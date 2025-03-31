#include "symtable.hpp"

SymbolTable::SymbolTable() {
    scope = 0;
    scopes.push_back(std::vector<std::pair<std::string, SymEntry>>());

    libfuncs = {
        "print", "input", "objectmemberkeys", "objecttotalmembers",
        "objectcopy", "totalarguments", "argument", "typeof",
        "strtonum", "sqrt", "cos", "sin"
    };

    for (const std::string& name : libfuncs) {
        SymEntry* entry = new SymEntry{name, LIBFUNC, 0, 0, true};
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

int SymbolTable::insert(SymEntry* entry) {
    SymEntry* found = new SymEntry;
    assert(entry);

    assert(entry->scope >= 0 && entry->scope < (int)scopes.size());


    scopes[entry->scope].emplace_back(entry->name, *entry);
    return 0;
}



SymEntry* SymbolTable::lookup(const std::string& name, int scope) const {
    assert(!name.empty());
    assert(scope >= 0 && scope < (int)scopes.size());   

    

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
    ss << "ANON_" << counter++;
    return ss.str();
}