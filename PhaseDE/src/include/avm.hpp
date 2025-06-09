//=== avm.hpp ================================================================
#ifndef AVM_HPP
#define AVM_HPP

#include <cstdint>
#include <string>
#include <cassert>
#include "target.hpp"

#define AVM_TABLE_HASHSIZE 211
#define AVM_STACKENV_SIZE 4

//––– Memory‐cell types –––––––––––––––––––––––––––––––––––––––––––––––––––––

enum avm_memcell_t {
    number_m, string_m, bool_m, table_m,
    userfunc_m, libfunc_m, nil_m, undef_m
};

/* Forward declare */
struct avm_table;

/* A generic VM “cell” holding a value */
struct avm_memcell {
    avm_memcell_t type;
    union {
        double       numVal;
        std::string* strVal;
        bool         boolVal;
        avm_table*   tableVal;
        unsigned     funcVal;
        unsigned     libfuncVal;
    } data;
};

//––– Hash‐table for “table_m” –––––––––––––––––––––––––––––––––––––––––––––

struct avm_table_bucket {
    avm_memcell*          key;
    avm_memcell*          value;
    avm_table_bucket*     next;
};

struct avm_table {
    unsigned              refCounter;
    avm_table_bucket*     numIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket*     strIndexed[AVM_TABLE_HASHSIZE];
    unsigned              total;
};

//––– Public AVM API –––––––––––––––––––––––––––––––––––––––––––––––––––––––

/* Clear any dynamic contents of a memcell (string/table) and reset to undef */
void         avm_memcellclear(avm_memcell* m);

/* Create/destroy a table; simple ref‐count GC on tables */
avm_table*   avm_tablenew(void);
void         avm_tabledestroy(avm_table* t);
void         avm_tableincrefcounter(avm_table* t);
void         avm_tabledecrefcounter(avm_table* t);

/* Lookup or set an element in a table (numeric or string key only) */
avm_memcell* avm_tablegetelem(avm_table* t, avm_memcell* key);
void         avm_tablesetelem(avm_table* t, avm_memcell* key, avm_memcell* value);


// reverse‐lookup for constants
double consts_getnumber   (unsigned index);
char*  consts_getstring   (unsigned index);
char*  libfuncs_getused   (unsigned index);

//––– execution dispatch table and cycle ––––––––––––––––––––––––––––––––––––

typedef void (*execute_func_t)(instruction*);

#define AVM_MAX_INSTRUCTIONS  (unsigned) nop_v

extern execute_func_t executeFuncs[];

extern void execute_assign      (instruction*);
extern void execute_add         (instruction*);
extern void execute_sub         (instruction*);
extern void execute_mul         (instruction*);
extern void execute_div         (instruction*);
extern void execute_mod         (instruction*);

extern void execute_jeq         (instruction*);
extern void execute_jne         (instruction*);
extern void execute_jle         (instruction*);
extern void execute_jge         (instruction*);
extern void execute_jlt         (instruction*);
extern void execute_jgt         (instruction*);
extern void execute_jump        (instruction*);

extern void execute_call        (instruction*);
extern void execute_pusharg     (instruction*);
extern void execute_funcenter   (instruction*);
extern void execute_funcexit    (instruction*);
extern void execute_newtable    (instruction*);
extern void execute_tablegetelem(instruction*);
extern void execute_tablesetelem(instruction*);
extern void execute_getretval   (instruction*);
extern void execute_nop         (instruction*);

extern void execute_cycle(void);


#endif // AVM_HPP
