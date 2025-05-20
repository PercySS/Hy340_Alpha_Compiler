// src/quad.cpp
#include "../include/quad.hpp"
#include "../include/expr.hpp"
#include "../include/symtable.hpp"
#include "../include/types.hpp"
#include "../include/temp.hpp"
#include <iostream>
#include <string>
#include <sstream>

extern int yylineno;
extern FILE* yyout;
extern SymbolTable symTable;

static unsigned temp_counter;
std::vector<quad *> quads;
static unsigned quad_counter;

void init_quads() {
    quads = std::vector<quad *>(0);
    quads.reserve(10000);
    quad_counter = 0;
    temp_counter = 0;
}

void emit(iopcode op, expr* arg1, expr* arg2, expr* result, unsigned label) {
    quad *q = new quad();
    q->op     = op;
    q->arg1   = arg1;
    q->arg2   = arg2;
    q->result = result;
    q->label  = label;
    q->line   = yylineno;
    quads.push_back(q);
    quad_counter++;
}

unsigned nextquad() {
    return quad_counter;
}

void patchlabel(unsigned quadNo, unsigned label) {
    assert(quadNo < quad_counter);
    quads[quadNo]->label = label;
}

static std::string exprToString(expr* e) {
    if (!e) return "_";

    switch (e->type) {
      case var_e:
      case tableitem_e:
      case programfunc_e:
      case libraryfunc_e:
      case arithexpr_e:
      case boolexpr_e:
      case assignexpr_e:
        return e->sym ? e->sym->name : "_";

      case constnum_e:
        return std::to_string(e->numConst);

      case constbool_e:
        return e->boolConst ? "true" : "false";

      case conststring_e:
        return "\"" + std::string(e->strConst) + "\"";

      case nil_e:
        return "nil";

      case newtable_e:
        return e->sym ? e->sym->name : "_";

      default:
        return "_";
    }
}


const char* iopcodeToString(iopcode op) {
    static const char* names[] = {
        "assign","add","sub","mul","div","mod",
        "uminus","and","or","not",
        "if_eq","if_noteq","if_lesseq","if_greatereq","if_less","if_greater",
        "jump","call","param","ret",
        "getretval","funcstart","funcend",
        "tablecreate","tablegetelem","tablesetelem"
    };
    return names[op];
}

void print_quads(FILE* out) {
    fprintf(out, "\n===================== QUADS =====================\n");
    fprintf(out, "%-6s | %-12s | %-20s | %-20s | %-20s | %-6s\n",
            "Quad#","Opcode","Result","Arg1","Arg2","Label");
    fprintf(out, "------------------------------------------------");
    fprintf(out, "-----------------------------\n");
    
    for (int i = 0; i < (int) quads.size(); i++) {
        quad *q = quads[i];
        fprintf(out, "%-6u | %-12s | %-20s | %-20s | %-20s | ",
                i+1,
                iopcodeToString(q->op),
                exprToString(q->result).c_str(),
                exprToString(q->arg1).c_str(),
                exprToString(q->arg2).c_str());

        if (q->label > 0) fprintf(out, "%-6u", q->label);
        else               fprintf(out, "%-6s", "-");
        fprintf(out, "\n");
    }
    fprintf(out, "=================== END QUADS ==================\n\n");
}

// emits
expr* emit_arith(iopcode op, expr* arg1, expr* arg2, expr* result) {
    if (!check_arith(arg1, "first operand") ||
        !check_arith(arg2, "second operand")) {
        exit(1);
    }
    if ((op == div_op || op == mod) &&
        (arg2->type == constnum_e && arg2->numConst == 0)) {
        comperror("Division by zero", "division/modulus");
        exit(1);
    }
    result     = newexpr(arithexpr_e);
    result->sym = newtemp();
    
    emit(op, arg1, arg2, result, 0);
    return result;
}

expr* emit_eq(iopcode op, expr* arg1, expr* arg2, expr* result) {
    bool same_non_nil =
        arg1->type == arg2->type 
     && arg1->type != nil_e;
    bool table_nil_pair =
       (arg1->type == newtable_e && arg2->type == nil_e)
    || (arg1->type == nil_e      && arg2->type == newtable_e);

    if (!same_non_nil && !table_nil_pair) {
        fprintf(yyout,
          "      [!] Error: Cannot compare %s and %s in line %d.\n",
          exprToString(arg1).c_str(),
          exprToString(arg2).c_str(),
          yylineno);
        exit(1);
    }

    result       = newexpr(boolexpr_e);
    result->sym  = newtemp();


    if (table_nil_pair) {
        // table == nil → always false; table != nil → always true
        expr* c = newexpr_constbool(op == if_noteq);
        emit(assign, c, nullptr, result, nextquad());
        return result;
    }

    emit(op, arg1, arg2, result, nextquad() + 3);
    emit(assign, newexpr_constbool(false), nullptr, result, 0);
    emit(jump,   nullptr, nullptr, nullptr, nextquad() + 2);
    emit(assign, newexpr_constbool(true), nullptr, result, 0);

    return result;
}



expr* emit_relop(iopcode op, expr* arg1, expr* arg2, expr* result) {
    if (op == if_eq || op == if_noteq) {
        return emit_eq(op, arg1, arg2, result);
    }
    if (!check_arith(arg1, "first operand") ||
        !check_arith(arg2, "second operand")) {
        exit(1);
    }
    result     = newexpr(boolexpr_e);
    if      (op == if_less)      result->boolConst = arg1->numConst <   arg2->numConst;
    else if (op == if_greater)   result->boolConst = arg1->numConst >   arg2->numConst;
    else if (op == if_lesseq)    result->boolConst = arg1->numConst <=  arg2->numConst;
    else if (op == if_greatereq) result->boolConst = arg1->numConst >=  arg2->numConst;
    result->sym = newtemp();
    emit(op, arg1, arg2, result, nextquad() + 3);
    emit(assign, newexpr_constbool(false), nullptr, result, 0);
    emit(jump,   nullptr, nullptr, nullptr, nextquad() + 2);
    emit(assign, newexpr_constbool(true), nullptr, result, 0);
    return result;
}

expr* emit_bool(iopcode op, expr* arg1, expr* arg2, expr* result) {
    return emit_relop(op, arg1, arg2, result);
}
