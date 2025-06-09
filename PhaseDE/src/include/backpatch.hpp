// backpatch.hpp
#ifndef BACKPATCH_HPP
#define BACKPATCH_HPP
#pragma once

#include <vector>
#include "expr.hpp" 

// manage patch lists
int   newlist(int i);
int   mergelist(int i, int j);
void  patchlist(int list, int label);
void  patchlabel(unsigned quadNo, unsigned label);

std::vector<unsigned> makelist(unsigned label);
std::vector<unsigned> mergelist(const std::vector<unsigned>& l1, const std::vector<unsigned>& l2);
void backpatch(const std::vector<unsigned>& list, unsigned label);
void convertToBool(expr* e);
void convertToBoolNot(expr* e);


#endif // BACKPATCH_HPP
