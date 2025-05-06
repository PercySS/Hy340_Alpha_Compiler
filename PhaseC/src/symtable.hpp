#ifndef SYMTABLE_HPP
#define SYMTABLE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cassert>
#include <cstring>
#include <vector>
#include <stack>

typedef enum {
    programvar,
    functionlocal,
    formalarg,
} ScopeSpace;

typedef enum {
    VAR,
    FUNC,
    LIBFUNC,
    FORARG,
    NONLVAL
} SymbolType;

typedef struct SymEntry {
    std::string name;
    SymbolType type;
    int scope;
    int line;
    bool isActive;
    bool isGlobal = false;
    std::vector<SymEntry*> args;

    ScopeSpace space;
    unsigned offset;
} SymEntry;

class SymbolTable {
public:
    SymbolTable();
    ~SymbolTable();

    std::vector<std::string> libfuncs; 
    std::stack<SymEntry*> funcStack;

    int getScope() const;

    // insertion
    void insert(SymEntry* entry);
    
    // lookupz
    SymEntry* lookup(const std::string& name, int scope = -1) const;

    void hide(int scope);
    void enter_scope();
    void exit_scope();
    
    void printTable(FILE* output) const;

    ScopeSpace currScopeSpace() const;
    unsigned currScopeOffset() const;
    void incCurrScopeOffset();
    void enterScopeSpace();
    void exitScopeSpace();
    void resetFormalsOff();
    void resetFuncLocalsOff();
    void restoreCurrScopeOffset(unsigned offset);
private:
    int scope;
    std::vector<std::vector<std::pair<std::string, SymEntry>>> scopes;

    unsigned programVarOffset;
    unsigned functionLocalOffset;
    unsigned formalsOffset;
    unsigned scopeSpaceCtr;
};

std::string typeToString(SymEntry type);

std::string generateAnonymousName();


#endif // SYMTABLE_HPP