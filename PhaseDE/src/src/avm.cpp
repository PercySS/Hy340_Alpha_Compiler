//=== avm.cpp ==============================================================

#include "avm.hpp"
#include <cassert>
#include <cstdlib>
#include <functional>  // for std::hash

// registers & VM state
avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned   top, topsp;

//–––– Memcell clear –––––––––––––––––––––––––––––––––––––––––––––––––––––––

void avm_memcellclear(avm_memcell* m) {
    switch(m->type) {
      case string_m:
        delete m->data.strVal;
        break;
      case table_m:
        avm_tabledecrefcounter(m->data.tableVal);
        break;
      default:
        break;
    }
    m->type = undef_m;
}

//–––– Table buckets init/destroy ––––––––––––––––––––––––––––––––––––––––––

static void avm_tablebucketsinit(avm_table_bucket** p) {
    for(unsigned i=0; i<AVM_TABLE_HASHSIZE; ++i) p[i] = nullptr;
}

static void avm_tablebucketsdestroy(avm_table_bucket** p) {
    for(unsigned i=0; i<AVM_TABLE_HASHSIZE; ++i) {
        auto b = p[i];
        while(b) {
            auto nxt = b->next;
            avm_memcellclear(b->key);
            delete b->key;
            avm_memcellclear(b->value);
            delete b->value;
            delete b;
            b = nxt;
        }
        p[i] = nullptr;
    }
}

//–––– Table lifecycle ––––––––––––––––––––––––––––––––––––––––––––––––––––––

avm_table* avm_tablenew(void) {
    avm_table* t = new avm_table();
    t->refCounter = 0;
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->strIndexed);
    t->total = 0;
    return t;
}

void avm_tabledestroy(avm_table* t) {
    avm_tablebucketsdestroy(t->numIndexed);
    avm_tablebucketsdestroy(t->strIndexed);
    delete t;
}

void avm_tableincrefcounter(avm_table* t) {
    ++t->refCounter;
}

void avm_tabledecrefcounter(avm_table* t) {
    assert(t->refCounter > 0);
    if(--t->refCounter == 0) avm_tabledestroy(t);
}

//–––– Helpers: hash & equality ––––––––––––––––––––––––––––––––––––––––––––

static unsigned string_hash(const std::string& s) {
    return std::hash<std::string>{}(s) % AVM_TABLE_HASHSIZE;
}
static unsigned number_hash(double d) {
    return static_cast<unsigned>(d) % AVM_TABLE_HASHSIZE;
}

static bool memcell_equal(avm_memcell* a, avm_memcell* b) {
    if(a->type != b->type) return false;
    switch(a->type) {
      case number_m: return a->data.numVal == b->data.numVal;
      case string_m: return *a->data.strVal == *b->data.strVal;
      case bool_m:   return a->data.boolVal == b->data.boolVal;
      default:       return a->data.tableVal == b->data.tableVal;
    }
}

static avm_table_bucket** choose_bucket_list(avm_table* t, avm_memcell* key) {
    if(key->type == string_m)
        return &t->strIndexed[string_hash(*key->data.strVal)];
    else if(key->type == number_m)
        return &t->numIndexed[number_hash(key->data.numVal)];
    else
        assert(false && "Unsupported key type");
    return nullptr;
}

//–––– Table get/set ––––––––––––––––––––––––––––––––––––––––––––––––––––––––

avm_memcell* avm_tablegetelem(avm_table* t, avm_memcell* key) {
    auto head = *choose_bucket_list(t, key);
    for(auto b = head; b; b = b->next)
        if(memcell_equal(b->key, key))
            return b->value;
    static avm_memcell nil_cell{ nil_m, {.numVal=0} };
    return &nil_cell;
}

void avm_tablesetelem(avm_table* t, avm_memcell* key, avm_memcell* value) {
    auto bucket_ptr = choose_bucket_list(t, key);
    for(auto b = *bucket_ptr; b; b = b->next) {
        if(memcell_equal(b->key, key)) {
            avm_memcellclear(b->value);
            b->value = new avm_memcell(*value);
            return;
        }
    }
    // insert new
    auto nb = new avm_table_bucket();
    nb->key   = new avm_memcell(*key);
    nb->value = new avm_memcell(*value);
    nb->next  = *bucket_ptr;
    *bucket_ptr = nb;
    ++t->total;
}

//––––– VM state –
unsigned char executionFinished = 0;
unsigned       pc                = 0;
unsigned       currLine          = 0;
unsigned       codeSize          = 0;
instruction*   code              = nullptr;
#define AVM_ENDING_PC codeSize

//––– dispatch table –––––––––––––––––––––––––––––––––––––––––––––––––––––––
execute_func_t executeFuncs[] = {
    execute_assign,      // assign_v       = 0
    execute_add,         // add_v           1
    execute_sub,         // sub_v           2
    execute_mul,         // mul_v           3
    execute_div,         // div_v           4
    execute_mod,         // mod_v           5
    execute_jeq,         // jeq_v          10
    execute_jne,         // jne_v          11
    execute_jle,         // jle_v          12
    execute_jge,         // jge_v          13
    execute_jlt,         // jlt_v          14
    execute_jgt,         // jgt_v          15
    execute_jump,        // jump_v         16
    execute_call,        // call_v         17
    execute_pusharg,     // pusharg_v      18
    execute_funcenter,   // funcenter_v    19
    execute_funcexit,    // funcexit_v     20
    execute_newtable,    // newtable_v     21
    execute_tablegetelem,// tablegetelem_v 22
    execute_tablesetelem,// tablesetelem_v 23
    execute_getretval,   // getretval_v    24
    execute_nop          // nop_v          25
};

//––– the VM “tick” –––––––––––––––––––––––––––––––––––––––––––––––––––––––––
void execute_cycle(void) {
    if (executionFinished) return;

    if (pc == AVM_ENDING_PC) {
        executionFinished = 1;
        return;
    }

    assert(pc < AVM_ENDING_PC);
    instruction* instr = code + pc;
    assert(instr->opcode <= AVM_MAX_INSTRUCTIONS);

    if (instr->srcLine)
        currLine = instr->srcLine;

    unsigned oldPC = pc;
    // dispatch
    (*executeFuncs[instr->opcode])(instr);

    // advance if the handler didn’t change pc
    if (pc == oldPC)
        ++pc;
}
