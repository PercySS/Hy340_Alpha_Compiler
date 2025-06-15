#include "../include/avm.hpp"

std::vector<double> numConsts;
std::vector<std::string> stringConsts;
std::vector<std::string> namedLibFuncs;
std::vector<userfunc> userFuncs;
std::vector<instruction> instructions;
std::vector<incomplete_jump> jumps;
unsigned currProcessedQuad = 0;
std::stack<unsigned> funcs;

avm_memcell stack[AVM_STACKSIZE];

avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned     top, topsp;

unsigned char executionFinished = 0;
unsigned pc = 0; // program counter
unsigned currline = 0; // current line in the source code
unsigned codeSize = 0; // size of the code segment
instruction* code = nullptr; // code segment
unsigned totalActuals = 0; // total number of actual parameters in the current function



void avm_initstack(void) {
    for (unsigned i = 0; i < AVM_STACKSIZE; ++i) {
        AVM_WIPEOUT(stack[i]);
        stack[i].type = undef_m;
    }
}

void avm_tableincrefcounter(avm_table* t) {
    ++t->refCounter;
}

void avm_tabledecrefcounter(avm_table* t) {
    assert(t->refCounter > 0);
    if (--t->refCounter)
        avm_tabledestroy(t);
}

void avm_tablebucketsinit(avm_table_bucket** p) {
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE; ++i)
        p[i] = (avm_table_bucket*)0;
}

avm_table* avm_tablenew(void) {
    avm_table* t = (avm_table*)malloc(sizeof(avm_table));
    AVM_WIPEOUT(*t);
    t->refCounter = 0;
    t->total      = 0;
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->strIndexed);
    return t;
}

void avm_memcellclear(avm_memcell* m);

void avm_tablebucketsdestroy(avm_table_bucket** p) {
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE; ++i) {
        avm_table_bucket* b = p[i];
        while (b) {
            avm_table_bucket* del = b;
            b = b->next;
            avm_memcellclear(del->key);
            avm_memcellclear(del->value);
            free(del);
        }
        p[i] = nullptr;
    }
}

void avm_tabledestroy(avm_table* t) {
    avm_tablebucketsdestroy(t->strIndexed);
    avm_tablebucketsdestroy(t->numIndexed);
    free(t);
}


avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg) {
    std::cout << "[translate_operand] vmarg type = " << arg->type << "\n";
    switch (arg->type) {
        case global_a:  return &stack[AVM_STACKENV_SIZE - 1 - arg->val];
        case local_a:   return &stack[topsp - arg->val];
        case formal_a:  return &stack[topsp + AVM_STACKENV_SIZE + 1 + arg->val];
        case retval_a:  return &retval;

        case number_a:  
            reg->type = number_m; 
            reg->data.numVal = consts_getnumber(arg->val);
            return reg;
        case string_a:
            reg->type = string_m; 
            reg->data.strVal = strdup(consts_getstring(arg->val).c_str());
            return reg;
        case bool_a:
            reg->type = bool_m; 
            reg->data.boolVal = (unsigned char)arg->val;
            return reg;
        
        case nil_a: reg->type = nil_m; return reg;

        case userfunc_a:
            reg->type = userfunc_m; 
            reg->data.funcVal =  userfuncs_getfunc(arg->val).address;
            return reg;

        case libfunc_a:
            reg->type = libfunc_m; 
            reg->data.libfuncVal = strdup(libfuncs_getused(arg->val).c_str());
            return reg;

        default:
            assert(0 && "Invalid vmarg type");
    }
}

double consts_getnumber(unsigned index) {
    return numConsts[index];
}

std::string consts_getstring(unsigned index) {
    return stringConsts[index];
}

userfunc userfuncs_getfunc(unsigned index) {
    return userFuncs[index];
}

std::string libfuncs_getused(unsigned index) {
    return namedLibFuncs[index];
}

typedef void (*execute_func_t)(instruction*);

execute_func_t executeFuncs[] = {
    execute_assign,
    execute_add,
    execute_sub,
    execute_mul,
    execute_div,
    execute_mod,
    execute_uminus,
    execute_and,
    execute_or,
    execute_not,
    execute_jeq,
    execute_jne,
    execute_jle,
    execute_jge,
    execute_jlt,
    execute_jgt,
    execute_jump,
    execute_call,
    execute_pusharg,
    execute_ret,  
    execute_getretval,
    execute_funcenter,
    execute_funcexit,
    execute_newtable,
    execute_tablegetelem,
    execute_tablesetelem,
    execute_nop
};

