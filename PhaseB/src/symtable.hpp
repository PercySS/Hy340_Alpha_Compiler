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
#include <unordered_map>

using namespace std;

typedef enum {
    VAR,
    FUNC,
    LIBFUNC,
    FORARG
} SymbolType;

typedef struct {
    string name;
    SymbolType type;
    int scope;
    int line;
    bool isActive;
} SymEntry;

class SymbolTable {
public:
    SymbolTable();
    ~SymbolTable();

    int getScope() const;
    int insert(SymEntry* entry);
    SymEntry* lookup(const string& name);
    
    void hide(int scope);
    void enter_scope();
    void exit_scope();
    
    void printTable(FILE* output) const;
private:
    int scope;
    std::vector<std::unordered_map<string, SymEntry>> scopes;
};



#endif // SYMTABLE_HPP