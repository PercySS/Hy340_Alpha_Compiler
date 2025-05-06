#include "iopcode.hpp"
#include <iostream>
#include <string>

// global quad storage
std::vector<quad> quads;

// global temp var and quad ctr
static unsigned temp_counter = 0;
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

// ---------------- new expression -------------------
expr* newexpr(expr_t type) {
    return new expr(type);
}

expr* lvalue_expr(SymEntry* sym) {
    expr* e = newexpr(var_e);
    e->sym = sym;
    return e;
}

expr* newexpr_constnum(double val) {
    expr* e = newexpr(constnum_e);
    e->numConst = val;
    return e;
}

expr* newexpr_constbool(bool val) {
    expr* e = newexpr(constbool_e);
    e->boolConst = val;
    return e;
}

expr* newexpr_conststring(const std::string& str) {
    expr* e = newexpr(conststring_e);
    e->strConst = str;
    return e;
}

// ---------------- new temp var ----------------
std::string newtempname() {
    return "_t" + std::to_string(temp_counter++);
}

void resettemp() {
    temp_counter = 0;
}

extern SymbolTable symTable; // για να έχει πρόσβαση στο scope

SymEntry* newtemp(int line) {
    std::string name = newtempname();
    
    SymEntry* entry = new SymEntry;
    entry->name = name;
    entry->type = VAR;
    entry->scope = symTable.getScope();
    entry->line = line;
    entry->isActive = true;
    entry->isGlobal = (entry->scope == 0);

    // νέα πεδία για phase 3
    entry->space = symTable.currScopeSpace();
    entry->offset = symTable.currScopeOffset();
    symTable.incCurrScopeOffset();

    symTable.insert(entry);
    return entry;
}

void make_call(expr* func, expr* elist) {
    if (func->type == tableitem_e) {
        // Handle functor call
        expr* func_expr = emit_iftableitem(func); // ensure func is resolved

        // Create expr for key "()" to access t["()"]
        expr* key = newexpr_conststring("()");
        expr* call_slot = newexpr(tableitem_e);
        call_slot->sym = func_expr->sym;
        call_slot->index = key;

        expr* real_func = emit_iftableitem(call_slot);

        // Make param list: first param is the table itself
        emit(param, func_expr, nullptr, nullptr);  // push table
        for (expr* arg = elist; arg; arg = arg->next)
            emit(param, arg, nullptr, nullptr);

        emit(call, real_func, nullptr, nullptr);

    } else {
        // Normal function call
        for (expr* arg = elist; arg; arg = arg->next)
            emit(param, arg, nullptr, nullptr);

        emit(call, func, nullptr, nullptr);
    }
}

expr* emit_iftableitem(expr* e, int line) {
    if (e->type != tableitem_e)
        return e;

    expr* result = newexpr(var_e);
    result->sym = newtemp(line);

    emit(tablegetelem, e, e->index, result);

    return result;
}