void execute_cycle() {
    if (executionFinished) {
        return;
    } else if (pc == codeSize) {
        executionFinished = 1;
        return;
    } else {
        assert(pc < codeSize && "Invalid program counter");
        instruction* instr = code + pc;
        assert(instr->opcode >= 0 && instr->opcode <= AVM_MAX_INSTRUCTIONS);

        if (instr->srcLine) {
            currline = instr->srcLine;
        }

        unsigned oldPC = pc;
        (*executeFuncs[instr->opcode])(instr);
        if (pc == oldPC) {
            pc++;
        }
    }
} 

typedef void (*memclear_func_t)(avm_memcell*);

void memclear_string(avm_memcell* m) {
    assert(m->data.strVal);
    free(m->data.strVal);
}

void memclear_table(avm_memcell* m) {
    assert(m->data.tableVal);
    avm_tabledestroy(m->data.tableVal);
}

memclear_func_t memclearfuncs[] = {
    0, // number_m
    memclear_string, // string_m
    0, // bool_m
    memclear_table, // table_m
    0, // userfunc_m
    0, // libfunc_m
    0, // nil_m
    0  // undef_m
};

void avm_memcellclear(avm_memcell* m) {
    if (m->type != undef_m) {
        memclear_func_t clearFunc = memclearfuncs[m->type];
        if (clearFunc) {
            (*clearFunc)(m);
        }
        m->type = undef_m;
    }
}


// executes
void execute_assign(instruction* instr) {
    avm_memcell* lv = avm_translate_operand(&instr->result, &ax);
    avm_memcell* rv = avm_translate_operand(&instr->arg1, &bx);

    assert(lv && (&stack[AVM_STACKSIZE - 1] > lv || lv >= stack));
    assert(rv && (&stack[AVM_STACKSIZE - 1] > rv || rv >= stack));

    avm_assign(lv, rv);
}

// avm_funcs
void avm_assign(avm_memcell* lv, avm_memcell* rv) {
    if (lv == rv) {
        return; // no need to assign if they are the same
    }

    if (lv->type == table_m && rv->type == table_m && lv->data.tableVal == rv->data.tableVal) {
        return; // no need to assign if they are the same table
    }

    avm_memcellclear(lv);

    memcpy(lv, rv, sizeof(avm_memcell));

    /* Now we take care of copied values or reference counting */
    if (lv->type == string_m) {
        lv->data.strVal = strdup(rv->data.strVal);
    } else if (lv->type == table_m) {
        avm_tableincrefcounter(rv->data.tableVal);
    }
}

void execute_call(instruction* instr) {
    avm_memcell* func = avm_translate_operand(&instr->result, &ax);
    assert(func);
    avm_callsaveenv();

    switch (func->type) {
        case userfunc_m:
            pc = func->data.funcVal;
            assert(pc < AVM_ENDING_PC);
            assert(code[pc].opcode == funcenter_v);
            break;
        case string_m:  
            avm_calllibfunc(func->data.strVal);
            break;
        case libfunc_m:
            avm_calllibfunc(func->data.libfuncVal);
            break;

        default:
            executionFinished = 1;
    }
}

void avm_dec_top() {
    if (!top) {
        avm_error("Stack overflow");
        executionFinished = 1;
    } else {
        --top;
    }
}

void avm_push_envvalue(unsigned val) {
    stack[top].type = number_m;
    stack[top].data.numVal = (double) val;
    avm_dec_top();
}

void avm_callsaveenv() {
    avm_push_envvalue(totalActuals);
    avm_push_envvalue(pc + 1);
    avm_push_envvalue(top + totalActuals + 2);
    avm_push_envvalue(topsp);
}


userfunc* avm_getfuncinfo(unsigned address) {
    assert(address < userFuncs.size());
    return &userFuncs[address];
}

void execute_funcenter(instruction* instr) {
    avm_memcell* func = avm_translate_operand(&instr->result, &ax);
    assert(func);
    assert(pc == func->data.funcVal);
    totalActuals = 0;
    userfunc* funcInfo = avm_getfuncinfo(pc);
    topsp = top;
    top = top - funcInfo->localSize;
}

unsigned avm_get_envvalue(unsigned i) {
    assert(stack[i].type == number_m);
    unsigned val = (unsigned) stack[i].data.numVal;
    assert(stack[i].data.numVal == (double) val);
    return val;
}   

void execute_funcexit(instruction* instr) {
    unsigned oldTop = top;
    top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
    pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
    topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

    while (++oldTop <= top) {
        avm_memcellclear(&stack[oldTop]);
    } 
}

