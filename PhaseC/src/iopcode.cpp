#include "iopcode.hpp"
#include <iostream>
#include <string>

extern int yylineno;
extern FILE* yyout;
extern SymbolTable symTable;

static unsigned temp_counter = 0;

// ---------------- new temp var ----------------
std::string newtempname() {
    return "_t" + std::to_string(temp_counter++);
}

void resettemp() {
    temp_counter = 0;
}

SymEntry* newtemp() {
    std::string name = newtempname();
    unsigned scope = symTable.getScope();

    SymEntry* found = symTable.lookup(name, scope);

    if (found) return found;

    SymEntry* entry = new SymEntry();
    entry->name = name;
    entry->type = VAR;
    entry->scope = scope;
    entry->line = yylineno;
    entry->isActive = true;
    entry->isGlobal = (scope == 0);
    entry->isTemp = true;

    symTable.insert(entry);

    return entry;
}


// global quad storage
std::vector<quad> quads;

// global and quad ctr
static unsigned quad_counter = 0;

// ---------------- Emit ----------------
void emit(iopcode op, expr* arg1, expr* arg2, expr* result) {
    quad q;
    q.op = op;
    q.arg1 = arg1;
    q.arg2 = arg2;
    q.result = result;
    q.label = 0;
    q.line = 0;
    quads.push_back(q);
    quad_counter++;
}

// ---------------- quad index ------------
unsigned nextquad() {
    return quad_counter;
}

void patchlabel(unsigned quadNo, unsigned label) {
    assert(quadNo < quad_counter && !quads[quadNo].label);
    quads[quadNo].label = label;
}

// ---------------- new expression -------------------
expr* lvalue_expr(SymEntry* sym) {
    assert(sym);
    expr* e = newexpr(var_e);

    e->next = nullptr;
    e->sym = sym;

    switch (sym->type) {
        case VAR    :   e->type = var_e; break;
        case FUNC   :   e->type = programfunc_e; break;
        case LIBFUNC:   e->type = libraryfunc_e; break;
        default     :   assert(false);
    }

    return e;
}

expr* member_item(expr* lvalue, std::string name) {
    lvalue  = emit_iftableitem(lvalue);
    expr* e = newexpr(tableitem_e);
    e->sym = lvalue->sym; 
    e->index = newexpr_conststring(name);
    return e;
}

expr* newexpr_tmpvar(expr_t type) {
    expr* e = newexpr(type);
    e->sym = newtemp();
    return e;
}

