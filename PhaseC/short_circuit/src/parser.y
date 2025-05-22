%define         parse.error     verbose
%define         parse.trace   
%locations

%{
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <vector>

#include "../src/include/backpatch.hpp"
#include "../src/include/expr.hpp"
#include "../src/include/symTable.hpp"
#include "../src/include/quad.hpp"
#include "../src/include/temp.hpp"
#include "../src/include/types.hpp"
#include "../src/include/stmt.hpp"

extern SymbolTable symTable;
extern bool skipBlockScope;
extern int yylex();
extern char* yytext;
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
extern int loopCounter;
extern std::stack<int> loopCounterStack;
extern std::vector<quad*> quads;
int yyerror(const char* msg);

// Global variables
SymEntry* entryFuncDef = nullptr;
std::stack<unsigned int> jumpfunctag = std::stack<unsigned int>();
unsigned int jumpfromreturntag;
std::stack<std::stack<unsigned int>> returns = std::stack<std::stack<unsigned int>>();

struct expr* tempexpr1 = newexpr(arithexpr_e);
%}


%start program

%union {
        int int_val;
        float float_val;
        char *str_val;
        struct SymEntry *node;
        struct expr *expr;
        struct call *callval;
        struct indexed *indexed;
        struct stmt_t *stmtval;
        unsigned offset;
        struct forprefix *forprefix;
}


/* OPS */
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token MODULO
%token LESS_THAN
%token LESS_THAN_EQUAL
%token GREATER_THAN
%token GREATER_THAN_EQUAL
%token EQUAL
%token NOT_EQUAL
%token INCREMENT
%token DECREMENT

/* ASSIGN */
%token ASSIGN


/* Delimeters */
%token SEMICOLON
%token COMMA
%token COLON
%token DOUBLE_COLON
%token DOT
%token DOUBLE_DOT
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS
%token LEFT_BRACE
%token RIGHT_BRACE
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token UMINUS

/* Keywords */
%token IF
%token ELSE
%token WHILE
%token FOR
%token FUNCTION
%token RETURN
%token BREAK
%token CONTINUE
%token TRUE
%token FALSE
%token NIL
%token LOCAL
%token AND 
%token NOT
%token OR 

/* Constants */
%token <int_val> INTEGER;
%token <float_val> REAL
%token <str_val> STRINGT
%token <str_val> IDENTIFIER 


/* Extra Tokens */
%token ERROR_COMMENT
%token ERROR_STRING
%token ERROR_ESCAPE
%token UNDEF

%type <node>    program
%type <expr>    expr term
%type <expr>    lvalue call objectdef primary
%type <expr>    assignexpr elist member idlist errors const
%type <node>    funcprefix funcdef
  
%type <stmtval> block stmt stmt_list ifstmt whilestmt forstmt loopstmt returnstmt break continue 

%type <callval> callsuffix normcall methodcall 
%type <indexed> indexed indexedelem   
%type <str_val> funcname
%type <forprefix> forprefix
%type <int_val> whilestart whilecond loopstart loopend ifprefix elseprefix N M funcbody




%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN
%left OR
%left AND 
%nonassoc EQUAL NOT_EQUAL
%nonassoc GREATER_THAN GREATER_THAN_EQUAL LESS_THAN LESS_THAN_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT INCREMENT DECREMENT
%nonassoc UMINUS
%left DOT DOUBLE_DOT
%left LEFT_BRACKET RIGHT_BRACKET
%left LEFT_PARENTHESIS RIGHT_PARENTHESIS  
%left LEFT_BRACE RIGHT_BRACE   


%%
program: stmt_list      {       
                                fprintf(yyout, "[-] Reduced: program -> stmt_list\n");
                        }
        ;

stmt: expr SEMICOLON    {       
                                $$ = new struct stmt_t;
                                make_stmt($$);
                                resettemp();
                                if ($1->type == boolexpr_e) {
                                        backpatch($1->truelist, nextquad());
                                        backpatch($1->falselist, nextquad() + 2);
                                        emit(assign, newexpr_constbool(true), nullptr, $1, 0);
                                        emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
                                        emit(assign, newexpr_constbool(false), nullptr, $1, 0);
                                }
                                fprintf(yyout, "[-] Reduced: stmt -> expr SEMICOLON\n");
                        }

        | ifstmt        {       
                                
                                $$ = new struct stmt_t;
                                make_stmt($$);
                                resettemp();
                                fprintf(yyout, "[-] Reduced: stmt -> ifstmt\n");
                        }

        | whilestmt     {
                                resettemp();
                                $$ = new struct stmt_t;
                                make_stmt($$);
                                fprintf(yyout, "[-] Reduced: stmt -> whilestmt\n");
                        }

        | forstmt       {       
                                resettemp();
                                $$ = new struct stmt_t;
                                make_stmt($$);

                                fprintf(yyout, "[-] Reduced: stmt -> forstmt\n");
                        }

        | returnstmt    {       
                                resettemp();
                                $$ = new struct stmt_t;
                                make_stmt($$);
                                fprintf(yyout, "[-] Reduced: stmt -> returnstmt\n");
                        }

        | continue      {       
                                resettemp();
                                $$ = new struct stmt_t;
                                make_stmt($$);
                                $$ = $1;
                                fprintf(yyout, "[-] Reduced: stmt -> CCONTINUE SEMICOLON\n");
                        }

        | break    {    
                        resettemp();
                        $$ = new struct stmt_t;
                        make_stmt($$);
                        $$ = $1;
                        fprintf(yyout, "[-] Reduced: stmt -> BREAK SEMICOLON\n");
                }

        | block                 {
                                        resettemp();
                                        $$ = new struct stmt_t;
                                        make_stmt($$);
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: stmt -> block\n");
                                }

        | funcdef               {
                                        resettemp();
                                        $$ = new struct stmt_t;
                                        make_stmt($$);
                                        fprintf(yyout, "[-] Reduced: stmt -> funcdef\n");
                                }

        | SEMICOLON             {       
                                        resettemp();
                                        $$ = new struct stmt_t;
                                        make_stmt($$);
                                        fprintf(yyout, "[-] Reduced: stmt -> SEMICOLON\n");
                                }
        

        | errors                {
                                        resettemp();
                                        fprintf(yyout, "[-] Reduced: stmt -> errors\n");
                                }

        | error SEMICOLON       {       
                                        resettemp();
                                        fprintf(yyout, "      [!] Error: Illegal statement in line %d.\n", yylineno);
                                        yyerrok;
                                        yyclearin;
                                }
        
        ;

