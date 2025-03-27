#include "symtable.hpp"

SymbolTable::SymbolTable() {
    scope = 0;
    scopes.push_back(std::unordered_map<string, SymEntry>());
    // insert the library functions
    SymEntry* print = new SymEntry{"print", LIBFUNC, 0, 0, true};
    insert(print);
    SymEntry* input = new SymEntry{"input", LIBFUNC, 0, 0, true};
    insert(input);
    SymEntry* objectmemberkeys = new SymEntry{"objectmemberkeys", LIBFUNC, 0, 0, true};
    insert(objectmemberkeys);
    SymEntry* objecttotalmembers = new SymEntry{"objecttotalmembers", LIBFUNC, 0, 0, true};
    insert(objecttotalmembers);
    SymEntry* objectcopy = new SymEntry{"objectcopy", LIBFUNC, 0, 0, true};
    insert(objectcopy);
    SymEntry* totalarguments = new SymEntry{"totalarguments", LIBFUNC, 0, 0, true};
    insert(totalarguments);
    SymEntry* argument = new SymEntry{"argument", LIBFUNC, 0, 0, true};
    insert(argument);
    SymEntry* typeof = new SymEntry{"typeof", LIBFUNC, 0, 0, true};
    insert(typeof);
    SymEntry* strtonum = new SymEntry{"strtonum", LIBFUNC, 0, 0, true};
    insert(strtonum);
    SymEntry* sqrt = new SymEntry{"sqrt", LIBFUNC, 0, 0, true};
    insert(sqrt);
    SymEntry* cos = new SymEntry{"cos", LIBFUNC, 0, 0, true};
    insert(cos);
    SymEntry* sin = new SymEntry{"sin", LIBFUNC, 0, 0, true};
    insert(sin);
}

SymbolTable::~SymbolTable() {
    scopes.clear();
}


int SymbolTable::getScope() const {
    return scope;
}

int SymbolTable::insert(SymEntry* entry) {
    // then i check if the entry already exists in this scope
    if (scopes[entry->scope].find(entry->name) != scopes[entry->scope].end()) {
        return 2;
    }

    // if everything is ok i insert the entry
    scopes[entry->scope][entry->name] = *entry;
    return 0;
}

SymEntry* SymbolTable::lookup(const string& name) {
    for (int i = scope; i >= 0; i--) {
        auto it = scopes[i].find(name);
        if (it != scopes[i].end()) return &it->second;
    }
    return nullptr;
}


void SymbolTable::hide(int scope) {
    // check bounds 
    if (scope < 0 || scope > this->scope) {
        return;
    }

    for (auto it = scopes[scope].begin(); it != scopes[scope].end(); it++) {
        it->second.isActive = false;
    }
}

void SymbolTable::enter_scope() {
    // checks if scope is the last one and if so it creates a new one else it just increments the scope
    scope++;
    if ((size_t)scope == scopes.size() - 1) {
        scopes.push_back(std::unordered_map<string, SymEntry>());
    }
}

void SymbolTable::exit_scope() {
    hide(scope);
    if (scope > 0) scope--; 
}

void SymbolTable::printTable(FILE* output) const {
    for (int i = 0; i <= scope; i++) {
        fprintf(output, "Scope %d:\n", i);
        for (const auto& it : scopes[i]) {
            const SymEntry& e = it.second;
            fprintf(output, "  %s [scope: %d, line: %d, active: %d, type: %d]\n",
                    e.name.c_str(), e.scope, e.line, e.isActive, e.type);
        }
    }
}