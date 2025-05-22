// expr.hpp
#ifndef EXPR_HPP
#define EXPR_HPP

#include "types.hpp"
#include "symtable.hpp"
#include <string>
#include <vector>
#include <cassert>

// the core IR expression node
struct expr {
    expr_t type;
    SymEntry* sym;
    expr*     index;
    double    numConst     = 0;
    std::string strConst;
    bool      boolConst    = false;
    expr*     next         = nullptr;
    std::vector<unsigned int> truelist;
    std::vector<unsigned int> falselist;

    expr(expr_t t)
      : type(t), sym(nullptr), index(nullptr), numConst(0),
        strConst(), boolConst(false), next(nullptr) { }
};

// constructors & helpers
expr* lvalue_expr(SymEntry* sym);
expr* newexpr(expr_t type);
expr* newexpr_tmpvar(expr_t type);
expr* newexpr_constnum(double val);
expr* newexpr_constbool(bool val);
expr* newexpr_conststring(const std::string& str);
expr* make_call(expr* e, expr* arglist);
expr* member_item(expr* e, std::string name);
expr* reverse(expr* head);

// semantic & bool conversion
bool        check_arith(expr* e, std::string context);
bool check_constexpr(expr* e);
void        comperror(const char* msg, const char* context);
void        release_temp(expr* e);

// helpers
unsigned    istempname(const std::string& name);
unsigned    istempexpr(expr* e);

#endif // EXPR_HPP
