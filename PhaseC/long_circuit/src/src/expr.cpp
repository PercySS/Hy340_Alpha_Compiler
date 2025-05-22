// src/expr.cpp
#include "../include/expr.hpp"
#include "../include/temp.hpp"
#include "../include/quad.hpp"
#include <cstdlib>
#include <cassert>

expr* newexpr(expr_t type) {
    auto* e = new expr(type);
    e->sym   = nullptr;
    e->index = nullptr;
    e->numConst = 0;
    e->boolConst = false;
    e->next  = nullptr;
    return e;
}


expr* newexpr_tmpvar(expr_t type) {
    expr* e = newexpr(type);
    e->sym  = newtemp();
    return e;
}

expr* newexpr_constnum(double val) {
    expr* e = newexpr(constnum_e);
    e->numConst = val;
    return e;
}

expr* newexpr_constbool(bool b) {
    expr* e = newexpr(constbool_e);
    e->boolConst = b;
    return e;
}

expr* newexpr_conststring(const std::string& str) {
    expr* e = newexpr(conststring_e);
    e->strConst = str;
    return e;
}

expr* lvalue_expr(SymEntry* sym) {
    assert(sym);
    expr* e = nullptr;
    switch (sym->type) {
      case VAR:
      case FORARG:
        e = new expr(var_e);
        break;
      case FUNC:
        e = new expr(programfunc_e);
        break;
      case LIBFUNC:
        e = new expr(libraryfunc_e);
        break;
      default:
        assert(false);
    }
    e->sym = sym;
    return e;
}


expr* member_item(expr* lvalue, std::string name) {
    lvalue = emit_iftableitem(lvalue);
    expr* e = newexpr(tableitem_e);
    e->sym   = lvalue->sym;
    e->index = newexpr_conststring(name);
    return e;
}

expr* emit_iftableitem(expr* e) {
    if (e->type != tableitem_e) {
        return e;
    } else {
        expr* result = newexpr(var_e);
        result->sym  = newtemp();
        emit(tablegetelem, e, e->index, result, 0);
        return result;
    }
}

expr* reverse(expr* head) {
  expr* prev = nullptr;
  while (head) {
    expr* nxt = head->next;
    head->next = prev;
    prev = head;
    head = nxt;
  }
  return prev;
}

expr* make_call(expr* lv, expr* reversed_list) {
    expr* func = emit_iftableitem(lv);
    while (reversed_list) {
        emit(param, reversed_list, nullptr, nullptr, 0);
        reversed_list = reversed_list->next;
    }
    emit(call, func, nullptr, nullptr, 0);

    expr* result = newexpr(var_e);
    result->sym  = newtemp();

    emit(getretval, nullptr, nullptr, result, 0);
    return result;
}

bool check_arith(expr* e, std::string context) {
    if (e->type == programfunc_e ||
        e->type == libraryfunc_e ||
        e->type == boolexpr_e    ||
        e->type == newtable_e    ||
        e->type == constbool_e   ||
        e->type == conststring_e ||
        e->type == nil_e) {
        comperror("Arithmetic operation on %s", context.c_str());
        return false;
    }
    return true;
}

bool check_constexpr(expr* e) {
    if (e->type == constnum_e ||
        e->type == constbool_e ||
        e->type == conststring_e) {
        return true;
    }
    return false;
}

void comperror(const char* msg, const char* context) {
    extern FILE* yyout;
    extern int   yylineno;
    fprintf(yyout, "      [!] Error: ");
    fprintf(yyout, msg, context);
    fprintf(yyout, " in line %d.\n", yylineno);
}

unsigned int istempname(const std::string& name) {
    return !name.empty() && name[0] == '_';
}

unsigned int istempexpr(expr* e) {
    return istempname(e->sym->name);
}

expr* convert_to_bool(expr* e) {
    if (e->type == constbool_e) {
        return e;
    } else if (e->type == constnum_e) {
        return newexpr_constbool(e->numConst != 0);
    } else if (e->type == conststring_e) {
        return newexpr_constbool(e->strConst != "");
    } else if (e->type == nil_e) {
        return newexpr_constbool(false);
    } else if (e->type == newtable_e) {
        return newexpr_constbool(true);
    } else if (e->type == programfunc_e || e->type == libraryfunc_e) {
        return newexpr_constbool(true);
    } else {
        return e;
    }
}
