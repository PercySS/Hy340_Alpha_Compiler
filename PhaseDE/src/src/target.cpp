#include "../include/target.hpp"
#define MAGIC_NUMBER 0xDEADBEEF

extern std::vector<quad*> quads;
std::vector<double> numConsts;
std::vector<std::string> stringConsts;
std::vector<std::string> namedLibFuncs;
std::vector<userfunc> userFuncs;
std::vector<instruction> instructions;
std::vector<incomplete_jump> jumps;
unsigned currProcessedQuad = 0;
std::stack<unsigned> funcs;


void add_incomplete_jump(unsigned instr, unsigned iaddress) {
    incomplete_jump ij = {instr, iaddress};
    jumps.push_back(ij);
}

void patch_incomplete_jumps() {
  for (auto &ij : jumps) {
    unsigned instrNo   = ij.instr;
    unsigned quadIndex = ij.iaddress;
    unsigned target;

    if (quadIndex >= quads.size()) {
      target = instructions.size();
    } else {
      target = quads[quadIndex]->taddress;
    }

    instructions[instrNo].result.val = target;
  }
  jumps.clear();
}


unsigned consts_newstring(std::string s) {
    stringConsts.push_back(s);
    return stringConsts.size() - 1;
}

unsigned consts_newnum(double n) {
    numConsts.push_back(n);
    return numConsts.size() - 1;
}

unsigned userfuncs_newfunc(SymEntry* u) {
    for (unsigned i = 0; i < userFuncs.size(); ++i) {
        if (userFuncs[i].id == u->name)
            return i;
    }
    
    userfunc uf;
    uf.address   = u->taddress;       
    uf.localSize = u->totalLocals;    
    uf.id        = u->name;           
    userFuncs.push_back(uf);
    return userFuncs.size() - 1;
}

unsigned libfuncs_newused(std::string s) {
    for (unsigned i = 0; i < namedLibFuncs.size(); ++i) {
        if (namedLibFuncs[i] == s)
            return i;
    }
    namedLibFuncs.push_back(s);
    return namedLibFuncs.size() - 1;
}

void make_operand(expr* e, vmarg* arg) {
    if (!e) {
        reset_operand(arg);
        return;
    }

    switch (e->type) {
      case var_e:
      case tableitem_e:
      case arithexpr_e:
      case boolexpr_e:
      case newtable_e:
      case assignexpr_e:
        assert(e->sym && "internal error: variable expr with no sym");
        arg->val = e->sym->offset;
        switch (e->sym->space) {
          case programvar:    arg->type = global_a;  break;
          case functionlocal: arg->type = local_a;   break;
          case formalarg:     arg->type = formal_a;  break;
          default:            assert(false);
        }
        break;

      case constbool_e:
        arg->type = bool_a;
        arg->val  = e->boolConst ? 1 : 0;
        break;

      case constnum_e:
        arg->type = number_a;
        arg->val  = consts_newnum(e->numConst);
        break;

      case conststring_e:
        arg->type = string_a;
        arg->val  = consts_newstring(e->strConst);
        break;

      case nil_e:
        reset_operand(arg);
        break;

      case programfunc_e:  // or userfunc_e in your enum
        assert(e->sym);
        arg->type = userfunc_a;
        arg->val  = e->sym->taddress;
        break;

      case libraryfunc_e:
        arg->type = libfunc_a;
        arg->val  = libfuncs_newused(e->sym->name);
        break;

      default:
        assert(false && "Unhandled expr type in make_operand");
    }
}


void make_numberoperand(vmarg* arg, double n) {
    arg->type = number_a;
    arg->val = consts_newnum(n);
}

void make_booloperand(vmarg* arg, std::string s) {
    arg->type = bool_a;
    arg->val = (s == "true") ? 1 : 0;
}

void make_retvaloperand(vmarg* arg) {
    arg->type = retval_a;
    arg->val = 0;
}

void emit(instruction t) {
    instructions.push_back(t);
}

unsigned nextinstructionlabel() {
    return instructions.size();
}

void generate(vmopcode op, quad* quad) {
    instruction t{};
    t.opcode = op;
    make_operand(quad->arg1, &t.arg1);
    make_operand(quad->arg2, &t.arg2);
    make_operand(quad->result, &t.result);
    quad->taddress = nextinstructionlabel();
    t.srcLine = quad->line;
    emit(t);
}