expr* newexpr(expr_t type) {
    expr* e = new expr(type);
    e->type = type;
    e->sym = nullptr;
    e->index = nullptr;
    e->truelist.clear();
    e->falselist.clear();
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


expr* make_call(expr* lv, expr* reversed_list) {
    expr* func = emit_iftableitem(lv);
    while (reversed_list) {
        emit(param, reversed_list, nullptr, nullptr);
        reversed_list = reversed_list->next;
    }

    emit(call, func, nullptr, nullptr);
    expr* result = newexpr(var_e);
    result->sym = newtemp();
    emit(getretval, nullptr, nullptr, func);
    return result;
}


expr* emit_iftableitem(expr* e) {
    if (e->type == tableitem_e) {
        return e;
    } else { 
        expr* result = newexpr(var_e);
        result->sym = newtemp();
        emit(tablegetelem, e, e->index, result);
        
        return result;
    }

}



bool check_arith(expr* e, std::string context) { 
    if (
        e->type == constbool_e ||
        e->type == conststring_e ||
        e->type == nil_e ||
        e->type == newtable_e ||
        e->type == programfunc_e ||
        e->type == libraryfunc_e ||
        e->type == boolexpr_e 
    ) {
        comperror("Arithmetic operation on %s", context.c_str());
        return false;
    }

    return true;
}


void comperror(const char* msg, const char* context) {
    fprintf(yyout, "      [!] Error: ");
    fprintf(yyout, msg, context);
    fprintf(yyout, " in line %d.\n", yylineno);
}

unsigned int istempname(const std::string& name) {
    return name[0] == '_';
}

unsigned int istempexpr(expr* e) {
    return e->type == var_e && istempname(e->sym->name);
}

void make_stmt(stmt_t* s) {
    s->breaklist = 0;
    s->contlist = 0;
}

int newlist(int i) {
    quads[i].label = 0;
    return i;
}

int mergelist(int l1, int l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    int i = l1;
    while (quads[i].label) {
        i = quads[i].label;
    }

    quads[i].label = l2;
    return l1;
}

void patchlist(int list, int label) {
    while (list) {
        int next = quads[list].label;
        quads[list].label = label;
        list = next;
    }
}


expr* convert_to_bool(expr* e) {
    if (e->type == constbool_e) return e;

    if (e->type == constnum_e) {
        return newexpr_constbool(e->numConst != 0);
    }

    if (e->type == conststring_e) {
        return newexpr_constbool(!e->strConst.empty());
    }

    if (e->type == nil_e) {
        return newexpr_constbool(false);
    }

    if (e->type == programfunc_e || e->type == libraryfunc_e || e->type == newtable_e) {
        return newexpr_constbool(true);
    }

    // Dynamic case
    expr* result = newexpr(boolexpr_e);
    result->sym = newtemp();

    // emit: if e == false jump to assign false
    emit(if_eq, e, newexpr_constbool(false), newexpr_constnum(nextquad() + 3));

    // emit: assign true
    emit(assign, newexpr_constbool(true), nullptr, result);

    // emit: unconditional jump over false assign
    emit(jump, nullptr, nullptr, newexpr_constnum(nextquad() + 2));

    // emit: assign false
    emit(assign, newexpr_constbool(false), nullptr, result);

    return result;
}

static const char* iopcodeToString(iopcode op) {
    switch (op) {
        case assign: return "assign";
        case add: return "add";
        case sub: return "sub";
        case mul: return "mul";
        case div_op: return "div";
        case mod: return "mod";
        case uminus: return "uminus";
        case and_op: return "and";
        case or_op: return "or";
        case not_op: return "not";
        case if_eq: return "if_eq";
        case if_noteq: return "if_noteq";
        case if_lesseq: return "if_lesseq";
        case if_greatereq: return "if_greatereq";
        case if_less: return "if_less";
        case if_greater: return "if_greater";
        case jump: return "jump";
        case call: return "call";
        case param: return "param";
        case ret: return "ret";
        case getretval: return "getretval";
        case funcstart: return "funcstart";
        case funcend: return "funcend";
        case tablecreate: return "tablecreate";
        case tablegetelem: return "tablegetelem";
        case tablesetelem: return "tablesetelem";
        default: return "unknown_op";
    }
}

std::string exprToString(expr* e) {
    if (!e) return "nil";

    switch (e->type) {
        case constbool_e:
            return e->boolConst ? "true" : "false";
        case constnum_e:
            return std::to_string(e->numConst);
        case conststring_e:
            return "\"" + std::string(e->strConst) + "\"";
        case var_e:
        case arithexpr_e:
        case boolexpr_e:
        case assignexpr_e:
        case newtable_e:
        case programfunc_e:
        case libraryfunc_e:
            return e->sym ? e->sym->name : "nullsym";
        case tableitem_e:
            return (e->sym ? e->sym->name : "nullsym") + "[" +
                   (e->index ? exprToString(e->index) : "nullindex") + "]";
        default:
            return "invalid";
    }
}


void print_quads(FILE* out) {
    for (unsigned i = 0; i < quads.size(); ++i) {
        const quad& q = quads[i];
        fprintf(out, "%-4u: %-12s %-10s %-10s %-10s",
            i,
            iopcodeToString(q.op),
            exprToString(q.result).c_str(),
            exprToString(q.arg1).c_str(),
            exprToString(q.arg2).c_str()
        );
        if (q.label)
            fprintf(out, "  [label: %u]", q.label);
        fprintf(out, "\n");
    }
}