stmt_list:      stmt stmt_list  {
                                        $$ = new struct stmt_t;
                                        make_stmt($$);
                                        if (!$1 && $2) {
                                                $$->breaklist = $2->breaklist;
                                                $$->contlist = $2->contlist;
                                        } else if ($1 && !$2) {
                                                $$->breaklist = $1->breaklist;
                                                $$->contlist = $1->contlist;
                                        } else if ($1 && $2) {
                                                $$->breaklist = mergelist($2->breaklist, $1->breaklist);
                                                $$->contlist = mergelist($2->contlist, $1->contlist);
                                        }
                                        fprintf(yyout, "[-] Reduced: stmt_list -> stmt\n");
                                }

                | /* empty */           {               
                                                $$ = new struct stmt_t;
                                                make_stmt($$);
                                                fprintf(yyout, "[-] Reduced: stmt_list -> stmt_list stmt\n");
                                }

expr:   assignexpr              {
                                        fprintf(yyout, "[-] Reduced: expr -> assignexpr\n");
                                }

        | expr PLUS expr                {       
                                                tempexpr1 = emit_arith(add, $1, $3, tempexpr1);
                                                $$ = tempexpr1;
                                                fprintf(yyout, "[-] Reduced: expr -> expr PLUS expr\n");
                                        }

        | expr MINUS expr               {       
                                                tempexpr1 = emit_arith(sub, $1, $3, tempexpr1);
                                                $$ = tempexpr1;

                                                fprintf(yyout, "[-] Reduced: expr -> expr MINUS expr\n");
                                        }

        | expr MULTIPLY expr            {       
                                                tempexpr1 = emit_arith(mul, $1, $3, tempexpr1);
                                                $$ = tempexpr1;

                                                fprintf(yyout, "[-] Reduced: expr -> expr MULTIPLY expr\n");
                                        }
                                
        | expr DIVIDE expr              {       
                                                tempexpr1 = emit_arith(div_op, $1, $3, tempexpr1);
                                                $$ = tempexpr1;

                                                fprintf(yyout, "[-] Reduced: expr -> expr DIVIDE expr\n");
                                        }

        | expr MODULO expr              {       
                                                tempexpr1 = emit_arith(mod, $1, $3, tempexpr1);
                                                $$ = tempexpr1;

                                                fprintf(yyout, "[-] Reduced: expr -> expr MODULO expr\n");
                                        }

        | expr LESS_THAN expr           {

                                                $$ = emit_relop(if_less, $1, $3, $$);

                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN expr\n");
                                        }

        | expr GREATER_THAN expr        {
                                                $$ = emit_relop(if_greater, $1, $3, $$);

                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN expr\n");
                                        }

        | expr GREATER_THAN_EQUAL expr   {
                                                $$ = emit_relop(if_greatereq, $1, $3, $$);

                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN_EQUAL expr\n");
                                                }

        | expr LESS_THAN_EQUAL expr    {
                                                $$ = emit_relop(if_lesseq, $1, $3, $$);

                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN_EQUAL expr\n");
                                        }

        | expr EQUAL expr       {       
                                        checkforeqop($1, $3);

                                        if ($1->type == boolexpr_e) {
                                                backpatch($1->truelist, nextquad());
                                                backpatch($1->falselist, nextquad() + 2);
                                                emit(assign, newexpr_constbool(true), nullptr, $1, 0);
                                                emit(jump, nullptr, nullptr, nullptr, nextquad() + 3);
                                                emit(assign, newexpr_constbool(false), nullptr, $1, 0);
                                        }

                                        if ($3->type == boolexpr_e) {
                                                backpatch($3->truelist, nextquad());
                                                backpatch($3->falselist, nextquad() + 2);
                                                emit(assign, newexpr_constbool(true), nullptr, $3, 0);
                                                emit(jump, nullptr, nullptr, nullptr, nextquad() + 3);
                                                emit(assign, newexpr_constbool(false), nullptr, $3, 0);
                                        }
                                        
                                        $$ = newexpr(boolexpr_e);
                                        $$->sym = newtemp();

                                        $$->truelist.push_back(nextquad() - 1);
                                        emit(if_eq, $1, $3, nullptr, 0);
                                        $$->falselist.push_back(nextquad() - 1);
                                        emit(jump, nullptr, nullptr, nullptr, 0);

                                        fprintf(yyout, "[-] Reduced: expr -> expr EQUAL expr\n");
                                }

        | expr NOT_EQUAL expr   {       
                                        checkforeqop($1, $3);

                                        if ($1->type == boolexpr_e) {
                                                backpatch($1->truelist, nextquad());
                                                backpatch($1->falselist, nextquad() + 2);
                                                emit(assign, newexpr_constbool(true), nullptr, $1, 0);
                                                emit(jump, nullptr, nullptr, nullptr, nextquad() + 3);
                                                emit(assign, newexpr_constbool(false), nullptr, $1, 0);
                                        }

                                        if ($3->type == boolexpr_e) {
                                                backpatch($3->truelist, nextquad());
                                                backpatch($3->falselist, nextquad() + 2);
                                                emit(assign, newexpr_constbool(true), nullptr, $3, 0);
                                                emit(jump, nullptr, nullptr, nullptr, nextquad() + 3);
                                                emit(assign, newexpr_constbool(false), nullptr, $3, 0);
                                        }
                                        
                                        $$ = newexpr(boolexpr_e);
                                        $$->sym = newtemp();

                                        $$->truelist.push_back(nextquad() - 1);
                                        emit(if_noteq, $1, $3, nullptr, 0);
                                        $$->falselist.push_back(nextquad() - 1);
                                        emit(jump, nullptr, nullptr, nullptr, 0);


                                        fprintf(yyout, "[-] Reduced: expr -> expr NOT_EQUAL expr\n");
                                }                                        

        |expr AND {if ($1->type != boolexpr_e) convertToBool($1);} M expr        {       
                        
                                        if ($5->type != boolexpr_e) convertToBool($5);
                                        backpatch($1->truelist, $4);

                                        $$ = newexpr(boolexpr_e);
                                        $$->sym = newtemp();
                                        $$->truelist = $5->truelist;
                                        $$->falselist = mergelist($1->falselist, $5->falselist);

                                        fprintf(yyout, "[-] Reduced: expr -> expr AND expr\n");
                                }
        
        | expr OR {if ($1->type != boolexpr_e) convertToBool($1);} M expr        {       
                                
                                        if ($5->type != boolexpr_e) convertToBool($5);
                                        backpatch($1->falselist, $4);
                                        $$ = newexpr(boolexpr_e);
                                        $$->sym = newtemp();
                                        $$->truelist = mergelist($1->truelist, $5->truelist);
                                        $$->falselist = $5->falselist;
                                        fprintf(yyout, "[-] Reduced: expr -> expr OR expr\n");
                                }

        | term                          {       
                                                $$ = $1;
                                                fprintf(yyout, "[-] Reduced: expr -> term\n");
                                        } 
        ;


