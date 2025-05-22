// quad.hpp
#ifndef QUAD_HPP
#define QUAD_HPP

#include "types.hpp"
#include "expr.hpp"
#include <cstdio>

// the quad IR node
struct quad {
    iopcode op;
    expr*   result;
    expr*   arg1;
    expr*   arg2;
    int label = 0;
    unsigned line  = 0;
};

// quad management
void    init_quads();
void    emit(iopcode op, expr* arg1, expr* arg2, expr* result, int label = 0);
expr* emit_iftableitem(expr* e);
unsigned nextquad();
void optimize_jumps();
void    print_quads(FILE* output);


// convenience emitters
expr* emit_arith(iopcode op, expr* a1, expr* a2, expr* res);
expr* emit_relop(iopcode op, expr* a1, expr* a2, expr* res);
expr* emit_bool(iopcode op, expr* a1, expr* a2, expr* res);
void checkforeqop(expr* arg1, expr* arg2);

#endif // QUAD_HPP