typedef void (*library_func_t)(void);

library_func_t avm_getlibraryfunc(char* id) {
    for (unsigned i = 0; i < namedLibFuncs.size(); ++i) {
        if (namedLibFuncs[i] == id) {
            switch (i) {
                case 0: return libfunc_print;
                case 1: return libfunc_typeof;
            }
        }
    }
    return nullptr; // not found
}

void avm_calllibfunc(const char* funcName) {
    library_func_t func = avm_getlibraryfunc((char*)funcName);
    
    if (!func) {
        avm_error("Call: cannot bind %s to library function", funcName);
        executionFinished = 1;
    } else {
        topsp = top;
        totalActuals = 0;
        (*func)();
        if (!executionFinished) {
            execute_funcexit(nullptr);
        }
    } 
}

unsigned avm_totalactuals() {
    return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual(unsigned i) {
    assert(i < avm_totalactuals());
    return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

void libfunc_print(void) {
    unsigned n = avm_totalactuals();
    for (unsigned i = 0; i < n; ++i) {
        std::string s = avm_tostring(avm_getactual(i));
        puts(s.c_str());
    }
}


void avm_registerlibfunc(char* id, library_func_t addr) {
    for (unsigned i = 0; i < namedLibFuncs.size(); ++i) {
        if (namedLibFuncs[i] == id) {
            return;
        }
    }
    namedLibFuncs.push_back(id);    
}

void execute_pusharg(instruction* instr) {
    std::cout << "Executing pusharg for instruction: " << instr->srcLine << std::endl;
    avm_memcell* arg = avm_translate_operand(&instr->arg1, &ax);
    assert(arg);

    avm_assign(&stack[top], arg);
    ++totalActuals;
    avm_dec_top();
}


typedef char* (*tostring_func_t)(const avm_memcell*);

char* number_to_string(const avm_memcell* m) {
    char* buffer = (char*)malloc(32);
    snprintf(buffer, 32, "%g", m->data.numVal);
    return buffer;
}

char* string_to_string(const avm_memcell* m) {
    assert(m->data.strVal);
    char* buffer = (char*)malloc(strlen(m->data.strVal) + 1);
    strcpy(buffer, m->data.strVal);
    return buffer;
}

char* bool_to_string(const avm_memcell* m) {
    return m->data.boolVal ? strdup("true") : strdup("false");
}

char* table_to_string(const avm_memcell* m) {
    assert(m->data.tableVal);
    char* buffer = (char*)malloc(32);
    snprintf(buffer, 32, "table@%p", (void*)m->data.tableVal);
    return buffer;
}

char* userfunc_to_string(const avm_memcell* m) {
    assert(m->data.funcVal < userFuncs.size());
    userfunc* func = &userFuncs[m->data.funcVal];
    char* buffer = (char*)malloc(func->id.size() + 32);
    snprintf(buffer, func->id.size() + 32, "userfunc@%s:%d", func->id.c_str(), func->address);
    return buffer;
}

char* libfunc_to_string(const avm_memcell* m) {
    assert(m->data.libfuncVal);
    char* buffer = (char*)malloc(strlen(m->data.libfuncVal) + 1);
    strcpy(buffer, m->data.libfuncVal);
    return buffer;
}

char* nil_to_string(const avm_memcell* m) {
    return strdup("nil");
}

char* undef_to_string(const avm_memcell* m) {
    return strdup("undefined");
}

tostring_func_t tostringfuncs[] = {
    number_to_string, // number_m
    string_to_string, // string_m
    bool_to_string,   // bool_m
    table_to_string,  // table_m
    userfunc_to_string, // userfunc_m
    libfunc_to_string, // libfunc_m
    nil_to_string,     // nil_m
    undef_to_string    // undef_m
};

std::string avm_tostring(avm_memcell* m) {
    assert(m->type >= 0);
    return (*tostringfuncs[m->type])(m);
}

typedef double (*arithmetic_func_t)(double, double);

double add_func(double x, double y) {
    return x + y;
}

double sub_func(double x, double y) {
    return x - y;
}

double mul_func(double x, double y) {
    return x * y;
}

double div_func(double x, double y) {
    if (y == 0) {
        avm_error("Division by zero");
        executionFinished = 1;
        return 0; // or some error value
    }
    return x / y;
}

double mod_func(double x, double y) {
    if (y == 0) {
        avm_error("Modulo by zero");
        executionFinished = 1;
        return 0; // or some error value
    }
    return fmod((unsigned)x, (unsigned)y);
}

arithmetic_func_t arithmeticFuncs[] = {
    add_func, // execute_add
    sub_func, // execute_sub
    mul_func, // execute_mul
    div_func, // execute_div
    mod_func  // execute_mod
};


void execute_arithmetic(instruction* instr) {
    avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    assert(lv && (&stack[AVM_STACKSIZE - 1] >= lv || lv >= stack));
    assert(rv1 && rv2);

    if (rv1->type == undef_m || rv2->type == undef_m) {
        avm_error("Arithmetic operation: one of the operands is undefined");
        executionFinished = 1;
    } else {
        arithmetic_func_t op = arithmeticFuncs[instr->opcode - add_v];
        avm_memcellclear(lv);
        lv->type = number_m; // result is always a number
        lv->data.numVal = (*op)(rv1->data.numVal, rv2->data.numVal);
    }
}


typedef unsigned char (*tobool_func_t)(avm_memcell*);

unsigned char number_tobool(avm_memcell* m) {
    return m->data.numVal != 0;
}

unsigned char string_tobool(avm_memcell* m) {
    return m->data.strVal[0] != 0;
}

unsigned char bool_tobool(avm_memcell* m) {
    return m->data.boolVal;
}

unsigned char table_tobool(avm_memcell* m) {
    return 1;
}

unsigned char userfunc_tobool(avm_memcell* m) {
    return 1;
}

unsigned char libfunc_tobool(avm_memcell* m) {
    return 1;
}

unsigned char nil_tobool(avm_memcell* m) {
    return 0;
}

unsigned char undef_tobool(avm_memcell* m) {
    assert(0);
    return 0;
}

tobool_func_t toboolfuncs[] = {
    number_tobool, // number_m
    string_tobool, // string_m
    bool_tobool,   // bool_m
    table_tobool,  // table_m
    userfunc_tobool, // userfunc_m
    libfunc_tobool, // libfunc_m
    nil_tobool,     // nil_m
    undef_tobool    // undef_m
};

unsigned char avm_tobool(avm_memcell* m) {
    assert(m->type >= 0 && m->type < undef_m);
    return (*toboolfuncs[m->type])(m);
}

const char* typeStrings[] = {
    "number",   // number_m
    "string",   // string_m
    "bool",     // bool_m
    "table",    // table_m
    "userfunc", // userfunc_m
    "libfunc",  // libfunc_m
    "nil",      // nil_m
    "undef"     // undef_m
};

void execute_jeq(instruction* instr) {
    assert(instr->result.type == label_a);

    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    unsigned char result = 0;

    if (rv1->type == undef_m || rv2->type == undef_m) {
        avm_error("Comparison: one of the operands is undefined");
        executionFinished = 1;
    } else if (rv1->type == nil_m || rv2->type == nil_m) {
        result = (rv1->type == nil_m && rv2->type == nil_m);
    } else if (rv1->type == bool_m && rv2->type == bool_m) {
        result = (avm_tobool(rv1) == avm_tobool(rv2));
    } else if (rv1->type != rv2->type) {
        avm_error("%s == %s: cannot compare different types", typeStrings[rv1->type], typeStrings[rv2->type]);
        executionFinished = 1;
    } else {
        /* equality check with dispatching */
        switch (rv1->type) {
            case number_m: result = (rv1->data.numVal == rv2->data.numVal); break;
            case string_m: result = (strcmp(rv1->data.strVal, rv2->data.strVal) == 0); break;
            case table_m: result = (rv1->data.tableVal == rv2->data.tableVal); break;
            case userfunc_m: result = (rv1->data.funcVal == rv2->data.funcVal); break;
            case libfunc_m: result = (strcmp(rv1->data.libfuncVal, rv2->data.libfuncVal) == 0); break;
            default:
                avm_error("Comparison: unsupported type for equality check");
                executionFinished = 1;
        }
    }
        
    if (!executionFinished && result) {
        pc = instr->result.val; // jump to the label
    }
}

void execute_uminus(instruction* instr) {
    ;
}

void execute_and(instruction* instr) {
    ;
}

void execute_or(instruction* instr) {
    ;
}

void execute_not(instruction* instr) {
    ;
}

void execute_jne(instruction* instr) {
    ;
}

void execute_jle(instruction* instr) {
    ;
}

void execute_jge(instruction* instr) {
    ;
}

void execute_jlt(instruction* instr) {
    ;
}

void execute_jgt(instruction* instr) {
    ;
}

void execute_jump(instruction* instr) {
    assert(instr->result.type == label_a);
    if (instr->result.val >= codeSize) {
        avm_error("Jump: label %u is out of bounds", instr->result.val);
        executionFinished = 1;
    } else {
        pc = instr->result.val; // jump to the label
        currline = instr->srcLine; // update current line
        std::cout << "[execute_jump] Jumping to instruction at line " << currline << " with PC = " << pc << std::endl;
    }
}

void execute_ret(instruction* instr) {
    ;
}

void execute_getretval(instruction* instr) {
    ;
}

void execute_nop(instruction* instr) {
    ;
}

void libfunc_typeof(void) {
    unsigned n = avm_totalactuals();
    
    if (n != 1) {
        avm_error("TypeOf: expected 1 argument, got %u", n);
        executionFinished = 1;
        return;
    } else {
        avm_memcellclear(&retval);
        retval.type = string_m;
        retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
    }
}

void execute_newtable(instruction* instr) {
    avm_memcell* lv = avm_translate_operand(&instr->result, &ax);
    assert(lv && (&stack[AVM_STACKSIZE - 1] >= lv && lv >= stack));

    avm_memcellclear(lv);
    lv->type = table_m;
    lv->data.tableVal = avm_tablenew();
    avm_tableincrefcounter(lv->data.tableVal);
}

avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index) {
    assert(table && index);
    unsigned hash = 0;
    avm_table_bucket* bucket = nullptr;
    if (index->type == number_m) {
        hash = (unsigned)index->data.numVal % AVM_TABLE_HASHSIZE;
    } else if (index->type == string_m) {
        hash = std::hash<std::string>()(index->data.strVal) % AVM_TABLE_HASHSIZE;   
    } else {
        avm_error("TableGetElem: index type is not supported");
        executionFinished = 1;
        return nullptr;
    }
    return nullptr; // placeholder, actual implementation needed
}

void avm_tablesetelem(avm_table* table, avm_memcell* index, avm_memcell* value) {
    assert(table && index && value);
    unsigned hash = 0;
    avm_table_bucket* bucket = nullptr;
    if (index->type == number_m) {
        hash = (unsigned)index->data.numVal % AVM_TABLE_HASHSIZE;
    } else if (index->type == string_m) {
        hash = std::hash<std::string>()(index->data.strVal) % AVM_TABLE_HASHSIZE;
    } else {
        avm_error("TableSetElem: index type is not supported");
        executionFinished = 1;
        return;
    }
}

void execute_tablegetelem(instruction* instruction) {
    avm_memcell* lv = avm_translate_operand(&instruction->result, (avm_memcell*) 0);
    avm_memcell* t = avm_translate_operand(&instruction->arg1, (avm_memcell*) 0);
    avm_memcell* i = avm_translate_operand(&instruction->arg2, &ax);
   
    assert(lv && ((&stack[AVM_STACKSIZE - 1] >= lv && lv > &stack[top]) || lv == &retval));
    assert(t && (&stack[AVM_STACKSIZE - 1] >= t && t >= &stack[top]));
    assert(i);

    avm_memcellclear(lv);
    lv->type = nil_m;

    if (t->type != table_m) {
        avm_error("TableGetElem: first operand is not a table");
        executionFinished = 1;
    } else {
        avm_memcell* result = avm_tablegetelem(t->data.tableVal, i);
        if (result) {
            avm_assign(lv, result);
        } else {
        }
    }
}


void execute_tablesetelem(instruction* instruction) {
    avm_memcell* t = avm_translate_operand(&instruction->result, (avm_memcell*) 0);
    avm_memcell* i = avm_translate_operand(&instruction->arg1, &ax);
    avm_memcell* v = avm_translate_operand(&instruction->arg2, &bx);

    assert(t && (&stack[AVM_STACKSIZE - 1] >= t && t >= &stack[top]));
    assert(i && v);

    if (t->type != table_m) {
        avm_error("TableSetElem: first operand is not a table");
        executionFinished = 1;
    } else {
        avm_tablesetelem(t->data.tableVal, i, v);
    }
}



void avm_initialize() {
    avm_initstack();
    avm_registerlibfunc((char *)"print", libfunc_print);
    top      = AVM_STACKSIZE - 1;
    topsp    = AVM_STACKSIZE - 1;
}

void libfunc_totalargument() {
    unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
    avm_memcellclear(&retval);

    if (!p_topsp) {
        avm_error("TotalArgument: no function is currently executing");
        executionFinished = 1;
    } else {
        retval.type = number_m;
        retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
    }
}

void avm_error(const char* format, ...) {
    executionFinished = 1;
}

void readBinary(const char* fileName) {
    std::ifstream in(fileName, std::ios::binary);
    if (!in) {
        std::cerr << "Cannot open " << fileName << "\n";
        std::exit(1);
    }

    // 1) magic
    uint32_t mag;
    in.read(reinterpret_cast<char*>(&mag), sizeof(mag));
    if (mag != MAGIC_NUMBER) {
        std::cerr << "Invalid magic number\n";
        std::exit(1);
    }

    // 2) strings
    uint32_t sc;
    in.read(reinterpret_cast<char*>(&sc), sizeof(sc));
    stringConsts.clear();
    for (uint32_t i = 0; i < sc; ++i) {
        uint32_t len;
        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        char *buf = new char[len+1];
        in.read(buf, len+1);              // includes '\0'
        stringConsts.emplace_back(buf);
        delete[] buf;
    }

    // 3) numbers
    uint32_t nc;
    in.read(reinterpret_cast<char*>(&nc), sizeof(nc));
    numConsts.clear();
    for (uint32_t i = 0; i < nc; ++i) {
        double d;
        in.read(reinterpret_cast<char*>(&d), sizeof(d));
        numConsts.push_back(d);
    }

    // 4) userfuncs
    uint32_t uc;
    in.read(reinterpret_cast<char*>(&uc), sizeof(uc));
    userFuncs.clear();
    for (uint32_t i = 0; i < uc; ++i) {
        userfunc uf;
        in.read(reinterpret_cast<char*>(&uf.address),   sizeof(uf.address));
        in.read(reinterpret_cast<char*>(&uf.localSize), sizeof(uf.localSize));
        uint32_t idLen;
        in.read(reinterpret_cast<char*>(&idLen), sizeof(idLen));
        char *idbuf = new char[idLen+1];
        in.read(idbuf, idLen+1);
        uf.id = idbuf;
        delete[] idbuf;
        userFuncs.push_back(uf);
    }

    // 5) libfuncs
    uint32_t lc;
    in.read(reinterpret_cast<char*>(&lc), sizeof(lc));
    namedLibFuncs.clear();
    for (uint32_t i = 0; i < lc; ++i) {
        uint32_t len;
        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        char *buf = new char[len+1];
        in.read(buf, len+1);
        namedLibFuncs.emplace_back(buf);
        delete[] buf;
    }

    // 6) code
    uint32_t ic;
    in.read(reinterpret_cast<char*>(&ic), sizeof(ic));
    instructions.clear();
    instructions.resize(ic);
    for (uint32_t i = 0; i < ic; ++i) {
        uint8_t op, rt, a1t, a2t;
        uint32_t rv, a1v, a2v;

        in.read(reinterpret_cast<char*>(&op),  1);
        in.read(reinterpret_cast<char*>(&rt),  1);
        in.read(reinterpret_cast<char*>(&rv),  sizeof(rv));
        in.read(reinterpret_cast<char*>(&a1t), 1);
        in.read(reinterpret_cast<char*>(&a1v), sizeof(a1v));
        in.read(reinterpret_cast<char*>(&a2t), 1);
        in.read(reinterpret_cast<char*>(&a2v), sizeof(a2v));

        instructions[i].opcode  = static_cast<vmopcode>(op);
        instructions[i].result  = { static_cast<vmarg_t>(rt), static_cast<int>(rv) };
        instructions[i].arg1    = { static_cast<vmarg_t>(a1t), static_cast<int>(a1v) };
        instructions[i].arg2    = { static_cast<vmarg_t>(a2t), static_cast<int>(a2v) };
        instructions[i].srcLine = 0;  // not stored in binary
    }

    codeSize = ic;
    code     = instructions.data();
    pc       = 0;

    in.close();
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: avm <binary>\n");
        return 1;
    }

    // 1) load all your constants & instructions
    readBinary(argv[1]);
    std::cout << "Loaded " << codeSize << " instructions from " << argv[1] << "\n";
    
    // 2) set up the stack & builtin library functions
    avm_initialize();     
    std::cout << "AVM initialized with stack size " << AVM_STACKSIZE << "\n";
    
    // 3) run until the program signals it's finished
    executionFinished = 0;
    std::cout << "Starting execution...\n";
    while (!executionFinished) {
        execute_cycle();
    }
    std::cout << "Execution finished.\n";
    return 0;
}