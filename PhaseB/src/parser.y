/* %define         parse.error     verbose
%define         parse.trace  */   
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
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
void yyerror(const char* msg);

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


%type <node> lvalue
%type <str_val> assignexpr primary const
%type <str_val> call callsuffix normcall methodcall
%type <str_val> elist objectdef indexed indexedelem
%type <str_val> idlist
%type <str_val> errors


%left RIGHT_PARENTHESIS LEFT_PARENTHESIS
%left RIGHT_BRACKET LEFT_BRACKET

%left DOT DOUBLE_DOT

%right NOT INCREMENT DECREMENT MINUS

%left MULTIPLY DIVIDE MODULO

%right PLUS

%nonassoc GREATER_THAN GREATER_THAN_EQUAL LESS_THAN LESS_THAN_EQUAL
%nonassoc LOWER_THAN_ELSE
%nonassoc EQUAL NOT_EQUAL
%nonassoc ELSE

%left AND 
%left OR

%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN

%right UMINUS

%left RIGHT_BRACE LEFT_BRACE


%%
program: stmt_list      {
                                fprintf(yyout, "[-] Reduced: program -> stmt_list\n");
                        }
        ;

stmt: expr SEMICOLON    {
                                fprintf(yyout, "[-] Reduced: stmt -> expr SEMICOLON\n");
                        }

        | ifstmt        {
                                fprintf(yyout, "[-] Reduced: stmt -> ifstmt\n");
                        }

        | whilestmt     {
                                fprintf(yyout, "[-] Reduced: stmt -> whilestmt\n");
                        }

        | forstmt       {
                                fprintf(yyout, "[-] Reduced: stmt -> forstmt\n");
                        }

        | returnstmt    {       
                                if (symTable.funcStack.empty()) fprintf(yyout, "      [!] Error: Return statement outside of function in line %d.", yylineno);
                                fprintf(yyout, "[-] Reduced: stmt -> returnstmt\n");
                        }

        | BREAK SEMICOLON       {       
                                        if (rabbitHole < 1)  fprintf(yyout, "      [!] Error: Break statement outside of loop in line %d.", yylineno);
                                        fprintf(yyout, "[-] Reduced: stmt -> BREAK SEMICOLON\n");
                                }

        | CONTINUE SEMICOLON    {       
                                        if (rabbitHole < 1) fprintf(yyout, "      [!] Error: Continue statement outside of loop in line %d.", yylineno);
                                        fprintf(yyout, "[-] Reduced: stmt -> CONTINUE SEMICOLON\n");
                                }
        | block                 {       
                                        fprintf(yyout, "[-] Reduced: stmt -> block\n");
                                }

        | funcdef               {
                                        fprintf(yyout, "[-] Reduced: stmt -> funcdef\n");
                                }

        | SEMICOLON             {
                                        fprintf(yyout, "[-] Reduced: stmt -> SEMICOLON\n");
                                }

        | errors                {
                                        fprintf(yyout, "[-] Reduced: stmt -> errors\n");
                                }
        ;
    
stmt_list:  stmt stmt_list     {
                                        fprintf(yyout, "[-] Reduced: stmt_list -> stmt stmt_list\n");
                                }

            | /* empty */       {       
                                        fprintf(yyout, "[-] Reduced: stmt_list -> /* empty */\n");
                                }
            ;

expr:   assignexpr              {
                                        fprintf(yyout, "[-] Reduced: expr -> assignexpr\n");
                                }

        | expr PLUS expr        {       
                                        fprintf(yyout, "[-] Reduced: expr -> expr PLUS expr\n");
                                }

        | expr MINUS expr       {
                                        fprintf(yyout, "[-] Reduced: expr -> expr MINUS expr\n");
                                }

        | expr MULTIPLY expr    {
                                        fprintf(yyout, "[-] Reduced: expr -> expr MULTIPLY expr\n");
                                }

        | expr DIVIDE expr      {
                                        fprintf(yyout, "[-] Reduced: expr -> expr DIVIDE expr\n");
                                }

        | expr MODULO expr      {
                                        fprintf(yyout, "[-] Reduced: expr -> expr MODULO expr\n");
                                }

        | expr GREATER_THAN expr        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN expr\n");
                                        }

        | expr LESS_THAN expr           {
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN expr\n");
                                        }

        | expr GREATER_THAN_EQUAL expr  {
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN_EQUAL expr\n");
                                        }

        | expr LESS_THAN_EQUAL expr     {
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN_EQUAL expr\n");
                                        }

        | expr EQUAL expr               {
                                                fprintf(yyout, "[-] Reduced: expr -> expr EQUAL expr\n");
                                        }

        | expr NOT_EQUAL expr           {
                                                fprintf(yyout, "[-] Reduced: expr -> expr NOT_EQUAL expr\n");
                                        }

        | expr AND expr                 {
                                                fprintf(yyout, "[-] Reduced: expr -> expr AND expr\n");
                                        }

        | expr OR expr                  {
                                                fprintf(yyout, "[-] Reduced: expr -> expr OR expr\n");
                                        }

        | term                          {
                                                fprintf(yyout, "[-] Reduced: expr -> term\n");
                                        } 
        ;

