// src/backpatch.cpp
#include "../include/backpatch.hpp"
#include "../include/quad.hpp"
#include "../include/stmt.hpp"
#include <cassert>

extern std::vector<quad*> quads;
extern std::stack<int> breakStack;

void make_stmt(struct stmt_t* s) {
    s->breaklist = 0;
    s->contlist  = 0;
}

int newlist(int i) {
    quads[i]->label = 0;
    return i;
}

int mergelist(int l1, int l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    int i = l1 - 1;
    while (quads[i]->label) {
        printf("[mergelist] merging l1=%d with l2=%d\n", l1, l2);
        i = quads[i]->label;
    }
    quads[i]->label = l2 - 1;
    return l1;

}

void patchlist(int list, int label) {
    while (list) {
        int next = quads[list]->label;
        quads[list]->label = label;
        list = next;
    }
}


// short-circuiting
std::vector<unsigned> makelist(unsigned label) {
    return {label};
}

std::vector<unsigned> mergelist(const std::vector<unsigned>& l1, const std::vector<unsigned>& l2) {
    if (l1.empty()) return l2;
    if (l2.empty()) return l1;

    std::vector<unsigned> merged = std::vector<unsigned>();
    merged.reserve(l1.size() + l2.size());
    merged.insert(merged.end(), l1.begin(), l1.end());
    merged.insert(merged.end(), l2.begin(), l2.end());
    return merged;
}

void backpatch(const std::vector<unsigned>& list, unsigned label) {
    for (unsigned quadNo : list) {
        assert(quadNo < quads.size());
        quads[quadNo]->label = label;
    }
}

void convertToBool(expr* e) {
    if (e->truelist.empty() && e->falselist.empty()) {
        emit(if_eq, e, newexpr_constbool(true), nullptr, 0);
        e->truelist.push_back(nextquad()- 1);
        emit(jump, nullptr, nullptr, nullptr, 0);
        e->falselist.push_back(nextquad() - 1);
        
    }
}

void backpatch_method(expr* e) {
    backpatch(e->truelist, nextquad());
    backpatch(e->falselist, nextquad() + 2);
    emit(assign, newexpr_constbool(true), nullptr, e, 0);
    emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
    emit(assign, newexpr_constbool(false), nullptr, e, 0);
}