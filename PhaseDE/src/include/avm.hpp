#ifndef _AVM_HPP
#define _AVM_HPP

#include "target.hpp"
#include <cstring>
#include <cmath>
#include <cassert>

#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))
#define AVM_TABLE_HASHSIZE 211
#define AVM_STACKENV_SIZE 4
#define AVM_ENDING_PC codeSize
#define AVM_NUMACTUALS_OFFSET 4
#define AVM_SAVEDPC_OFFSET 3
#define AVM_SAVEDTOP_OFFSET 2
#define AVM_SAVEDTOPSP_OFFSET 1

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic


enum avm_memcell_t {
    number_m   = 0,
    string_m   = 1,
    bool_m     = 2,
    table_m    = 3,
    userfunc_m = 4,
    libfunc_m  = 5,
    nil_m      = 6,
    undef_m    = 7
};

struct avm_table;
struct avm_memcell {
    avm_memcell_t  type;
    union {
        double        numVal;
        char*         strVal;
        unsigned char boolVal;
        avm_table*    tableVal;
        unsigned      funcVal;
        char*         libfuncVal;
    } data;
};

extern avm_memcell stack[AVM_STACKSIZE];

void avm_initstack(void);

struct avm_table_bucket {
    avm_memcell*       key;
    avm_memcell*       value;
    avm_table_bucket*  next;
};

struct avm_table {
    unsigned             refCounter;
    avm_table_bucket*    strIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket*    numIndexed[AVM_TABLE_HASHSIZE];
    unsigned             total;
};

avm_table*   avm_tablenew(void);
avm_memcell* avm_tablegetelem(avm_table* t, avm_memcell* key);
void         avm_tablesetelem(avm_table* t, avm_memcell* key, avm_memcell* value);
void         avm_tableincrefcounter(avm_table* t);
void         avm_tabledecrefcounter(avm_table* t);
void         avm_tablebucketsinit(avm_table_bucket** p);
void         avm_tablebucketsdestroy(avm_table_bucket** p);
void         avm_tabledestroy(avm_table* t);
void         avm_memcellclear(avm_memcell& m);
avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg);

double consts_getnumber(unsigned index);
std::string  consts_getstring(unsigned index);
std::string  libfuncs_getused(unsigned index);
userfunc userfuncs_getfunc(unsigned index);


#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v

void execute_assign(instruction*);
void execute_add(instruction*);
void execute_sub(instruction*);
void execute_mul(instruction*);
void execute_div(instruction*);
void execute_mod(instruction*);

void execute_uminus(instruction*);
void execute_and(instruction*);
void execute_or(instruction*);
void execute_not(instruction*);


void execute_jeq(instruction*);
void execute_jne(instruction*);
void execute_jle(instruction*);
void execute_jge(instruction*);
void execute_jlt(instruction*);
void execute_jgt(instruction*);

void execute_call(instruction*);
void execute_pusharg(instruction*);
void execute_funcenter(instruction*);
void execute_funcexit(instruction*);

void execute_newtable(instruction*);
void execute_tablegetelem(instruction*);
void execute_tablesetelem(instruction*);

void execute_jump(instruction*);
void execute_ret(instruction*);
void execute_nop(instruction*);
void execute_getretval(instruction*);

void execute_cycle();

void avm_warning(const char* format, ...);
void avm_assign(avm_memcell* lv, avm_memcell* rv);

void avm_error(const char* format, ...);
std::string avm_tostring(avm_memcell* m);
void avm_calllibfunc(const char* funcName);
void avm_callsaveenv(void);

userfunc* avm_getfuncinfo(unsigned address);

void avm_dec_top();
void avm_push_envvalue(unsigned val);
void readBinary(const char* fileName);

char* avm_to_string(const avm_memcell* m);

void libfunc_print(void);
void libfunc_typeof(void);





#endif // _AVM_HPP