// src/backpatch.cpp
#include "../include/backpatch.hpp"
#include "../include/quad.hpp"
#include "../include/stmt.hpp"
#include <cassert>

extern std::vector<quad*> quads;

struct stmt_t* make_stmt() {
    struct stmt_t* s = new struct stmt_t;
    s->breaklist = 0;
    s->contlist  = 0;
    return s;
}

int newlist(int i) {
    quads[i]->label = 0;
    return i;
}

int mergelist(int l1, int l2) {
    if (!l1) return l2;
    else if (!l2) return l1;
    else {
        int i = l1;
        while (quads[i]->label) {
            i = quads[i]->label;
        }
        quads[i]->label = l2;
        return l1;
    }
}

void patchlist(int list, int label) {
    while (list) {
        int next = quads[list]->label;
        quads[list]->label = label;
        list = next;
    }
}
