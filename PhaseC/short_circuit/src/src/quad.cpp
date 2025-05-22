// src/quad.cpp
#include "../include/quad.hpp"
#include "../include/expr.hpp"
#include "../include/symtable.hpp"
#include "../include/types.hpp"
#include "../include/temp.hpp"
#include "../include/backpatch.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

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

void emit(iopcode op, expr* arg1, expr* arg2, expr* result, int label) {
    quad *q = new quad();
    q->op     = op;
    q->arg1   = arg1;
    q->arg2   = arg2;
    q->result = result;
    q->label  = label;
    q->line   = yylineno;
    quads.push_back(q);
    ++quad_counter;
}

unsigned nextquad() {
    return quad_counter;
}

void patchlabel(unsigned quadNo, unsigned label) {
    assert(quadNo < quad_counter);
    quads[quadNo]->label = label;
}

std::string double_to_string(double d) {
    if (d == floor(d)) {
        return std::to_string((int)d);
    }
    return std::to_string(d);
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
        return double_to_string(e->numConst);

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

bool has_jump(iopcode op) {
    return op == jump || op == if_eq || op == if_noteq ||
           op == if_lesseq || op == if_greatereq ||
           op == if_less || op == if_greater;
}

void optimize_jumps() {
    std::stack<unsigned int> jumpStack = std::stack<unsigned int>();
    unsigned int lastJump = 0;
    fprintf(stdout, "Optimizing jumps...\n");
    for (unsigned i = 0; i < quads.size(); i++) {
        quad* q = quads[i];
        if (q->op != jump)  continue;
        while (q->op == jump) {
            if (q->label >= quads.size()) {
                lastJump = q->label;
                break;
            }
            jumpStack.push(i);
            lastJump = q->label;
            q = quads[q->label];
        }

        while (!jumpStack.empty()) {
            quads[jumpStack.top()]->label = lastJump;
            jumpStack.pop();
        }
    }
}

void print_quads(FILE* out) {
    /* optimize_jumps(); */
    fprintf(out, "\n============================================== QUADS =============================================\n");
    fprintf(out, "%-6s | %-12s | %-20s | %-20s | %-20s | %-6s\n",
            "Quad#","Opcode","Result","Arg1","Arg2","Label");
    fprintf(out, "------------------------------------------------");
    fprintf(out, "--------------------------------------------------\n");
    
    for (int i = 0; i < (int) quads.size(); i++) {
        quad *q = quads[i];
        fprintf(out, "%-6u | %-12s | %-20s | %-20s | %-20s | ",
                i + 1,
                iopcodeToString(q->op),
                exprToString(q->result).c_str(),
                exprToString(q->arg1).c_str(),
                exprToString(q->arg2).c_str());
        has_jump(q->op) ?
            fprintf(out, "%-6u", q->label + 1) :
            fprintf(out, "%-6s", " ");
        fprintf(out, "  {line %d}", q->line);
        fprintf(out, "\n");

    }
    fprintf(out, "============================================ END QUADS ===========================================\n\n");
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

    result = newexpr(arithexpr_e);

    if (!check_constexpr(arg1) && istempexpr(arg1)) {
        result->sym = arg1->sym;
    } else if (!check_constexpr(arg2) && istempexpr(arg2)) {
        result->sym = arg2->sym;
    } else {
        result->sym = newtemp();
    }
    
    emit(op, arg1, arg2, result, 0);
    return result;
}

void checkforeqop(expr* arg1, expr* arg2) {
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
}



expr* emit_relop(iopcode op, expr* arg1, expr* arg2, expr* result) {
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
    emit(op, arg1, arg2, result, 0);
    result->truelist = makelist(nextquad() - 1);
    emit(jump, nullptr, nullptr, nullptr, 0);
    result->falselist = makelist(nextquad() - 1);
    return result;
}

expr* emit_bool(iopcode op, expr* arg1, expr* arg2, expr* result) {
    result = newexpr(boolexpr_e);
    result->sym = newtemp();
    emit(op, arg1, arg2, result, 0);
    return result;
}
