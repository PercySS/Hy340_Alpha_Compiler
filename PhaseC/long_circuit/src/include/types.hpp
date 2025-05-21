// types.hpp
#ifndef TYPES_HPP
#define TYPES_HPP

// basic enums used throughout
enum expr_t {
    var_e, tableitem_e,
    programfunc_e, libraryfunc_e,
    arithexpr_e, boolexpr_e, assignexpr_e, newtable_e,
    constnum_e, constbool_e, conststring_e, nil_e
};

enum iopcode {
    assign, add, sub, mul, div_op, mod,
    uminus, and_op, or_op, not_op,
    if_eq, if_noteq, if_lesseq, if_greatereq, if_less, if_greater,
    jump, call, param, ret, getretval,
    funcstart, funcend,
    tablecreate, tablegetelem, tablesetelem
};

typedef enum {
    programvar, functionlocal, formalarg
} ScopeSpace;

typedef enum {
    VAR, FUNC, LIBFUNC, FORARG, NONLVAL
} SymbolType;

#endif // TYPES_HPP