void reset_operand(vmarg* arg) {
    arg->type = nil_a;
    arg->val = 0;
}

void generate_add(quad* quad)       {generate(add_v, quad);}
void generate_sub(quad* quad)       {generate(sub_v, quad);}
void generate_mul(quad* quad)       {generate(mul_v, quad);}
void generate_div(quad* quad)       {generate(div_v, quad);}
void generate_mod(quad* quad)       {generate(mod_v, quad);}
void generate_newtable(quad* quad)  {generate(newtable_v, quad);}
void generate_getelem(quad* quad)   {generate(tablegetelem_v, quad);}
void generate_setelem(quad* quad)   {generate(tablesetelem_v, quad);}
void generate_assign(quad* quad)    {generate(assign_v, quad);}

void generate_nop(quad* quad) {
    instruction t{};
    t.opcode = nop_v;
    emit(t);
}

void generate_uminus(quad* quad) {
    instruction t{};
    t.opcode = uminus_v;
    make_operand(quad->arg1, &t.arg1);
    make_operand(quad->result, &t.result);
    quad->taddress = nextinstructionlabel();
    t.srcLine = quad->line;
    emit(t);
}

void generate_relational(vmopcode op, quad* quad) {
    instruction t{};
    t.opcode = op;
    make_operand(quad->arg1, &t.arg1);
    make_operand(quad->arg2, &t.arg2);

    t.result.type = label_a;
    if (quad->label < currProcessedQuad) {
        t.result.val = quads[quad->label]->taddress;
    } else {
        add_incomplete_jump(nextinstructionlabel(), quad->label);
    }
    quad->taddress = nextinstructionlabel();
    t.srcLine = quad->line;
    emit(t);
}

void generate_jump(quad* quad) {generate_relational(jump_v, quad);}
void generate_ifeq(quad* quad) {generate_relational(jeq_v, quad);}
void generate_ifne(quad* quad) {generate_relational(jne_v, quad);}
void generate_ifle(quad* quad) {generate_relational(jle_v, quad);}
void generate_ifge(quad* quad) {generate_relational(jge_v, quad);}
void generate_iflt(quad* quad) {generate_relational(jlt_v, quad);}
void generate_ifgt(quad* quad) {generate_relational(jgt_v, quad);}

void generate_not(quad* quad) {
    quad->taddress = nextinstructionlabel();
    instruction t{};
    t.opcode = jeq_v;
    make_operand(quad->arg1, &t.arg1);
    make_booloperand(&t.arg2, "false");
    t.result.type = label_a;
    t.result.val = nextinstructionlabel() + 3; // Jump to the next instruction after the not
    emit(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, "false");
    reset_operand(&t.arg2);
    make_operand(quad->result, &t.result);
    emit(t);

    t.opcode = jump_v;
    reset_operand(&t.arg1);
    reset_operand(&t.arg2);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel() + 2; // Jump to the end of the not
    emit(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, "true");
    reset_operand(&t.arg2);
    make_operand(quad->result, &t.result);
    emit(t);
}

void generate_or(quad* quad) {
    quad->taddress = nextinstructionlabel();
    instruction t{};
    
    t.opcode = jeq_v;
    make_operand(quad->arg1, &t.arg1);
    make_booloperand(&t.arg2, "true");
    t.result.type = label_a;
    t.result.val = nextinstructionlabel() + 4;
    emit(t);
    
    make_operand(quad->arg2, &t.arg1);
    t.result.val = nextinstructionlabel() + 3;
    
    t.opcode = assign_v;
    make_booloperand(&t.arg1, "false");
    reset_operand(&t.arg2);
    make_operand(quad->result, &t.result);
    emit(t);

    t.opcode = jump_v;
    reset_operand(&t.arg1);
    reset_operand(&t.arg2);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel() + 2; // Jump to the end of the or
    emit(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, "true");
    reset_operand(&t.arg2);
    make_operand(quad->result, &t.result);
    emit(t);
}

