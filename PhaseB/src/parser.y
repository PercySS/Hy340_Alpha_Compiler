%define         parse.error     verbose
%define         parse.trace   
%locations

%{
#include <iostream>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <vector>

#include "../src/symtable.hpp"

extern SymbolTable symTable;
extern bool skipBlockScope;
extern int rabbitHole;
extern int yylex();
extern char* yytext;
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
int yyerror(const char* msg);

// Global variables
SymEntry* entryFuncDef = nullptr;
%}


%start program

%union {
    int int_val;
    float float_val;
    char* str_val;
    struct SymEntry* node;
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
%token PLUS_ASSIGN
%token MINUS_ASSIGN


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


%type <node> expr term
%type <node> lvalue call primary objectdef
%type <node> assignexpr
%type <node> callsuffix normcall methodcall
%type <node> elist indexed indexedelem block funcdef returnstmt ifstmt whilestmt forstmt member
%type <node> idlist
%type <node> errors
%type <node> const program stmt_list stmt


%nonassoc ELSE
%nonassoc LOWER_THAN_ELSE

%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN
%left OR
%left AND 
%nonassoc EQUAL NOT_EQUAL
%nonassoc GREATER_THAN GREATER_THAN_EQUAL LESS_THAN LESS_THAN_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT INCREMENT DECREMENT UMINUS
%left DOT DOUBLE_DOT
%left LEFT_BRACKET RIGHT_BRACKET
%left LEFT_PARENTHESIS RIGHT_PARENTHESIS  
%left LEFT_BRACE RIGHT_BRACE


%%
program: stmt_list      {       
                                $$ = $1;
                                fprintf(yyout, "[-] Reduced: program -> stmt_list\n");
                        }
        ;

stmt: expr SEMICOLON    {
                                fprintf(yyout, "[-] Reduced: stmt -> expr SEMICOLON\n");
                        }

        | ifstmt        {
                                $$ = $1;
                                fprintf(yyout, "[-] Reduced: stmt -> ifstmt\n");
                        }

        | whilestmt     {
                                $$ = $1;
                                fprintf(yyout, "[-] Reduced: stmt -> whilestmt\n");
                        }

        | forstmt       {
                                $$ = $1;
                                fprintf(yyout, "[-] Reduced: stmt -> forstmt\n");
                        }

        | returnstmt    {
                                if (symTable.funcStack.empty()) fprintf(yyout, "      [!] Error: Return statement outside of function in line %d.\n", yylineno);
                                $$ = $1;
                                fprintf(yyout, "[-] Reduced: stmt -> returnstmt\n");
                        }

        | BREAK SEMICOLON       {       
                                        if (rabbitHole < 1)  fprintf(yyout, "      [!] Error: Break statement outside of loop in line %d.\n", yylineno);
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: stmt -> BREAK SEMICOLON\n");
                                }

        | CONTINUE SEMICOLON    {       
                                        if (rabbitHole < 1) fprintf(yyout, "      [!] Error: Continue statement outside of loop in line %d.\n", yylineno);
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: stmt -> CONTINUE SEMICOLON\n");
                                }

        | block                 {       
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: stmt -> block\n");
                                }

        | funcdef               {
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: stmt -> funcdef\n");
                                }

        | SEMICOLON             {
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: stmt -> SEMICOLON\n");
                                }

        | errors                {
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: stmt -> errors\n");
                                }

        
        | error SEMICOLON       {       
                                        fprintf(yyout, "      [!] Error: Illegal statement in line %d.\n", yylineno);
                                        yyerrok;
                                        yyclearin;
                                }
        
        ;
    
stmt_list:  stmt stmt_list      {
                                        $$ = nullptr;
                                        fprintf(yyout, "[-] Reduced: stmt_list -> stmt stmt_list\n");
                                }

            | /* empty */       {       
                                        $$ = nullptr;    
                                        fprintf(yyout, "[-] Reduced: stmt_list -> /* empty */\n");
                                }
            ;

expr:   assignexpr              {       
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: expr -> assignexpr\n");
                                }

        | expr PLUS expr        {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: expr -> expr PLUS expr\n");
                                }

        | expr MINUS expr       {
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: expr -> expr MINUS expr\n");
                                }

        | expr MULTIPLY expr    {
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: expr -> expr MULTIPLY expr\n");
                                }

        | expr DIVIDE expr      {
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: expr -> expr DIVIDE expr\n");
                                }

        | expr MODULO expr      {
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: expr -> expr MODULO expr\n");
                                }

        | expr GREATER_THAN expr        {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                $$ = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN expr\n");
                                        }

        | expr LESS_THAN expr           {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                $$ = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN expr\n");
                                        }

        | expr GREATER_THAN_EQUAL expr  {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                $$ = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN_EQUAL expr\n");
                                        }

        | expr LESS_THAN_EQUAL expr     {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                $$ = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN_EQUAL expr\n");
                                        }

        | expr EQUAL expr               {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                $$ = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr EQUAL expr\n");
                                        }

        | expr NOT_EQUAL expr           {       
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                $$ = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr NOT_EQUAL expr\n");
                                        }

        | expr AND expr                 {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                $$ = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr AND expr\n");
                                        }

        | expr OR expr                  {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                $$ = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr OR expr\n");
                                        }

        | term                          {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = NONLVAL;
                                                $$ = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> term\n");
                                        } 
        ;

term:   LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {
                                                        $$ = $2;
                                                        fprintf(yyout, "[-] Reduced: term -> LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");
                                                }

        | MINUS expr %prec UMINUS               {
                                                        $$ = $2;
                                                        fprintf(yyout, "[-] Reduced: term -> MINUS expr\n");
                                                }

        | NOT expr                              { 
                                                        $$ = $2;
                                                        fprintf(yyout, "[-] Reduced: term -> NOT expr\n");
                                                }

        | INCREMENT lvalue                      {       
                                                        if ($2->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (++libfunc) in line %d.\n", yylineno);
                                                        if ($2->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (++func) in line %d.\n", yylineno);
                                                        if ($2->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (++nonlval) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        $$ = dummy;
                                                        fprintf(yyout, "[-] Reduced: term -> INCREMENT lvalue\n");
                                                }

        | lvalue INCREMENT                      {       
                                                        if ($1->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc++) in line %d.\n", yylineno);
                                                        if ($1->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func++) in line %d.\n", yylineno);
                                                        if ($1->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval++) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        $$ = dummy;
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue INCREMENT\n");
                                                }

        | DECREMENT lvalue                      {       
                                                        if ($2->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (--libfunc) in line %d.\n", yylineno);
                                                        if ($2->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (--func) in line %d.\n", yylineno);
                                                        if ($2->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (--nonlval) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        $$ = dummy;
                                                        fprintf(yyout, "[-] Reduced: term -> DECREMENT lvalue\n");
                                                }

        | lvalue DECREMENT                      {
                                                        if ($1->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc--) in line %d.\n", yylineno);
                                                        if ($1->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func--) in line %d.\n", yylineno);
                                                        if ($1->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval--) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        $$ = dummy;
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue DECREMENT\n");
                                                }        
        
        | primary                               {       
                                                        $$ = $1;
                                                        fprintf(yyout, "[-] Reduced: term -> primary\n");
                                                }
        ;

assignexpr:     lvalue ASSIGN expr              {       
                                                        if ($1->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc = expr) in line %d.\n", yylineno);
                                                        if ($1->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func = expr) in line %d.\n", yylineno);
                                                        if ($1->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval = expr) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        $$ = dummy;
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue ASSIGN expr\n");
                                                }

                | lvalue PLUS_ASSIGN expr       {       
                                                        if ($1->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc += expr) in line %d.\n", yylineno);
                                                        if ($1->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func += expr) in line %d.\n", yylineno);
                                                        if ($1->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval += expr) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        $$ = dummy;
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue PLUS_ASSIGN expr\n");
                                                }

                | lvalue MINUS_ASSIGN expr      {
                                                        if ($1->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc -= expr) in line %d.\n", yylineno);
                                                        if ($1->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func -= expr) in line %d.\n", yylineno);
                                                        if ($1->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval -= expr) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        $$ = dummy;
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue MINUS_ASSIGN expr\n");
                                                }
                ;

primary: lvalue                 {       
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: primary -> lvalue\n");
                                }

        | call                  {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = NONLVAL;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: primary -> call\n");
                                }

        | objectdef             {       
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: primary -> objectdef\n");
                                }

        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS    {       
                                                                $$ = $2;
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
                                                entry->isGlobal = entry->scope == 0 ? true : false;
                                                symTable.insert(entry);
                                                $$ = entry;
                                        } else {    
                                                if (found->type == LIBFUNC) {
                                                        $$ = found;
                                                }

                                                if (found->type == VAR || found->type == FORARG) {
                                                        if (symTable.funcStack.empty()) {
                                                                $$ = found;
                                                        } else {
                                                                if ((found->scope > symTable.funcStack.top()->scope && found->isActive) || found->scope == 0) {
                                                                        $$ = found;
                                                                } else {
                                                                     fprintf(yyout, "      [!] Error: Variable %s is not accessible in line %d.\n", $1, yylineno); 
                                                                }
                                                        }
                                                } else {
                                                        $$ = found;
                                                }
                                        }

                                        fprintf(yyout, "[-] Reduced: lvalue -> IDENTIFIER\n");
                                }

        | LOCAL IDENTIFIER      {       
                                        SymEntry* found;
                                        if ((found = symTable.lookup($2, 0)) && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Local variable is shadowing library function in line %d.\n", yylineno);
                                        } else if (!found || found->type != LIBFUNC) {
                                        
                                                found = symTable.lookup($2, symTable.getScope());

                                                if (found) {
                                                        $$ = found;
                                                } else {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = $2;
                                                        entry->type = VAR;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;
                                                        symTable.insert(entry);
                                                        $$ = entry;
                                                }
                                        } 
                                        fprintf(yyout, "[-] Reduced: lvalue -> LOCAL IDENTIFIER\n");
                                }

        | DOUBLE_COLON IDENTIFIER       {       
                                                SymEntry* found = symTable.lookup($2, 0);
                                                if (!found) {
                                                        fprintf(yyout, "      [!] Error: Token %s has not been declared in global scope in line %d.\n", $2, yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = VAR;
                                                        $$ = dummy;
                                                } else {
                                                        $$ = found;
                                                }
                                                fprintf(yyout, "[-] Reduced: lvalue -> DOUBLE_COLON IDENTIFIER\n");
                                        }

        | member                        {       
                                                $$ = $1;
                                                fprintf(yyout, "[-] Reduced: lvalue -> member\n");
                                        }
        ;

member: lvalue DOT IDENTIFIER   {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: member -> lvalue DOT IDENTIFIER\n");
                                }

        | lvalue LEFT_BRACKET expr RIGHT_BRACKET        {
                                                                SymEntry* dummy = new SymEntry;
                                                                dummy->type = VAR;
                                                                $$ = dummy;
                                                                fprintf(yyout, "[-] Reduced: member -> lvalue LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }

        | call DOT IDENTIFIER                           {       
                                                                SymEntry* dummy = new SymEntry;
                                                                dummy->type = VAR;
                                                                $$ = dummy;
                                                                fprintf(yyout, "[-] Reduced: member -> call DOT IDENTIFIER\n");
                                                        }

        | call LEFT_BRACKET expr RIGHT_BRACKET          {       
                                                                SymEntry* dummy = new SymEntry;
                                                                dummy->type = VAR;
                                                                $$ = dummy;
                                                                fprintf(yyout, "[-] Reduced: member -> call LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        } 
        ;

call:   call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS   {       
                                                                SymEntry* dummy = new SymEntry;
                                                                dummy->type = NONLVAL;
                                                                $$ = dummy;       
                                                                fprintf(yyout, "[-] Reduced: call -> call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }

        | lvalue callsuffix                             {
                                                                $$ = $1;
                                                                fprintf(yyout, "[-] Reduced: call -> lvalue callsuffix\n");
                                                        }

        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS   {       
                                                                                                        SymEntry* dummy = new SymEntry;
                                                                                                        dummy->type = NONLVAL;
                                                                                                        $$ = dummy;
                                                                                                        fprintf(yyout, "[-] Reduced: call -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                }
        ;

callsuffix: normcall            {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = NONLVAL;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: callsuffix -> normcall\n");
                                }

            | methodcall        {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = NONLVAL;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: callsuffix -> methodcall\n");
                                }
            ;

normcall:   LEFT_PARENTHESIS elist RIGHT_PARENTHESIS    {       
                                                                SymEntry* dummy = new SymEntry;
                                                                dummy->type = VAR;
                                                                $$ = dummy;
                                                                fprintf(yyout, "[-] Reduced: normcall -> LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
            ;

methodcall: DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS      {       
                                                                                        SymEntry* dummy = new SymEntry;
                                                                                        dummy->type = VAR;
                                                                                        $$ = dummy;
                                                                                        fprintf(yyout, "[-] Reduced: methodcall -> DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                }
            ;

elist: expr                     {       
                                        $$ = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> expr\n");
                                }

        | elist COMMA expr      {       
                                        $$ = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> expr COMMA elist\n");
                                }

        | /* empty */           {       
                                        $$ = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> /* empty */\n");
                                }
        ;

objectdef: LEFT_BRACKET elist RIGHT_BRACKET     {       
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = VAR;
                                                        $$ = dummy;
                                                        fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET elist RIGHT_BRACKET\n");
                                                }

        | LEFT_BRACKET indexed RIGHT_BRACKET    {       
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = VAR;
                                                        $$ = dummy;
                                                        fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET indexed RIGHT_BRACKET\n");
                                                }
        ;

indexed: indexedelem                            {
                                                        $$ = nullptr;
                                                        fprintf(yyout, "[-] Reduced: indexed -> indexedelem\n");
                                                }

        | indexed COMMA indexedelem             {
                                                        $$ = nullptr;
                                                        fprintf(yyout, "[-] Reduced: indexed -> indexed COMMA indexedelem\n");
                                                }
        ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE     {
                                                                $$ = nullptr;
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
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = VAR;
                                                        $$ = dummy;   
                                                        fprintf(yyout, "[-] Reduced: block -> LEFT_BRACE stmt_list RIGHT_BRACE\n");
                                                }
        ;

funcdef: FUNCTION IDENTIFIER LEFT_PARENTHESIS   {
                                                        SymEntry* found = symTable.lookup($2, 0);
                                                        SymEntry* entry = nullptr;

                                                        if (found && found->type == LIBFUNC) {
                                                                fprintf(yyout, "      [!] Error : Function shadowing library function in line %d.\n", yylineno);
                                                        } else {
                                                                found = symTable.lookup($2, symTable.getScope());

                                                                if (!found) {
                                                                        entry = new SymEntry;
                                                                        entry->name = $2;
                                                                        entry->type = FUNC;
                                                                        entry->scope = symTable.getScope();
                                                                        entry->line = yylineno;
                                                                        entry->isActive = true;

                                                                        symTable.funcStack.push(entry);
                                                                        entry->args.clear();
                                                                        symTable.insert(entry);
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
                                                                entryFuncDef = entry;
                                                        }
                                                } idlist RIGHT_PARENTHESIS block {
                                                                                        if (!symTable.funcStack.empty()) {
                                                                                                symTable.funcStack.pop();
                                                                                        } 
                                                                                        SymEntry* dummy = new SymEntry;
                                                                                        dummy->type = VAR;
                                                                                        $$ = entryFuncDef ? entryFuncDef : dummy;
                                                                                        fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION IDENTIFIER LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                }
                                                
        | FUNCTION LEFT_PARENTHESIS     {
                                                SymEntry* entry = new SymEntry;

                                                entry->name = generateAnonymousName();
                                                entry->type = FUNC;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;
                                                entry->args.clear();

                                                symTable.funcStack.push(entry);

                                                symTable.insert(entry);
                                                entryFuncDef = entry;
                                                symTable.enter_scope();
                                                skipBlockScope = true;
                                        } idlist RIGHT_PARENTHESIS block        {       
                                                                                        symTable.funcStack.pop();
                                                                                        $$ = entryFuncDef;
                                                                                        fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                }
                                
        ;
        
const:  INTEGER         {       
                                $$ = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> INTEGER\n");
                        }

        | REAL          {       
                                $$ = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> REAL\n");
                        }
        
        | STRINGT       {       
                                $$ = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> STRING\n");
                        }

        | TRUE          {       
                                $$ = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> TRUE\n");
                        }

        | FALSE         {       
                                $$ = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> FALSE\n");
                        }

        | NIL           {
                                $$ = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> NIL\n");
                        }
        ;

idlist: IDENTIFIER      {       
                                SymEntry* found;

                                if ((found = symTable.lookup($1, 0)) && found->type == LIBFUNC) {
                                        fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.\n", yylineno);

                                        $$ = found;
                                } else {
                                        if ((found = symTable.lookup($1, symTable.getScope()))) {
                                                if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.\n", yylineno);
                                        } else {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = $1;
                                                entry->type = FORARG;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;

                                                symTable.insert(entry);

                                                if (!symTable.funcStack.empty() && symTable.funcStack.top()->scope == entry->scope - 1) {
                                                        symTable.funcStack.top()->args.push_back(entry);
                                                }  
                                                $$ = entry;
                                        }
                                }
                                fprintf(yyout, "[-] Reduced: idlist -> IDENTIFIER\n");
                        }
        | idlist COMMA IDENTIFIER   {   
                                        SymEntry* found;

                                        if ((found = symTable.lookup($3, 0)) && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.\n", yylineno);
                                                $$ = found;
                                        } else {
                                                if ((found = symTable.lookup($3, symTable.getScope()))) {
                                                        if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.\n", yylineno);
                                                } else {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = $3;
                                                        entry->type = FORARG;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;

                                                        symTable.insert(entry);

                                                        if (!symTable.funcStack.empty() && symTable.funcStack.top()->scope == entry->scope - 1) {
                                                                symTable.funcStack.top()->args.push_back(entry);
                                                        }  
                                                        $$ = entry;
                                                        
                                                }
                                        }
                                        fprintf(yyout, "[-] Reduced: idlist -> idlist COMMA IDENTIFIER\n");
                                    }
        | /* empty */           {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        $$ = dummy;
                                        fprintf(yyout, "[-] Reduced: idlist -> /* empty */\n");
                                }
        ;

ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt %prec LOWER_THAN_ELSE   {       
                                                                                        $$ = nullptr;
                                                                                        fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                                                                }

        | ifstmt ELSE stmt              {
                                                $$ = nullptr;
                                                fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt\n");
                                        }
        ;

whilestmt: WHILE LEFT_PARENTHESIS       {
                                                rabbitHole++;
                                        } expr RIGHT_PARENTHESIS stmt   {       
                                                                                rabbitHole--;
                                                                                $$ = nullptr;
                                                                                fprintf(yyout, "[-] Reduced: whilestmt -> WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                                                        }
        ;

forstmt: FOR LEFT_PARENTHESIS   {
                                        rabbitHole++;
                                } elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt   {       
                                                                                                        rabbitHole--;
                                                                                                        $$ = nullptr;
                                                                                                        fprintf(yyout, "[-] Reduced: forstmt -> FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt\n");
                                                                                                }
        ;

returnstmt: RETURN expr SEMICOLON       {
                                                $$ = nullptr;
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN expr SEMICOLON\n");
                                        }
            | RETURN SEMICOLON          {       
                                                $$ = nullptr;
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN SEMICOLON\n");
                                        }
            ;

errors: ERROR_COMMENT   {       
                                SymEntry* dummy = new SymEntry;
                                dummy->type = VAR;
                                $$ = dummy;
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_COMMENT\n");
                                fprintf(yyout, "      [!] Error: Invalid comment in line %d.\n", yylineno);
                                exit(1);
                        }

        | ERROR_STRING  {       
                                SymEntry* dummy = new SymEntry;
                                dummy->type = VAR;
                                $$ = dummy;
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_STRING\n");
                                fprintf(yyout, "      [!] Error: Invalid string in line %d.\n", yylineno);
                                exit(1);
                        }

        | ERROR_ESCAPE  {       
                                SymEntry* dummy = new SymEntry;
                                dummy->type = VAR;
                                $$ = dummy;
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_ESCAPE\n");
                                fprintf(yyout, "      [!] Error: Invalid escape sequence in line %d.\n", yylineno);
                                exit(1);
                        }

        | UNDEF         {       
                                SymEntry* dummy = new SymEntry;
                                dummy->type = VAR;
                                $$ = dummy;
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