#include "iopcode.hpp"
#include <iostream>
#include <string>

extern int yylineno;
extern FILE* yyout;
extern SymbolTable symTable;

static unsigned temp_counter = 0;
std::vector<quad> quads;
static unsigned quad_counter = 0;

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


void emit(iopcode op, expr* arg1, expr* arg2, expr* result, unsigned label) {
    quad q;
    q.op = op;
    q.arg1 = arg1;
    q.arg2 = arg2;
    q.result = result;
    q.label = label;
    q.line = yylineno;
    quads.push_back(q);
    quad_counter++;
}

expr* lvalue_expr(SymEntry* sym) {
    assert(sym);
    expr* e = newexpr(var_e);

    e->next = nullptr;
    e->sym = sym;

    switch (sym->type) {
        case VAR    :   e->type = var_e; break;
        case FORARG :   e->type = var_e; break;
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

expr* newexpr(expr_t type) {
    expr* e = new expr(type);
    e->type = type;
    e->sym = nullptr;
    e->index = nullptr;
    return e;
}

expr* newexpr_conststring(const std::string& str) {
    expr* e = newexpr(conststring_e);
    e->strConst = str;
    return e;
}

expr* emit_iftableitem(expr* e) {
    if (e->type != tableitem_e) {
        return e;
    } else { 
        expr* result = newexpr(var_e);
        result->sym = newtemp();
        emit(tablegetelem, e, e->index, result, 0);
        
        return result;
    }
}

expr* make_call(expr* lv, expr* reversed_list) {
    expr* func = emit_iftableitem(lv);
    while (reversed_list) {
        emit(param, reversed_list, nullptr, nullptr, 0);
        reversed_list = reversed_list->next;
    }
    
    emit(call, func, nullptr, nullptr, 0);
    
    expr* result = newexpr(var_e);
    result->sym = newtemp();
    
    emit(getretval, nullptr, nullptr, result, 0);
    
    return result;
}

expr* newexpr_constnum(double val) {
    expr* e = newexpr(constnum_e);
    e->numConst = val;
    return e;
}

expr* newexpr_tmpvar(expr_t type) {
    expr* e = newexpr(type);
    e->sym = newtemp();
    return e;
}



expr* newexpr_constbool(bool b) {
    expr* e = newexpr(constbool_e);
    e->boolConst = b;
    return e;
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

unsigned nextquad() {
    return quad_counter;
}

void patchlabel(unsigned quadNo, unsigned label) {
    assert(quadNo < quad_counter);
    quads[quadNo].label = label;
}

void make_stmt(stmt_t* s) {
    s->breaklist = s->contlist = 0;
}

int newlist(int i) {
    quads[i].label = 0;
    return i;
}

int mergelist(int l1, int l2) {
    if (!l1) {
        return l2;
    } else if (!l2) {
        return l1;
    } else {
        int i = l1;
        
        while (quads[i].label) {
            i = quads[i].label;
        }
        quads[i].label = l2;
        return l1;
    } 
    
}

void patchlist(int list, int label) {
    while (list) {
        int next = quads[list].label;
        quads[list].label = label;
        list = next;
    }
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

std::string exprToString(expr* e) {
    if (!e) return "_";

    switch (e->type) {
        case constbool_e:
            return e->boolConst ? "true" : "false";

        case constnum_e: {
            std::ostringstream oss;
            oss << e->numConst;
            return oss.str();
        }

        case conststring_e:
            return "\"" + e->strConst + "\"";

        case nil_e:
            return "nil";

        case var_e:
        case tableitem_e:
        case arithexpr_e:
        case boolexpr_e:
        case assignexpr_e:
        case programfunc_e:
        case libraryfunc_e:
        case newtable_e:
            return (e->sym && e->sym->name != "") ? e->sym->name : "unnamed";

        default:
            return "?";
    }
}


const char* iopcodeToString(iopcode op) {
    static const char* names[] = {
        "assign", "add", "sub", "mul", "div", "mod",
        "uminus", "and", "or", "not",
        "if_eq", "if_noteq", "if_lesseq", "if_greatereq", "if_less", "if_greater",
        "jump", "call", "param", "ret",
        "getretval", "funcstart", "funcend",
        "tablecreate", "tablegetelem", "tablesetelem"
    };
    return names[op];
}

void print_quads(FILE* out) {
    fprintf(out, "\n===================== QUADS =====================\n");
    fprintf(out, "%-6s | %-12s | %-20s | %-20s | %-20s | %-6s\n", 
            "Quad#", "Opcode", "Result", "Arg1", "Arg2", "Label");
    fprintf(out, "--------------------------------------------------------");
    fprintf(out, "--------------------------------------------------------\n");

    for (unsigned i = 0; i < quads.size(); ++i) {
        const quad& q = quads[i];
        
        fprintf(out, "%-6u | %-12s | %-20s | %-20s | %-20s | ",
                i + 1,
                iopcodeToString(q.op),
                exprToString(q.result).c_str(),
                exprToString(q.arg1).c_str(),
                exprToString(q.arg2).c_str());

        if (q.label > 0) {
            fprintf(out, "%-6u", q.label);
        } else {
            fprintf(out, "%-6s", "-");
        }
        fprintf(out, "\n");
    }
    fprintf(out, "=================== END QUADS ==================\n\n");
}


