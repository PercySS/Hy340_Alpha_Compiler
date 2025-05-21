// stmt.hpp
#ifndef STMT_HPP
#define STMT_HPP

#include "expr.hpp"
#include <string>

// for break/continue backpatch lists
struct stmt_t {
    int breaklist;
    int contlist;
};

void make_stmt(struct stmt_t* s);

// call & index nodes
struct call {
    expr*         elist;
    std::string   name;
    unsigned char method;
};

struct indexed {
    expr*      index;
    expr*      value;
    indexed*   next;
};

struct forprefix {
    int test;
    int enter;
};

#endif // STMT_HPP
