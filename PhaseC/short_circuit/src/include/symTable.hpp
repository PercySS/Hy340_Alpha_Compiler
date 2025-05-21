// symtable.hpp
#ifndef SYMTABLE_HPP
#define SYMTABLE_HPP

#include "types.hpp"
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <cstdio>

// symbol‐table entry
struct SymEntry {
    std::string       name;
    SymbolType        type;
    int               scope;
    int               line;
    bool              isActive;
    bool              isGlobal = false;
    bool              isTemp   = false;
    unsigned          iaddress;
    unsigned          totalLocals;
    std::vector<SymEntry*> args;
    ScopeSpace        space;
    unsigned          offset;
};

// the table itself
class SymbolTable {
public:
    SymbolTable();
    ~SymbolTable();

    void                 insert(SymEntry* entry);
    SymEntry*            lookup(const std::string& name, int scope = -1) const;
    void                 hide(int scope);
    void                 enter_scope();
    void                 exit_scope();
    int                  getScope() const;
    void                 printTable(FILE* output) const;

    ScopeSpace           currScopeSpace() const;
    unsigned             currScopeOffset() const;
    void                 incCurrScopeOffset();
    void                 enterScopeSpace();
    void                 exitScopeSpace();
    void                 resetFormalsOff();
    void                 resetFuncLocalsOff();
    void                 restoreCurrScopeOffset(unsigned offset);
    unsigned             top_pop(std::stack<unsigned>& stack);

    std::vector<std::string> libfuncs;
    std::stack<SymEntry*>    funcStack;
    std::stack<unsigned>     scopeOffsetStack;
private:
    int scope;
    std::vector<std::vector<std::pair<std::string,SymEntry*>>> scopes;
    unsigned programVarOffset,
             functionLocalOffset,
             formalsOffset,
             scopeSpaceCtr;
};

// utilities
std::string typeToString(SymEntry type);
std::string generateAnonymousName();

#endif // SYMTABLE_HPP
