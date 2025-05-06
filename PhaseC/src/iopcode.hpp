#ifndef __ICODE_HPP__
#define __ICODE_HPP__

#include "symtable.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// ----------- expression types -------------
enum expr_t {
    var_e, 
    tableitem_e, 
    
    programfunc_e,
    libraryfunc_e,
    
    arithexpr_e, 
    boolexpr_e, 
    assignexpr_e, 
    newtable_e,
    
    constnum_e, 
    constbool_e, 
    conststring_e, 
    nil_e
};

// ----------- i-code instructions ------------
enum iopcode {
    assign,         add,            sub, 
    mul,            div_op,         mod,
    uminus,         and_op,         or_op, 
    not_op,         if_eq,          if_noteq, 
    if_lesseq,      if_greatereq,   if_less, 
    if_greater,     jump,
    call,           param,          ret,
    getretval,      funcstart,      funcend,
    tablecreate,    tablegetelem,   tablesetelem
};

// ----------- expr node --------------
struct expr {
    expr_t type;
    SymEntry* sym = nullptr;
    expr* index = nullptr;
    double numConst = 0;
    std::string strConst;
    bool boolConst = false;
    expr* next = nullptr;

    std::vector<unsigned> truelist;
    std::vector<unsigned> falselist;

    expr(expr_t t) : type(t) {}
};

// ----------- quad node -------------------
struct quad {
    iopcode op;
    expr* result;
    expr* arg1;
    expr* arg2;
    unsigned label = 0;
    unsigned line = 0;
};

// ----------- global storage for quads -----------------------
extern std::vector<quad> quads;

// ----------- helper functions -------------------------
void emit(iopcode op, expr* arg1, expr* arg2, expr* result);
unsigned nextquad();
expr* lvalue_expr(expr* e);
expr* newexpr_tmpvar(expr_t type);
expr* newexpr(expr_t type);
expr* newexpr_constnum(double val);
expr* newexpr_constbool(bool val);
expr* newexpr_conststring(const std::string& str);
SymEntry* newtemp();
std::string newtempname();
void resettemp();
expr* emit_iftableitem(expr* e);
void make_call(expr* e, expr* arglist);

// ----------- SHORT CIRCUIT --------------
void backpatch(const std::vector<unsigned>& list, unsigned label);
std::vector<unsigned> makelist(unsigned quadLabel);
std::vector<unsigned> merge(const std::vector<unsigned>& list1, const std::vector<unsigned>& list2);


// ----------------- printing functions ------------------
void print_quads(FILE* output);
#endif // __ICODE_HPP__