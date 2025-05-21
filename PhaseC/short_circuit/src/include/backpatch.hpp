// backpatch.hpp
#ifndef BACKPATCH_HPP
#define BACKPATCH_HPP

// manage patch lists
int   newlist(int i);
int   mergelist(int i, int j);
void  patchlist(int list, int label);
void  patchlabel(unsigned quadNo, unsigned label);


#endif // BACKPATCH_HPP