void generate_and(quad* quad) {
    quad->taddress = nextinstructionlabel();
    instruction t{};
    
    t.opcode = jeq_v;
    make_operand(quad->arg1, &t.arg1);
    make_booloperand(&t.arg2, "false");
    t.result.type = label_a;
    t.result.val = nextinstructionlabel() + 4; // Jump to the end if arg1 is false
    emit(t);
    
    make_operand(quad->arg2, &t.arg1);
    t.result.val = nextinstructionlabel() + 3; // Jump to the next instruction after arg2

    t.opcode = assign_v;
    make_booloperand(&t.arg1, "true");
    reset_operand(&t.arg2);
    make_operand(quad->result, &t.result);
    emit(t);

    t.opcode = jump_v;
    reset_operand(&t.arg1);
    reset_operand(&t.arg2);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel() + 2; // Jump to the end of the and
    emit(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, "false");
    reset_operand(&t.arg2);
    make_operand(quad->result, &t.result);
    emit(t);
}

void generate_param(quad* quad) {
    quad->taddress = nextinstructionlabel();
    instruction t{};
    t.opcode = pusharg_v;
    make_operand(quad->arg1, &t.arg1);
    emit(t);
}

void generate_call(quad* quad) {
    quad->taddress = nextinstructionlabel();
    instruction t{};
    t.opcode = call_v;
    make_operand(quad->result, &t.result);    
    reset_operand(&t.arg2);
    emit(t);
}

void generate_getretval(quad* quad) {
    quad->taddress = nextinstructionlabel();
    instruction t{};
    t.opcode = getretval_v;
    make_retvaloperand(&t.result);
    reset_operand(&t.arg1);
    reset_operand(&t.arg2);
    emit(t);
}


void generate_funcstart(quad* q) {    
    q->taddress = nextinstructionlabel();
    unsigned funcIndex = userfuncs_newfunc(q->arg1->sym);
    q->arg1->sym->taddress = funcIndex;
    funcs.push(funcIndex);
    
    instruction instr;
    instr.opcode  = funcenter_v;
    make_operand(q->arg1, &instr.result);  
    instr.srcLine = q->line;
    emit(instr);
}

void generate_funcend(quad* quad) {
    quad->taddress = nextinstructionlabel();
    instruction t{};
    userfunc uf = userFuncs[funcs.top()];
    funcs.pop();
    uf.id = quad->arg1->sym->name;
    uf.address = nextinstructionlabel();
    uf.localSize = quad->arg1->sym->totalLocals;
    userfuncs_newfunc(quad->arg1->sym);
    t.opcode = funcexit_v;
    make_operand(quad->arg1, &t.result);
    uf.address = t.result.val;
    quad->arg1->sym->taddress = uf.address; // Update the taddress in the symbol table
    t.srcLine = quad->line;
    t.result.type = userfunc_a;
    userFuncs.push_back(uf);
    emit(t);
}

void generate_return(quad* quad) {
    quad->taddress = nextinstructionlabel();
    instruction t{};
    t.opcode = assign_v;
    
    make_retvaloperand(&t.result);
    make_operand(quad->arg1, &t.arg1);
    emit(t);
}


typedef void (*generator_func_t)(quad*);

static generator_func_t generators[] = {
    generate_assign,     // assign_v       = 0
    generate_add,        // add_v          = 1
    generate_sub,        // sub_v          = 2
    generate_mul,        // mul_v          = 3
    generate_div,        // div_v          = 4
    generate_mod,        // mod_v          = 5
    generate_uminus,     // uminus_v       = 6
    generate_and,        // and_v          = 7
    generate_or,         // or_v           = 8
    generate_not,        // not_v          = 9
    generate_ifeq,       // jeq_v          = 10
    generate_ifne,       // jne_v          = 11
    generate_ifle,       // jle_v          = 12
    generate_ifge,       // jge_v          = 13
    generate_iflt,       // jlt_v          = 14
    generate_ifgt,       // jgt_v          = 15
    generate_jump,       // jump_v         = 24
    generate_call,       // call_v         = 16
    generate_param,      // pusharg_v      = 17
    generate_return,     // ret_v          = 26
    generate_getretval,   // getretval_v    = 25
    generate_funcstart,  // funcenter_v    = 18
    generate_funcend,    // funcexit_v     = 19
    generate_newtable,   // newtable_v     = 20
    generate_getelem,    // tablegetelem_v = 21
    generate_setelem,    // tablesetelem_v = 22
    generate_nop        // nop_v          = 23
};

