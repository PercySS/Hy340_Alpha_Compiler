#include "symtable.hpp"

SymbolTable::SymbolTable() {
    scope = 0;
    scopes = std::vector<std::vector<std::pair<std::string, SymEntry>>>();
    scopes.emplace_back(std::vector<std::pair<std::string, SymEntry>>());
    funcStack = std::stack<SymEntry*>();
    scopeOffsetStack = std::stack<unsigned>();

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



    programVarOffset = 0;
    functionLocalOffset = 0;
    formalsOffset = 0;
    scopeSpaceCtr = 1;
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

    if (entry->type == VAR || entry->type == FORARG) {
        entry->space = currScopeSpace();
        entry->offset = currScopeOffset();
        incCurrScopeOffset();
    }

    scopes[entry->scope].emplace_back(entry->name, *entry);
}



SymEntry* SymbolTable::lookup(const std::string& name, int scopet) const {
    assert(!name.empty());
    assert(scopet >= -1 && scopet < ((int)this->scopes.size()));   

    // if scope is -1, search in all scopes from the inner to the outer
    if (scopet == -1) {
        for (int i = this->scopes.size() - 1; i >= 0; --i) {
            for (const auto& pair : this->scopes[i]) {
                if (pair.first == name && pair.second.isActive) {
                    return const_cast<SymEntry*>(&pair.second); // return a copy of the entry
                }
            }
        }
    } else {
        // search in the specified scope
        for (const auto& pair : scopes[scopet]) {
            if (pair.first == name && pair.second.isActive) {
                return const_cast<SymEntry*>(&pair.second); // return a copy of the entry
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
        scopes.emplace_back(std::vector<std::pair<std::string, SymEntry>>());
    }
}

void SymbolTable::exit_scope() {
    if (scope == 0) return;

    for (size_t i = 0; i < scopes[scope].size(); ++i) {
        scopes[scope][i].second.isActive = false;
    }

    scope--;
}

void SymbolTable::printTable(FILE* output) const {
    fprintf(output, "\n====================== SYMBOL TABLE ======================\n");

    for (size_t i = 0; i < scopes.size(); ++i) {
        if (scopes[i].empty()) continue;

        fprintf(output, "\n>> Scope %zu\n", i);
        fprintf(output, "----------------------------------------------------------\n");
        fprintf(output, "%-20s | %-5s | %-5s | %-6s | %-10s\n", 
                "Name", "Scope", "Line", "Active", "Type");
        fprintf(output, "----------------------------------------------------------\n");

        for (const auto& [name, e] : scopes[i]) {
            fprintf(output, "%-20s | %-5d | %-5d | %-6s | %-10s\n",
                    e.name.c_str(),
                    e.scope,
                    e.line,
                    e.isActive ? "true" : "false",
                    typeToString(e).c_str());
        }
    }

    fprintf(output, "\n==================== END OF SYMTABLE =====================\n\n");
}

ScopeSpace SymbolTable::currScopeSpace() const {
    if (scopeSpaceCtr == 1) return programvar;
    else if (scopeSpaceCtr % 2 == 0) return formalarg;
    else return functionlocal;

}

unsigned SymbolTable::currScopeOffset() const {
    switch (currScopeSpace()) {
        case programvar:    return programVarOffset;
        case functionlocal: return functionLocalOffset;
        case formalarg:     return formalsOffset;   
        default:           assert(false); return 0;
    }
}

void SymbolTable::incCurrScopeOffset() {
    switch (currScopeSpace()) {
        case programvar:    ++programVarOffset; break;
        case functionlocal: ++functionLocalOffset; break;
        case formalarg:     ++formalsOffset; break;   
        default:           assert(false);
    }
}

void SymbolTable::enterScopeSpace() {
    ++scopeSpaceCtr;
}

void SymbolTable::exitScopeSpace() {
    assert(scopeSpaceCtr > 1);
    --scopeSpaceCtr;
}

void SymbolTable::resetFormalsOff() {
    formalsOffset = 0;
}

void SymbolTable::resetFuncLocalsOff() {
    functionLocalOffset = 0;
}

void SymbolTable::restoreCurrScopeOffset(unsigned offset) {
    switch (currScopeSpace()) {
        case programvar:    programVarOffset = offset; break;
        case functionlocal: functionLocalOffset = offset; break;
        case formalarg:     formalsOffset = offset; break;   
        default:           assert(false);
    }
}



unsigned SymbolTable::top_pop(std::stack<unsigned>& stack) {
    assert(!stack.empty());
    unsigned offset = stack.top();
    stack.pop();
    return offset;
}

std::string typeToString(SymEntry entry) {
    switch (entry.type) {
        case VAR: return entry.isGlobal ? "GLOBAL_VAR" : "LOCAL_VAR";
        case FUNC: return "USER_FUNC";
        case LIBFUNC: return "LIBFUNC";
        case FORARG: return "FORARG";
        default: return "UNKNOWN";
    }
}

std::string generateAnonymousName() {
    static int counter = 0;
    std::stringstream ss;
    ss << "$ANON_" << counter++;
    return ss.str();
}