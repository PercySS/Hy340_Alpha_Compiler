#ifndef _TARGET_HPP
#define _TARGET_HPP


#include "backpatch.hpp"
#include "expr.hpp"
#include "quad.hpp"
#include "stmt.hpp"
#include "symTable.hpp"
#include "temp.hpp"
#include "types.hpp"
#include <iomanip>
#include <iostream>
#include <cstdint>
#include <fstream>


enum vmopcode {
    assign_v, add_v, sub_v, mul_v, div_v, mod_v,
    uminus_v, and_v, or_v, not_v,
    jeq_v, jne_v, jle_v, jge_v, jlt_v, jgt_v,
    jump_v, call_v, pusharg_v, ret_v, getretval_v,
    funcenter_v, funcexit_v,
    newtable_v, tablegetelem_v, tablesetelem_v, nop_v
};

enum vmarg_t {
    label_a    = 0,
    global_a   = 1,
    formal_a   = 2,
    local_a    = 3,
    number_a   = 4,
    string_a   = 5,
    bool_a     = 6,
    nil_a      = 7,
    userfunc_a = 8,
    libfunc_a  = 9,
    retval_a   = 10
};

struct vmarg {
    vmarg_t type;
    int val;
};

struct instruction {
    vmopcode opcode;
    vmarg result;
    vmarg arg1;
    vmarg arg2;
    int srcLine;
};

struct userfunc {
    int address;
    int localSize;
    std::string id;
};

struct incomplete_jump {
    int instr;
    int iaddress;
};

void add_incomplete_jump(unsigned instr, unsigned iaddress);
void patch_incomplete_jumps();
unsigned consts_newstring(std::string s);
unsigned consts_newnum(double n);
unsigned libfuncs_newused(std::string s);
unsigned userfuncs_newfunc(SymEntry* u);
void make_operand(expr* e, vmarg* arg);
void make_numberoperand(vmarg* arg, double n);
void make_booloperand(vmarg* arg, std::string s);
void make_retvaloperand(vmarg* arg);

void emit(instruction t);
unsigned nextinstructionlabel();
void generate(vmopcode op, quad* quad);
void reset_operand(vmarg* arg);

// generating instructions
void generate_add(quad* quad);
void generate_sub(quad* quad);
void generate_mul(quad* quad);
void generate_div(quad* quad);
void generate_mod(quad* quad);
void generate_newtable(quad* quad);
void generate_getelem(quad* quad);
void generate_setelem(quad* quad);
void generate_assign(quad* quad);
void generate_nop();
void generate_uminus(quad* quad);

void generate_relational(vmopcode op, quad* quad);
void generate_jump(quad* quad);
void generate_ifeq(quad* quad);
void generate_ifne(quad* quad);
void generate_ifle(quad* quad);
void generate_ifge(quad* quad);
void generate_iflt(quad* quad);
void generate_ifgt(quad* quad);

void generate_not(quad* quad);
void generate_or(quad* quad);
void generate_and(quad* quad);

void generate_param(quad* quad);
void generate_call(quad* quad);
void generate_getretval(quad* quad);
void generate_funcstart(quad* quad);
void generate_funcend(quad* quad);
void generate_return(quad* quad);
void generate_and_print_instructions();
void write_binary(const std::string& filename);


#endif // _TARGET_HPP