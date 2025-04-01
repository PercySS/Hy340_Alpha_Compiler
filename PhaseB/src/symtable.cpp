#include "symtable.hpp"

SymbolTable::SymbolTable() {
    scope = 0;
    scopes.push_back(std::vector<std::pair<std::string, SymEntry>>());
    funcStack.push(nullptr);

    libfuncs = {
        "print", "input", "objectmemberkeys", "objecttotalmembers",
        "objectcopy", "totalarguments", "argument", "typeof",
        "strtonum", "sqrt", "cos", "sin"
    };

    for (const std::string& name : libfuncs) {
        SymEntry* entry = new SymEntry;
        entry->name = name;
        entry->scope = 0;
        entry->line = 0;
        entry->isActive = true;
        entry->type = LIBFUNC;
        entry->args.clear();
        insert(entry);
        delete entry;
    }
}

SymbolTable::~SymbolTable() {
    scopes.clear();
}


int SymbolTable::getScope() const {
    return this->scope;
}

void SymbolTable::insert(SymEntry* entry) {
    assert(entry);

    assert(entry->scope >= 0 && entry->scope < (int)scopes.size());

    scopes[entry->scope].emplace_back(entry->name, *entry);
}



SymEntry* SymbolTable::lookup(const std::string& name, int scope) const {
    assert(!name.empty());
    assert(scope >= -1 && scope < (int)scopes.size());   

    // if scope is -1, search in all scopes
    if (scope == -1) {
        for (int i = scopes.size() - 1; i >= 0; --i) {
            for (const auto& pair : scopes[i]) {
                if (pair.first == name && pair.second.isActive) {
                    return new SymEntry(pair.second); // return a copy of the entry
                }
            }
        }
    } else {
        // search in the specified scope
        for (const auto& pair : scopes[scope]) {
            if (pair.first == name && pair.second.isActive) {
                return new SymEntry(pair.second); // return a copy of the entry
            }
        }
    }

    // if not found return null
    return nullptr;
}

void SymbolTable::hide(int scope) {
    if (scope < 0 || scope >= (int)scopes.size()) return;

    for (auto& pair : scopes[scope]) {
        pair.second.isActive = false;
    }
}

void SymbolTable::enter_scope() {
    scope++;
    if ((size_t)scope >= scopes.size()) {
        scopes.push_back(std::vector<std::pair<std::string, SymEntry>>());
    }
}

void SymbolTable::exit_scope() {
    if (scope < 0) return;

    for (size_t i = 0; i < scopes[scope].size(); ++i) {
        scopes[scope][i].second.isActive = false;
    }

    scope--;
}

void SymbolTable::printTable(FILE* output) const {
    printf("\n======Printing symbol table======");
    for (int i = 0; (size_t)i < scopes.size(); i++) {
        fprintf(output, "\n");
        for (int j = 0; j < i; j++) fprintf(output, "      ");
        fprintf(output, "Scope %d:\n", i);
        for (const auto& it : scopes[i]) {
            fprintf(output, "      ");
            for (int j = 0; j < i; j++) fprintf(output, "      ");
            const SymEntry& e = it.second;
            fprintf(output, "%s [scope: %d, line: %d, active: %d, type: %s]\n",
                    e.name.c_str(), e.scope, e.line, e.isActive, typeToString(e.type).c_str());
        }
    }
    printf("======END OF SYMTABLE======\n\n");
}

std::string typeToString(SymbolType type) {
    switch (type) {
        case VAR: return "VAR";
        case FUNC: return "FUNC";
        case LIBFUNC: return "LIBFUNC";
        case FORARG: return "FORARG";
        default: return "UNKNOWN";
    }
}

std::string generateAnonymousName() {
    static int counter = 0;
    std::stringstream ss;
    ss << "_ANON_" << counter++;
    return ss.str();
}