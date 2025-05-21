// src/temp.cpp
#include "../include/temp.hpp"
#include "../include/symtable.hpp"

static unsigned temp_counter;
extern SymbolTable symTable;
extern int yylineno;

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
    entry->name     = name;
    entry->type     = VAR;
    entry->scope    = scope;
    entry->line     = yylineno;
    entry->isActive = true;
    entry->isGlobal = (scope == 0);
    entry->isTemp   = true;

    symTable.insert(entry);
    return symTable.lookup(name, scope);
}