term:   LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {
                                                        fprintf(yyout, "[-] Reduced: term -> LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");
                                                }

        | MINUS expr %prec UMINUS               { 
                                                        fprintf(yyout, "[-] Reduced: term -> MINUS expr\n");
                                                }

        | NOT expr                              { 
                                                        fprintf(yyout, "[-] Reduced: term -> NOT expr\n");
                                                }

        | INCREMENT lvalue                      {       
                                                        if ($2->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (++func) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: term -> INCREMENT lvalue\n");
                                                }

        | lvalue INCREMENT                      {       
                                                        if ($1->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func++) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue INCREMENT\n");
                                                }

        | DECREMENT lvalue                      {       
                                                        if ($2->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (--func) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: term -> DECREMENT lvalue\n");
                                                }

        | lvalue DECREMENT                      {       
                                                        if ($1->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func--) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue DECREMENT\n");
                                                }        
        
        | primary                               {
                                                        fprintf(yyout, "[-] Reduced: term -> primary\n");
                                                }
        ;

assignexpr:     lvalue ASSIGN expr              {       
                                                        if ($1->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func = expr) in line %d.", yylineno);
                                                        if ($1->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot assign to library function in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue ASSIGN expr\n");
                                                }

                | lvalue PLUS_ASSIGN expr       {       
                                                        if ($1->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func += expr) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue PLUS_ASSIGN expr\n");
                                                }

                | lvalue MINUS_ASSIGN expr      {
                                                        if ($1->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func -= expr) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue MINUS_ASSIGN expr\n");
                                                }
                ;

primary: lvalue                 {
                                        fprintf(yyout, "[-] Reduced: primary -> lvalue\n");
                                }

        | call                  {
                                        fprintf(yyout, "[-] Reduced: primary -> call\n");
                                }

        | objectdef             {
                                        fprintf(yyout, "[-] Reduced: primary -> objectdef\n");
                                }

        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS    {
                                                            fprintf(yyout, "[-] Reduced: primary -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS\n");
                                                        }
        | const                 {
                                        fprintf(yyout, "[-] Reduced: primary -> const\n");
                                }
        ;

lvalue: IDENTIFIER              {       
                                        SymEntry* found;
                                        // Check for libfunc shadowing
                                        if ((found = symTable.lookup($1, 0))) {
                                                if (found->type == LIBFUNC) $$ = found;
                                        }

                                        found = symTable.lookup($1);

                                        if (!found) {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = $1;
                                                entry->type = VAR;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;

                                                symTable.insert(entry);
                                                $$ = entry;
                                        } else {
                                                if (found->type == VAR) {
                                                        if (symTable.funcStack.empty()) {
                                                                $$ = found;
                                                        } else {
                                                                if (found->scope == symTable.getScope() || found->scope == 0) {
                                                                        $$ = found;
                                                                } else {
                                                                     fprintf(yyout, "      [!] Error: Variable %s is not accessible in line %d.", $1, yylineno); 
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
                                        if ((found = symTable.lookup($2, 0))) {
                                                if (found->type == LIBFUNC) fprintf(yyout, "      [!] Error: Local variable is shadowing library function in line %d.", yylineno);
                                        } 
                                        
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
                                        fprintf(yyout, "[-] Reduced: lvalue -> LOCAL IDENTIFIER\n");
                                }

        | DOUBLE_COLON IDENTIFIER       {       
                                                SymEntry* found = symTable.lookup($2, 0);
                                                if (!found) {
                                                        fprintf(yyout, "      [!] Error: Token %s has not been declared in global scope in line %d.", $2, yylineno);
                                                } else {
                                                        $$ = found;
                                                }
                                                fprintf(yyout, "[-] Reduced: lvalue -> DOUBLE_COLON IDENTIFIER\n");
                                        }

        | member                        {
                                                fprintf(yyout, "[-] Reduced: lvalue -> member\n");
                                        }
        ;

member: lvalue DOT IDENTIFIER   {
                                        fprintf(yyout, "[-] Reduced: member -> lvalue DOT IDENTIFIER\n");
                                }

        | lvalue LEFT_BRACKET expr RIGHT_BRACKET        {
                                                                fprintf(yyout, "[-] Reduced: member -> lvalue LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }

        | call DOT IDENTIFIER                           {
                                                                fprintf(yyout, "[-] Reduced: member -> call DOT IDENTIFIER\n");
                                                        }

        | call LEFT_BRACKET expr RIGHT_BRACKET          {
                                                                fprintf(yyout, "[-] Reduced: member -> call LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        } 
        ;

call:   call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS   {
                                                                fprintf(yyout, "[-] Reduced: call -> call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }

        | lvalue callsuffix                             {
                                                                fprintf(yyout, "[-] Reduced: call -> lvalue callsuffix\n");
                                                        }

        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS   {
                                                                                                    fprintf(yyout, "[-] Reduced: call -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                }
        ;

callsuffix: normcall            {
                                    fprintf(yyout, "[-] Reduced: callsuffix -> normcall\n");
                                }

            | methodcall        {
                                    fprintf(yyout, "[-] Reduced: callsuffix -> methodcall\n");
                                }
            ;

normcall:   LEFT_PARENTHESIS elist RIGHT_PARENTHESIS    {
                                                            fprintf(yyout, "[-] Reduced: normcall -> LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
            ;

methodcall: DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS      {
                                                                                    fprintf(yyout, "[-] Reduced: methodcall -> DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                }
            ;

elist: expr                     {
                                        fprintf(yyout, "[-] Reduced: elist -> expr\n");
                                }

        | elist COMMA expr      {
                                        fprintf(yyout, "[-] Reduced: elist -> expr COMMA elist\n");
                                }

        | /* empty */           {
                                        fprintf(yyout, "[-] Reduced: elist -> /* empty */\n");
                                }
        ;

objectdef: LEFT_BRACKET elist RIGHT_BRACKET     {
                                                    fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET elist RIGHT_BRACKET\n");
                                                }

        | LEFT_BRACKET indexed RIGHT_BRACKET    {
                                                    fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET indexed RIGHT_BRACKET\n");
                                                }
        ;

indexed: indexedelem                            {
                                                    fprintf(yyout, "[-] Reduced: indexed -> indexedelem\n");
                                                }

        | indexed COMMA indexedelem             {
                                                    fprintf(yyout, "[-] Reduced: indexed -> indexed COMMA indexedelem\n");
                                                }
        ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE     {
                                                            fprintf(yyout, "[-] Reduced: indexedelem -> LEFT_BRACE expr COLON expr RIGHT_BRACE\n");
                                                        }
            ;

block: LEFT_BRACE       { 
                                if (!skipBlockScope) symTable.enter_scope(); 
                        } stmt_list RIGHT_BRACE {
                                                        symTable.exit_scope();      
                                                        fprintf(yyout, "[-] Reduced: block -> LEFT_BRACE stmt_list RIGHT_BRACE\n");
                                                }
        ;

funcdef: FUNCTION IDENTIFIER LEFT_PARENTHESIS {
                                                skipBlockScope = true;
                                                SymEntry* found = symTable.lookup($2, 0);

                                                if (found) {
                                                        if (found->type == LIBFUNC) fprintf(yyout, "      [!] Error : Function shadowing library function in line %d.", yylineno);
                                                }
                                                
                                                found = symTable.lookup($2, symTable.getScope());

                                                if (!found) {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = $2;
                                                        entry->type = FUNC;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;

                                                        symTable.funcStack.push(entry);
                                                        entry->args.clear();
                                                        symTable.insert(entry);
                                                        fprintf(yyout, "\n                       %s\n", symTable.funcStack.top()->name.c_str());
                                                } else {
                                                        if (found->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Function %s already declared in line %d.", $2, yylineno);
                                                        } else if (found->type == VAR) {
                                                                fprintf(yyout, "      [!] Error: Function %s is shadowing variable in line %d.", $2, yylineno);
                                                        } else if (found->type == FORARG) {
                                                                fprintf(yyout, "      [!] Error: Function %s is shadowing formal argument in line %d.", $2, yylineno);
                                                        } 
                                                }
                                                symTable.enter_scope();

                                                } idlist RIGHT_PARENTHESIS block {      
                                                                                        symTable.funcStack.pop();
                                                                                        if (symTable.funcStack.empty()) {
                                                                                                skipBlockScope = false;
                                                                                        }
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

                                                symTable.enter_scope();
                                                skipBlockScope = true;
                                        } idlist RIGHT_PARENTHESIS block        {       
                                                                                        symTable.funcStack.pop();
                                                                                        skipBlockScope = false;
                                                                                        fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                }
                                
        ;
        
const:  INTEGER         {
                                fprintf(yyout, "[-] Reduced: const -> INTEGER\n");
                        }

        | REAL          {
                                fprintf(yyout, "[-] Reduced: const -> REAL\n");
                        }
        
        | STRINGT       {
                                fprintf(yyout, "[-] Reduced: const -> STRING\n");
                        }

        | TRUE          {
                                fprintf(yyout, "[-] Reduced: const -> TRUE\n");
                        }

        | FALSE         {
                                fprintf(yyout, "[-] Reduced: const -> FALSE\n");
                        }

        | NIL           {
                                fprintf(yyout, "[-] Reduced: const -> NIL\n");
                        }
        ;

idlist: IDENTIFIER      {       
                                SymEntry* found;

                                if ((found = symTable.lookup($1, 0))) {
                                        if (found->type == LIBFUNC) fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.", yylineno);

                                }
                                
                                if ((found = symTable.lookup($1, symTable.getScope()))) {
                                        if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.", yylineno);
                                } else {
                                        SymEntry* entry = new SymEntry;
                                        entry->name = $1;
                                        entry->type = FORARG;
                                        entry->scope = symTable.getScope();
                                        entry->line = yylineno;
                                        entry->isActive = true;

                                        symTable.funcStack.top()->args.push_back(entry);
                                        symTable.insert(entry);
                                }
                                
                                fprintf(yyout, "[-] Reduced: idlist -> IDENTIFIER\n");
                        }
        | idlist COMMA IDENTIFIER   {   
                                        SymEntry* found;

                                        if ((found = symTable.lookup($3, 0))) {
                                                if (found->type == LIBFUNC) fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.", yylineno);

                                        } 
                                        
                                        if ((found = symTable.lookup($3, symTable.getScope()))) {
                                                if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.", yylineno);
                                        } else {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = $3;
                                                entry->type = FORARG;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;

                                                symTable.funcStack.top()->args.push_back(entry);
                                                symTable.insert(entry);
                                        }

                                        fprintf(yyout, "[-] Reduced: idlist -> idlist COMMA IDENTIFIER\n");
                                    }
        | /* empty */           {
                                        fprintf(yyout, "[-] Reduced: idlist -> /* empty */\n");
                                }
        ;

ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt %prec LOWER_THAN_ELSE   {
                                                                                    fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                                                                }

        | ifstmt ELSE stmt             {
                                                                                    fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt\n");
                                                                                }
        ;

whilestmt: WHILE LEFT_PARENTHESIS       {
                                        rabbitHole++;
                                        } expr RIGHT_PARENTHESIS        {
                                                                                symTable.enter_scope();
                                                                        } stmt  {       
                                                                                        rabbitHole--;
                                                                                        symTable.exit_scope();
                                                                                        fprintf(yyout, "[-] Reduced: whilestmt -> WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                                                                }
        ;

forstmt: FOR LEFT_PARENTHESIS   {
                                        rabbitHole++;
                                } elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS {
                                                                                                        symTable.enter_scope();
                                                                                                } stmt   {       
                                                                                                        rabbitHole--;
                                                                                                        symTable.exit_scope();
                                                                                                        fprintf(yyout, "[-] Reduced: forstmt -> FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt\n");
                                                                                                }
        ;

returnstmt: RETURN expr SEMICOLON       {
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN expr SEMICOLON\n");
                                        }
            | RETURN SEMICOLON          {
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN SEMICOLON\n");
                                        }
            ;

errors: ERROR_COMMENT   {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_COMMENT\n");
                                fprintf(yyout, "      [!] Error: Invalid comment in line %d.", yylineno);
                                exit(1);
                        }

        | ERROR_STRING  {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_STRING\n");
                                fprintf(yyout, "      [!] Error: Invalid string in line %d.", yylineno);
                                exit(1);
                        }

        | ERROR_ESCAPE  {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_ESCAPE\n");
                                fprintf(yyout, "      [!] Error: Invalid escape sequence in line %d.", yylineno);
                                exit(1);
                        }

        | UNDEF         {
                                fprintf(yyout, "[-] Reduced: errors -> UNDEF\n");
                                fprintf(yyout, "      [!] Error: Undefined variable in line %d.", yylineno);    
                                exit(1);
                        }
        ;
%%

void yyerror(const char* msg) {
    fprintf(stderr, "Bison error: %s\n", msg);
}