static_assert(sizeof(generators)/sizeof(*generators) == 27,
              "generators[] size must match vmopcode count");


static const char *vmopcodeNames[] = {
    "assign", "add",  "sub",  "mul",  "div",  "mod",  "uminus",
    "and",    "or",   "not",  "jeq",  "jne",  "jle",  "jge",
    "jlt",    "jgt",  "jump", "call", "pusharg", "return", "getretval", "funcenter","funcexit",
    "newtable","tablegetelem","tablesetelem","nop"
};

static std::string argToString(const vmarg &a) {
    return std::to_string(a.type) + "(" + std::to_string(a.val) + ")";
}

void generate_and_print_instructions() {
    instructions.clear();
    jumps.clear();
    for (auto &q : quads) {
        q->taddress = 0;
    }

    for (unsigned i = 0; i < quads.size(); ++i) {
        currProcessedQuad = i;
        quad *q = quads[i];
        auto gen = generators[q->op];
        if (gen) {
            gen(q);
        } else {
            std::cerr << "Error: No generator for opcode " << q->op << " at quad index " << i << "\n";
            continue;
        }
    }

    patch_incomplete_jumps();


    std::cout << " # | opcode          | result        | arg1          | arg2          | srcLine\n";
    std::cout << "-------------------------------------------------------------------------------\n";

    for (unsigned i = 0; i < instructions.size(); ++i) {
        const auto &ins = instructions[i];
        // opcode name (safely bound by array size)
        const char *name = (ins.opcode < sizeof(vmopcodeNames)/sizeof(*vmopcodeNames))
                            ? vmopcodeNames[ins.opcode]
                            : "??";
        std::cout << std::setw(2) << i << " | "
                  << std::left << std::setw(15) << name << " | "
                  << std::setw(13) << argToString(ins.result) << " | "
                  << std::setw(13) << argToString(ins.arg1)   << " | "
                  << std::setw(13) << argToString(ins.arg2)   << " | "
                  << ins.srcLine
                  << "\n";
    }
}

void write_binary(const std::string &fileName) {
  std::ofstream out(fileName, std::ios::binary);
  // 1) magic
  uint32_t mag = MAGIC_NUMBER;
  out.write((char*)&mag, sizeof(mag));
  // 2) strings
  uint32_t sc = stringConsts.size();
  out.write((char*)&sc, sizeof(sc));
  for (auto &s : stringConsts) {
    uint32_t len = s.size();
    out.write((char*)&len, sizeof(len));
    out.write(s.c_str(), len+1);
  }
  // 3) numbers
  uint32_t nc = numConsts.size();
  out.write((char*)&nc, sizeof(nc));
  for (double d : numConsts)
    out.write((char*)&d, sizeof(d));
  // 4) userfuncs
  uint32_t uc = userFuncs.size();
  out.write((char*)&uc, sizeof(uc));
  for (auto &uf : userFuncs) {
    out.write((char*)&uf.address,   sizeof(uf.address));
    out.write((char*)&uf.localSize, sizeof(uf.localSize));
    uint32_t l = uf.id.size();
    out.write((char*)&l, sizeof(l));
    out.write(uf.id.c_str(), l+1);
  }
  // 5) libfuncs
  uint32_t lc = namedLibFuncs.size();
  out.write((char*)&lc, sizeof(lc));
  for (auto &lf : namedLibFuncs) {
    uint32_t l = lf.size();
    out.write((char*)&l, sizeof(l));
    out.write(lf.c_str(), l+1);
  }
  // 6) code
  uint32_t ic = instructions.size();
  out.write((char*)&ic, sizeof(ic));
  for (auto &ins : instructions) {
    out.put((char)ins.opcode);
    out.put((char)ins.result.type);
    out.write((char*)&ins.result.val, sizeof(ins.result.val));
    out.put((char)ins.arg1.type);
    out.write((char*)&ins.arg1.val, sizeof(ins.arg1.val));
    out.put((char)ins.arg2.type);
    out.write((char*)&ins.arg2.val, sizeof(ins.arg2.val));
    // (omit srcLine—it’s only for debugging)
  }
}
