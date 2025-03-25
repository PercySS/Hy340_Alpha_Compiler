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


    bool insert(SymEntry* entry);
    SymEntry* lookup(string name);
    
    void hide(int scope);
    void enter_scope();
    void exit_scope();
    
    void printTable();
private:
    int scope;
    vector<
};



#endif // SYMTABLE_HPP