term:   LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {
                                                        $$ = $2;
                                                        fprintf(yyout, "[-] Reduced: term -> LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");
                                                }

        | MINUS expr %prec UMINUS               {
                                                        check_arith($2, "unary minus (-expr)");
                                                        $$ = newexpr(arithexpr_e);
                                                        $$->sym = istempexpr($2) ? $2->sym : newtemp();
                                                        emit(uminus, $2, nullptr, $$, 0);
                                                        fprintf(yyout, "[-] Reduced: term -> MINUS expr\n");
                                                }

        | NOT expr %prec LOWER_THAN_ELSE        {
                                                        if ($2->type != boolexpr_e) {
                                                                convertToBool($2);
                                                        }
                                                        
                                                        std::vector<unsigned int> temp = $2->truelist;
                                                        $2->truelist = $2->falselist;
                                                        $2->falselist = temp;
                                                        $$ = $2;
                                                        
                                                        fprintf(yyout, "[-] Reduced: term -> NOT expr\n");
                                                }

        | INCREMENT lvalue                      {       
                                                        check_arith($2, "increment (nonlval++)");
                                                        if ($2->type == tableitem_e) {
                                                                $$ = emit_iftableitem($2);
                                                                emit(add, $$, newexpr_constnum(1), $$, 0);
                                                                emit(tablesetelem, $2, $2->index, $$, 0);
                                                        } else {
                                                                emit(add, $2, newexpr_constnum(1), $2, 0);
                                                                $$ = newexpr(arithexpr_e);
                                                                $$->sym = newtemp();
                                                                emit(assign, $2, nullptr, $$, 0);
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> INCREMENT lvalue\n");
                                                }

        | lvalue INCREMENT                      {       
                                                        check_arith($1, "increment (nonlval++)");
                                                        $$ = newexpr(var_e);
                                                        $$->sym = newtemp();
                                                        if ($1->type == tableitem_e) {
                                                                expr* val = emit_iftableitem($1);
                                                                emit(assign, val, nullptr, $$, 0);
                                                                emit(add, val, newexpr_constnum(1), val, 0);
                                                                emit(tablesetelem, $1, $1->index, val,  0);
                                                        } else {
                                                                emit(assign, $1, nullptr, $$, 0);
                                                                emit(add, $1, newexpr_constnum(1), $1, 0);
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue INCREMENT\n");
                                                }

        | DECREMENT lvalue                      {       
                                                        check_arith($2, "decrement (nonlval--)");
                                                        if ($2->type == tableitem_e) {
                                                                $$ = emit_iftableitem($2);
                                                                emit(sub, $$, newexpr_constnum(1), $$, 0);
                                                                emit(tablesetelem, $2, $2->index, $$, 0);
                                                        } else {
                                                                emit(sub, $2, newexpr_constnum(1), $2, 0);
                                                                $$ = newexpr(arithexpr_e);
                                                                $$->sym = newtemp();
                                                                emit(assign, $2, nullptr, $$, 0);
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> DECREMENT lvalue\n");
                                                }

        | lvalue DECREMENT                      {
                                                        check_arith($1, "decrement (nonlval--)");
                                                        $$ = newexpr(var_e);
                                                        $$->sym = newtemp();
                                                        if ($1->type == tableitem_e) {
                                                                expr* val = emit_iftableitem($1);
                                                                emit(assign, val, nullptr, $$, 0);
                                                                emit(sub, val, newexpr_constnum(1), val, 0);
                                                                emit(tablesetelem, $1, $1->index, val, 0);
                                                        } else {
                                                                emit(assign, $1, nullptr, $$, 0);
                                                                emit(sub, $1, newexpr_constnum(1), $1, 0);
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue DECREMENT\n");
                                                }        
        
        | primary                               {       
                                                        $$ = $1;
                                                        fprintf(yyout, "[-] Reduced: term -> primary\n");
                                                }
        ;

assignexpr:     lvalue ASSIGN expr              {
                                                        if ($1->sym && $1->sym->type == LIBFUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc = expr) in line %d.\n", yylineno);
                                                        } else if ($1->sym && $1->sym->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func = expr) in line %d.\n", yylineno);      
                                                        } else {
                                                                
                                                                if ($3->type == boolexpr_e) {
                                                                        convertToBool($3);

                                                                        expr* result = newexpr(var_e);
                                                                        result->sym = !istempexpr($3) && $3->sym ? newtemp() : $3->sym;
                                                                        
                                                                        backpatch($3->truelist, nextquad());
                                                                        backpatch($3->falselist, nextquad() + 2);
                                                                        emit(assign, newexpr_constbool(true), nullptr, result, 0);
                                                                        emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
                                                                        emit(assign, newexpr_constbool(false), nullptr, result, 0);

                                                                }
                                                                
                                                                if ($1->type == tableitem_e) {
                                                                        emit(tablesetelem, $1, $1->index, $3, 0);
                                                                        $$ = emit_iftableitem($1);
                                                                        $$->type = assignexpr_e;
                                                                } else {
                                                                        emit(assign, $3, nullptr, $1, 0);
                                                                        $$ = newexpr_tmpvar(assignexpr_e);
                                                                        emit(assign, $1, nullptr, $$, 0);
                                                                }

                                                        }

                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue ASSIGN expr\n");
                                                }
                ;

primary:lvalue                 {       
                                        $$ = emit_iftableitem($1);
                                        fprintf(yyout, "[-] Reduced: primary -> lvalue\n");
                                }

        | call                  {       
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: primary -> call\n");
                                }

        | objectdef             {       
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: primary -> objectdef\n");
                                }

        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS    {       
                                                                $$ = newexpr(programfunc_e);
                                                                $$->sym = $2;
                                                                fprintf(yyout, "[-] Reduced: primary -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS\n");
                                                        }
        | const                 {
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: primary -> const\n");
                                }
        ;

lvalue: IDENTIFIER              {
                                        SymEntry* found = symTable.lookup($1);

                                        if (!found) {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = $1;
                                                entry->type = VAR;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;
                                                entry->isGlobal = (entry->scope == 0);

                                                symTable.insert(entry);
                                                $$ = lvalue_expr(symTable.lookup($1));
                                        } else {    
                                                if (found->type == LIBFUNC) {
                                                        $$ = newexpr(libraryfunc_e);
                                                        $$->sym = found;
                                                } else if (found->type == FUNC) {
                                                        $$ = newexpr(programfunc_e);
                                                        $$->sym = found;
                                                } else if (found->type == VAR || found->type == FORARG) {
                                                        if (symTable.funcStack.empty()) {
                                                                $$ = lvalue_expr(found);
                                                        } else {
                                                                if ((found->scope > symTable.funcStack.top()->scope && found->isActive) || found->scope == 0) {
                                                                        $$ = lvalue_expr(found);
                                                                } else {
                                                                     fprintf(yyout, "      [!] Error: Variable %s is not accessible in line %d.\n", $1, yylineno);
                                                                }
                                                        }
                                                }
                                        }

                                        fprintf(yyout, "[-] Reduced: lvalue -> IDENTIFIER\n");
                                }

        | LOCAL IDENTIFIER      {       
                                        SymEntry* found = symTable.lookup($2, 0);
                                        if ((found) && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Local variable is shadowing library function in line %d.\n", yylineno);
                                                $$ = newexpr(nil_e);
                                        } else if (!found || found->type != LIBFUNC) {
                                        
                                                found = symTable.lookup($2, symTable.getScope());

                                                if (!found) {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = $2;
                                                        entry->type = VAR;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;

                                                        entry->isGlobal = false;

                                                        symTable.insert(entry);
                                                        $$ = lvalue_expr(symTable.lookup($2));
                                                
                                                } else if (found->type == FUNC) {
                                                        fprintf(yyout, "      [!] Warning: Local variable is shadowing function in line %d.\n", yylineno);
                                                }

                                                
                                        } 
                                        fprintf(yyout, "[-] Reduced: lvalue -> LOCAL IDENTIFIER\n");
                                }

        | DOUBLE_COLON IDENTIFIER       {       
                                                SymEntry* found = symTable.lookup($2, 0);
                                                if (!found) {
                                                        fprintf(yyout, "      [!] Error: Token %s has not been declared in global scope in line %d.\n", $2, yylineno);
                                                        $$ = newexpr(nil_e);
                                                } else if (found->type == LIBFUNC) {
                                                        $$ = newexpr(libraryfunc_e);
                                                        $$->sym = found;
                                                } else if (found->type == FUNC) {
                                                        $$ = newexpr(programfunc_e);
                                                        $$->sym = found;
                                                } else if (found->type == VAR) {
                                                        $$ = lvalue_expr(found);
                                                } else {
                                                        fprintf(yyout, "      [!] Warning: Unexpected symbol type in line %d.\n", yylineno);
                                                        $$ = lvalue_expr(found);
                                                }
                                                fprintf(yyout, "[-] Reduced: lvalue -> DOUBLE_COLON IDENTIFIER\n");
                                        }

        | member                        {       
                                                $$ = $1;
                                                fprintf(yyout, "[-] Reduced: lvalue -> member\n");
                                        }
        ;

member: lvalue DOT IDENTIFIER   {       
                                        $$ = member_item($1, $3);
                                        fprintf(yyout, "[-] Reduced: member -> lvalue DOT IDENTIFIER\n");
                                }

        | lvalue LEFT_BRACKET expr RIGHT_BRACKET        { 
                                                                $1 = emit_iftableitem($1);
                                                                $$ = newexpr(tableitem_e);
                                                                $$->sym = $1->sym;
                                                                $$->index = $3;
                                                                fprintf(yyout, "[-] Reduced: member -> lvalue LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }

        | call DOT IDENTIFIER                           {       
                                                                $$ = member_item($1, $3);
                                                                fprintf(yyout, "[-] Reduced: member -> call DOT IDENTIFIER\n");
                                                        }

        | call LEFT_BRACKET expr RIGHT_BRACKET          {
                                                                fprintf(yyout, "[-] Reduced: member -> call LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        } 
        ;

call:   call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS   {     
                                                                $$ = make_call($1, $3); 
                                                                fprintf(yyout, "[-] Reduced: call -> call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }

        | lvalue callsuffix                             {
                                                                $1 = emit_iftableitem($1);

                                                                if ($2->method) {
                                                                        expr* temp = $1;
                                                                        $1 = emit_iftableitem(member_item(temp, $2->name));
                                                                        $2->elist->next = temp;
                                                                }
                                                                $$ = make_call($1, $2->elist);
                                                                fprintf(yyout, "[-] Reduced: call -> lvalue callsuffix\n");
                                                        }

        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS   {
                                                                                                        struct expr* func = newexpr(programfunc_e);
                                                                                                        func->sym = $2;
                                                                                                        $$ = make_call(func, $5);
                                                                                                        fprintf(yyout, "[-] Reduced: call -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                }
        ;

callsuffix: normcall            {
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: callsuffix -> normcall\n");
                                }

            | methodcall        {
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: callsuffix -> methodcall\n");
                                }
            ;

normcall:   LEFT_PARENTHESIS elist RIGHT_PARENTHESIS    {       
                                                                $$ = new struct call;
                                                                $$->elist = $2;
                                                                $$->method = 0;
                                                                $$->name = "";
                                                                fprintf(yyout, "[-] Reduced: normcall -> LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
            ;

methodcall: DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS      {       
                                                                                        $$ = new struct call;
                                                                                        $$->elist = $4;
                                                                                        $$->method = 1;
                                                                                        $$->name = $2;
                                                                                        fprintf(yyout, "[-] Reduced: methodcall -> DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                }
            ;

elist: expr                     {       
                                        if ($1->type == boolexpr_e) {
                                                backpatch($1->truelist, nextquad());
                                                backpatch($1->falselist, nextquad() + 2);
                                                emit(assign, newexpr_constbool(true), nullptr, $1, 0);
                                                emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
                                                emit(assign, newexpr_constbool(false), nullptr, $1, 0);
                                        }
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: elist -> expr\n");
                                }

        | elist COMMA expr      {       
                                        if ($3->type == boolexpr_e) {
                                                backpatch($3->truelist, nextquad());
                                                backpatch($3->falselist, nextquad() + 2);
                                                emit(assign, newexpr_constbool(true), nullptr, $3, 0);
                                                emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
                                                emit(assign, newexpr_constbool(false), nullptr, $3, 0);
                                        }
                                        $3->next = $1;
                                        $$ = $3;
                                        fprintf(yyout, "[-] Reduced: elist -> expr COMMA elist\n");
                                }

        | /* empty */           {       
                                        $$ = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> /* empty */\n");
                                }
        ;

objectdef: LEFT_BRACKET elist RIGHT_BRACKET     {       
                                                        expr* obj = newexpr(newtable_e);
                                                        obj->sym = newtemp();
                                                        emit(tablecreate, obj, nullptr, nullptr, 0);
                                                        expr* curr = reverse($2);
                                                        for (int i = 0; curr; curr = curr->next) {
                                                                
                                                                emit(tablesetelem, obj, newexpr_constnum(i++), curr, 0);
                                                        }
                                                        $$ = obj;
                                                        fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET elist RIGHT_BRACKET\n");
                                                }

        | LEFT_BRACKET indexed RIGHT_BRACKET    {       
                                                        expr* obj = newexpr(newtable_e);
                                                        obj->sym = newtemp();
                                                        emit(tablecreate, obj, nullptr, nullptr, nextquad());
                                                        indexed* p = $2;
                                                        for (int i = 0; p; p = p->next) {
                                                                emit(tablesetelem, obj, p->index, p->value, 0);
                                                        }
                                                        $$ = obj;
                                                        fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET indexed RIGHT_BRACKET\n");
                                                }
        ;

indexed: indexedelem                            {
                                                        $$ = $1;
                                                        fprintf(yyout, "[-] Reduced: indexed -> indexedelem\n");
                                                }

        | indexedelem COMMA indexed            {
                                                        $1->next = $3;
                                                        $$ = $1;
                                                        fprintf(yyout, "[-] Reduced: indexed -> indexed COMMA indexedelem\n");
                                                }
        ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE     {       
                                                                if ($2->type == boolexpr_e) {
                                                                        backpatch($2->truelist, nextquad());
                                                                        backpatch($2->falselist, nextquad() + 2);
                                                                        emit(assign, newexpr_constbool(true), nullptr, $2, 0);
                                                                        emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
                                                                        emit(assign, newexpr_constbool(false), nullptr, $2, 0);
                                                                }
                                                                if ($4->type == boolexpr_e) {
                                                                        backpatch($4->truelist, nextquad());
                                                                        backpatch($4->falselist, nextquad() + 2);
                                                                        emit(assign, newexpr_constbool(true), nullptr, $4, 0);
                                                                        emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
                                                                        emit(assign, newexpr_constbool(false), nullptr, $4, 0);
                                                                }
                                                                indexed* i = new indexed;
                                                                i->index = $2;
                                                                i->value = $4;
                                                                i->next = nullptr;
                                                                $$ = i;
                                                                fprintf(yyout, "[-] Reduced: indexedelem -> LEFT_BRACE expr COLON expr RIGHT_BRACE\n");
                                                        }
            ;

block: LEFT_BRACE       { 
                                if (skipBlockScope) {
                                        skipBlockScope = false;
                                } else {
                                        symTable.enter_scope();
                                }
                        } stmt_list RIGHT_BRACE {      
                                                        symTable.exit_scope();
                                                        $$ = new struct stmt_t;
                                                        make_stmt($$);
                                                        if ($stmt_list) $$ = $stmt_list;
                                                        fprintf(yyout, "[-] Reduced: block -> LEFT_BRACE stmt_list RIGHT_BRACE\n");
                                                }
        ;

funcblockstart: /* ε */ {
                                loopCounterStack.push(loopCounter);
                                loopCounter = 0;
                        }

funcblockend:   /* ε */ {
                                loopCounter = loopCounterStack.top();
                                loopCounterStack.pop();
                        }

funcname: IDENTIFIER            {       
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: funcname -> IDENTIFIER\n");
                                }

        | /* empty */           {       
                                        char* temp = strdup(generateAnonymousName().c_str());
                                        $$ = temp;
                                        fprintf(yyout, "[-] Reduced: funcname -> /* empty */\n");
                                }
        ;

funcprefix: FUNCTION funcname   {       
                                        SymEntry *found = symTable.lookup($2, 0);

                                        if(found && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Function shadowing library function in line %d.\n", yylineno);
                                        } else {
                                                found = symTable.lookup($2, symTable.getScope());

                                                if (!found) {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = $2;
                                                        entry->type = FUNC;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;
                                                        entry->isGlobal = (entry->scope == 0);

                                                        symTable.insert(entry);
                                                        entry->args.clear();
                                                        symTable.funcStack.push(entry);

                                                        $$ = symTable.lookup($2, symTable.getScope());
                                                        $$->iaddress = nextquad();
                                                        jumpfunctag.push(nextquad());
                                                        emit(jump, nullptr, nullptr, nullptr, 0);
                                                        emit(funcstart, lvalue_expr($$), nullptr, nullptr, 0);
                                                        symTable.scopeOffsetStack.push(symTable.currScopeOffset());
                                                        symTable.enterScopeSpace();
                                                        symTable.resetFormalsOff();

                                                        /* initializing the return stack */
                                                        returns.push(std::stack<unsigned int>());
                                                } else {
                                                        if (found->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Function %s already declared in line %d.\n", $2, yylineno);
                                                        }
                                                        
                                                        if (found->type == VAR) {
                                                                fprintf(yyout, "      [!] Error: Function %s is shadowing variable in line %d.\n", $2, yylineno);
                                                        }
                                                        
                                                        if (found->type == FORARG) {
                                                                fprintf(yyout, "      [!] Error: Function %s is shadowing formal argument in line %d.\n", $2, yylineno);
                                                        }
                                                }

                                                symTable.enter_scope();
                                                skipBlockScope = true;
                                                entryFuncDef = $$;
                                        }
                                }

funcargs: LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS   {
                                                        fprintf(yyout, "           hi hi \n");
                                                        symTable.enterScopeSpace();
                                                        symTable.resetFuncLocalsOff();
                                                        fprintf(yyout, "[-] Reduced: funcargs -> LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                }
        ;

funcbody: block {       
                        fprintf(yyout, "[-]                        hi hi hi \n");
                        $$ = symTable.currScopeOffset();
                        symTable.exitScopeSpace();
                }

funcdef: funcprefix funcargs funcblockstart funcbody funcblockend {
                                                if (!symTable.funcStack.empty()) {
                                                        symTable.funcStack.pop();
                                                }
                                                symTable.exitScopeSpace();
                                                $1->totalLocals = $4;
                                                int offset = symTable.top_pop(symTable.scopeOffsetStack);
                                                symTable.restoreCurrScopeOffset(offset);
                                                $$ = $1;
                                                /* patching return jumps from returns.top*/
                                                while (!returns.top().empty()) {
                                                        patchlabel(returns.top().top(), nextquad());
                                                        returns.top().pop();
                                                }
                                                if (returns.top().empty()) {
                                                        returns.pop();
                                                }
                                                emit(funcend, lvalue_expr($1), nullptr, nullptr, 0);
                                                if (!jumpfunctag.empty()) {
                                                        patchlabel(jumpfunctag.top(), nextquad());
                                                        jumpfunctag.pop();
                                                }

                                        }
        
const:  INTEGER         {       
                                struct expr* e = newexpr_constnum(yylval.int_val);
                                $$ = e;
                                fprintf(yyout, "[-] Reduced: const -> INTEGER\n");
                        }

        | REAL          {       
                                struct expr* e = newexpr_constnum(yylval.float_val);
                                $$ = e;
                                fprintf(yyout, "[-] Reduced: const -> REAL\n");
                        }
        
        | STRINGT       {       
                                struct expr* e = newexpr_conststring(yylval.str_val);
                                $$ = e;
                                fprintf(yyout, "[-] Reduced: const -> STRING\n");
                        }

        | TRUE          {       
                                struct expr* e = newexpr_constbool(true);
                                $$ = e;
                                fprintf(yyout, "[-] Reduced: const -> TRUE\n");
                        }

        | FALSE         {       
                                struct expr* e = newexpr_constbool(false);
                                $$ = e;
                                fprintf(yyout, "[-] Reduced: const -> FALSE\n");
                        }

        | NIL           {
                                struct expr* e = newexpr(nil_e);
                                $$ = e;
                                fprintf(yyout, "[-] Reduced: const -> NIL\n");
                        }
        ;

idlist: IDENTIFIER      {       
                                SymEntry* found = symTable.lookup($1, 0);

                                if ((found) && found->type == LIBFUNC) {
                                        fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.\n", yylineno);

                                        $$ = newexpr(nil_e);
                                } else {
                                        found = symTable.lookup($1, symTable.getScope());
                                        if (found) {
                                                if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.\n", yylineno);
                                        } else {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = $1;
                                                entry->type = FORARG;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;
                                                entry->isGlobal = false;
                                                
                                                entry->space = symTable.currScopeSpace();
                                                entry->offset = symTable.currScopeOffset();
                                                symTable.incCurrScopeOffset();

                                                symTable.insert(entry);

                                                if (!symTable.funcStack.empty() && symTable.funcStack.top()->scope == (symTable.lookup($1, symTable.getScope())->scope - 1)) {
                                                        symTable.funcStack.top()->args.push_back(symTable.lookup($1, symTable.getScope()));
                                                }  
                                                $$ = lvalue_expr(symTable.lookup($1));
                                        }
                                }
                                fprintf(yyout, "[-] Reduced: idlist -> IDENTIFIER\n");
                        }
        | idlist COMMA IDENTIFIER  {   
                                        SymEntry* found = symTable.lookup($3, 0);

                                        if ((found) && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.\n", yylineno);
                                        } else {
                                                if ((found = symTable.lookup($3, symTable.getScope()))) {
                                                        if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.\n", yylineno);
                                                        $$ = lvalue_expr(found);
                                                } else {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = $3;
                                                        entry->type = FORARG;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;

                                                        entry->isGlobal = entry->scope == 0 ? true : false;
                                                        entry->space = symTable.currScopeSpace();
                                                        entry->offset = symTable.currScopeOffset();
                                                        symTable.incCurrScopeOffset();

                                                        symTable.insert(entry);

                                                        if (!symTable.funcStack.empty() && symTable.funcStack.top()->scope == (symTable.lookup($3, symTable.getScope()))->scope - 1) {
                                                                symTable.funcStack.top()->args.push_back(symTable.lookup($3, symTable.getScope()));
                                                        }  
                                                        $$ = lvalue_expr(symTable.lookup($3, symTable.getScope()));
                                                        
                                                }
                                        }
                                        fprintf(yyout, "[-] Reduced: idlist -> idlist COMMA IDENTIFIER\n");
                                    }
        | /* empty */       {       
                                        $$ = nullptr;
                                        fprintf(yyout, "[-] Reduced: idlist -> /* empty */\n");
                                }
        ;

ifprefix: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS    {
                                                                if ($3->type == boolexpr_e) {
                                                                        backpatch($3->truelist, nextquad());
                                                                        backpatch($3->falselist, nextquad() + 2);
                                                                        emit(assign, newexpr_constbool(true), nullptr, $3, 0);
                                                                        emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
                                                                        emit(assign, newexpr_constbool(false), nullptr, $3, 0);
                                                                }
                                                                emit(if_eq, $3, newexpr_constbool(true), nullptr, nextquad() + 2);
                                                                $$ = nextquad();
                                                                emit(jump, nullptr, nullptr, nullptr, 0);    
                                                        }

elseprefix: ELSE        {
                                $$ = nextquad();
                                emit(jump, nullptr, nullptr, nullptr, 0);
                        }


ifstmt: ifprefix stmt %prec LOWER_THAN_ELSE {
                                patchlabel($1, nextquad());
                                fprintf(yyout, "[-] Reduced: ifstmt -> IF (...) stmt\n");
                        }

        | ifprefix stmt elseprefix stmt {
                                                patchlabel($1, $3 + 1);
                                                patchlabel($3, nextquad());
                                                fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt\n");
                                        }
        ;

loopstart: /* ε*/      {
                                ++loopCounter;
                                fprintf(yyout, "[-] Reduced: loopstart -> /* ε */\n");
                        }

loopend:   /* ε*/       {
                                --loopCounter;
                                fprintf(yyout, "[-] Reduced: loopend -> /* ε */\n");
                        }
loopstmt: loopstart stmt loopend        {       
                                                $$ = new struct stmt_t;
                                                make_stmt($$); 
                                                if ($2) {
                                                        $$->breaklist = $2->breaklist;
                                                        
                                                        $$->contlist = $2->contlist;
                                                }
                                                fprintf(yyout, "[-] Reduced: loopstmt -> stmt\n");
                                        }

whilestart: WHILE       {
                                $$ = nextquad();
                        }

whilecond: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS      {       
                                                                if ($2->type == boolexpr_e) {

                                                                        backpatch($2->truelist, nextquad());
                                                                        backpatch($2->falselist, nextquad() + 2);
                                                                        emit(assign, newexpr_constbool(true), nullptr, $2, 0);
                                                                        emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
                                                                        emit(assign, newexpr_constbool(false), nullptr, $2, 0);
                                                                }
                                                                emit(if_eq, $2, newexpr_constbool(true), nullptr, nextquad() + 2);
                                                                $$ = nextquad();
                                                                emit(jump, nullptr, nullptr, nullptr, 0);

                                                        }

whilestmt: whilestart whilecond loopstmt    {
                                                emit(jump, nullptr, nullptr, nullptr, $1);
                                                patchlabel($2, nextquad());
                                                patchlist($3->breaklist, nextquad());
                                                patchlist($3->contlist, $1);
                                                fprintf(yyout, "[-] Reduced: whilestmt -> WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                        }
        ;

N :     {
                $$ = nextquad();
                emit(jump, nullptr, nullptr, nullptr, 0);
        }
;

M :     {
                $$ = nextquad();
        }
;

forprefix: FOR LEFT_PARENTHESIS  elist SEMICOLON M expr SEMICOLON       {       
                                                                                $$ = new struct forprefix;
                                                                                $$->test = $5;
                                                                                $$->enter = nextquad();
                                                                                if ($3->type == boolexpr_e) {                                                                                        
                                                                                        backpatch($3->truelist, nextquad());
                                                                                        backpatch($3->falselist, nextquad() + 2);
                                                                                        emit(assign, newexpr_constbool(true), nullptr, $3, 0);
                                                                                        emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
                                                                                        emit(assign, newexpr_constbool(false), nullptr, $3, 0);

                                                                                }
                                                                                emit(if_eq, $6, newexpr_constbool(true), nullptr, 0);
                                                                        }
;
                                                                

forstmt: forprefix N elist RIGHT_PARENTHESIS N loopstmt N   {
                                                                patchlabel($1->enter, $5 + 1);
                                                                patchlabel($2, nextquad());
                                                                patchlabel($5, $1->test);
                                                                patchlabel($7, $2 + 1);

                                                                patchlist($6->breaklist, nextquad());
                                                                patchlist($6->contlist, $2 + 1);

                                                                fprintf(yyout, "[-] Reduced: forstmt -> FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON N elist RIGHT_PARENTHESIS N stmt M\n");
                                                        }
        ;

break: BREAK SEMICOLON {
                                $$ = new struct stmt_t;
                                make_stmt($$);
                                if (loopCounter == 0) {
                                        fprintf(yyout, "      [!] Error: Break statement outside loop in line %d.\n", yylineno);
                                } else {
                                        emit(jump, nullptr, nullptr, nullptr, 0);
                                        $$->breaklist = newlist(nextquad()- 1);
                                }
                                fprintf(yyout, "[-] Reduced: break -> BREAK SEMICOLON\n");
                        }

continue: CONTINUE SEMICOLON    {
                                        $$ = new struct stmt_t;
                                        make_stmt($$);
                                        if (loopCounter == 0) {
                                                fprintf(yyout, "      [!] Error: Continue statement outside loop in line %d.\n", yylineno);
                                        } else {
                                                emit(jump, nullptr, nullptr, nullptr, 0);
                                                $$->contlist = newlist(nextquad() - 1);
                                        }
                                }

returnstmt: RETURN expr SEMICOLON       {       
                                                if (symTable.funcStack.empty()) {
                                                        fprintf(yyout, "      [!] Error: Return statement outside function in line %d.\n", yylineno);
                                                } else {
                                                        if ($2->type == boolexpr_e) {
                                                                backpatch($2->truelist, nextquad());
                                                                backpatch($2->falselist, nextquad() + 2);
                                                                emit(assign, newexpr_constbool(true), nullptr, $2, 0);
                                                                emit(jump, nullptr, nullptr, nullptr, nextquad() + 2);
                                                                emit(assign, newexpr_constbool(false), nullptr, $2, 0);
                                                        }
                                                        emit(getretval, nullptr, nullptr, $2, 0);
                                                        returns.top().push(nextquad());
                                                        emit(jump, nullptr, nullptr, nullptr, 0);
                                                }
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN expr SEMICOLON\n");
                                        }
            | RETURN SEMICOLON          {
                                                if (symTable.funcStack.empty()) {
                                                        fprintf(yyout, "      [!] Error: Return statement outside function in line %d.\n", yylineno);
                                                } else {
                                                        emit(getretval, nullptr, nullptr, nullptr, 0);
                                                        returns.top().push(nextquad());
                                                        emit(jump, nullptr, nullptr, nullptr, 0);
                                                }
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN SEMICOLON\n");
                                        }
            ;

errors: ERROR_COMMENT   {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_COMMENT\n");
                                fprintf(yyout, "      [!] Error: Invalid comment in line %d.\n", yylineno);
                                exit(1);
                        }

        | ERROR_STRING  {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_STRING\n");
                                fprintf(yyout, "      [!] Error: Invalid string in line %d.\n", yylineno);
                                exit(1);
                        }

        | ERROR_ESCAPE  {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_ESCAPE\n");
                                fprintf(yyout, "      [!] Error: Invalid escape sequence in line %d.\n", yylineno);
                                exit(1);
                        }

        | UNDEF         {
                                fprintf(yyout, "[-] Reduced: errors -> UNDEF\n");
                                fprintf(yyout, "      [!] Error: Undefined variable in line %d.\n", yylineno);    
                                exit(1);
                        }
        ;
%%

int yyerror(const char *msg) {
    fprintf(stderr, "      [Line %d] Syntax error: %s (near token: \"%s\")\n", yylineno, msg, yytext);
    return 0;
}
