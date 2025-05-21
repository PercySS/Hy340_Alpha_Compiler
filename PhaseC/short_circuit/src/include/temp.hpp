// temp.hpp
#ifndef TEMP_HPP
#define TEMP_HPP

#include "symtable.hpp"
#include <string>

// temp‐var generators & reset
SymEntry* newtemp();
std::string newtempname();
void      resettemp();

#endif // TEMP_HPP
