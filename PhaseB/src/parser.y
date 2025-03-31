%define         parse.error     verbose
%define         parse.trace    
%locations

%{
#include <iostream>
#include <string>
#include <cstdarg>
#include <cstdio>
#include "parser.tab.hpp"
#include "../src/symtable.hpp"

extern SymbolTable symTable;
extern bool skipBlockScope;
extern int rabbitHole;
extern int yylex();
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
void myerror(YYLTYPE* loc, const char* msg);
void yyerror(const char* msg);

%}

%union {
    int int_val;
    float float_val;
    char* str_val;
}


%start program

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

%type <str_val> assignexpr lvalue primary const
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
%nonassoc ELSE
%nonassoc EQUAL NOT_EQUAL

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
                                if (funcStack.empty()) myerror(&@1, "Error: Return statement outside of function");
                                fprintf(yyout, "[-] Reduced: stmt -> returnstmt\n");
                        }

        | BREAK SEMICOLON       {       
                                        if (rabbitHole < 1)  myerror(&@1, "Error: Break statement outside of loop");
                                        fprintf(yyout, "[-] Reduced: stmt -> BREAK SEMICOLON\n");
                                }

        | CONTINUE SEMICOLON    {       
                                        if (rabbitHole < 1) myerror(&@1, "Error: Continue statement outside of loop");
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
                                        fprintf(yyout, "%s\n", yylval.str_val);
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
                                                        SymEntry* found = symTable.lookup($2);
                                                        if (found && found->type == FUNC) myerror(&@1, "Error: Function is not l-value");
                                                        fprintf(yyout, "[-] Reduced: term -> INCREMENT lvalue\n");
                                                }

        | lvalue INCREMENT                      {       
                                                        SymEntry* found = symTable.lookup($1);
                                                        if (found && found->type == FUNC) myerror(&@1, "Error: Function call is not l-value");
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue INCREMENT\n");
                                                }

        | DECREMENT lvalue                      {       
                                                        SymEntry* found = symTable.lookup($2);
                                                        if (found && found->type == FUNC) myerror(&@1, "Error: Function call is not l-value");
                                                        fprintf(yyout, "[-] Reduced: term -> DECREMENT lvalue\n");
                                                }

        | lvalue DECREMENT                      {       
                                                        SymEntry* found = symTable.lookup($1);
                                                        if (found && found->type == FUNC) myerror(&@1, "Error: Function call is not l-value");
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue DECREMENT\n");
                                                }        
        
        | primary                               {
                                                        fprintf(yyout, "[-] Reduced: term -> primary\n");
                                                }
        ;

assignexpr:     lvalue ASSIGN expr              {
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue ASSIGN expr\n");
                                                }

                | lvalue PLUS_ASSIGN expr       {
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue PLUS_ASSIGN expr\n");
                                                }

                | lvalue MINUS_ASSIGN expr      {
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue ASSIGN expr\n");
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
                                        SymEntry* found = symTable.lookup($1);

                                        if (found && found->type == FUNC) myerror(&@1, "Error: Function is not l-value");

                                        fprintf(yyout, "[-] Reduced: lvalue -> IDENTIFIER\n");
                                }
        | LOCAL IDENTIFIER      {       
                                        SymEntry* found = symTable.lookupInCurrentScope($2);

                                        if (found) myerror(&@2, "Error: Identifier already declared in this scope.");

                                        SymEntry* entry = new SymEntry;
                                        entry->name = $2;
                                        entry->type = VAR;
                                        entry->scope = symTable.getScope();
                                        

                                        fprintf(yyout, "[-] Reduced: lvalue -> LOCAL IDENTIFIER\n");
                                }

        | DOUBLE_COLON IDENTIFIER       {       
                                                SymEntry* found = symTable.lookupGlobal($2);
                                                
                                                if (!found) {
                                                        myerror(&@2, "Error: Variable not declared in global scope.");
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
                                                Symentry* found = lookupInCurrentScope($2);

                                                if (found) myerror(&@2, "Error: Identifier





                                                } idlist RIGHT_PARENTHESIS block {
                                                                                        funcStack.pop();
                                                                                        skipBlockScope = false;
                                                                                        fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION IDENTIFIER LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                }
                                                
        | FUNCTION LEFT_PARENTHESIS     {


                                        } idlist RIGHT_PARENTHESIS block        {       
                                                                                        funcStack.pop();
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
                                $$ = $1;
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
                                SymEntry* entry = new SymEntry;
                                entry->name = $1;
                                entry->type = FORARG;
                                entry->scope = symTable.getScope();
                                entry->line = yylineno;
                                entry->isActive = true;
                                fprintf(yyout, "Inserting id in symtable\n");
                                int res = symTable.insert(entry);

                                if (res == 2) myerror(&@1, "Error: Variable already declared in this scope.");
                                if (res == 3) myerror(&@1, "Error: Cannot shadow lib functions.");
                                if (res == 4) myerror(&@1, "Error: Cannot shadow user-active functions");

                                funcStack.top()->args.push_back(entry);
                                // print name : forarg of func : name
                                fprintf(yyout, "[-] Inserting %s as forarg in func %s\n", $1, funcStack.top()->name.c_str());

                                fprintf(yyout, "[-] Reduced: idlist -> IDENTIFIER\n");
                        }
        | idlist COMMA IDENTIFIER   {   
                                        SymEntry* entry = new SymEntry;
                                        entry->name = $3;
                                        entry->type = FORARG;
                                        entry->scope = symTable.getScope();
                                        entry->line = yylineno;
                                        entry->isActive = true;
                                        fprintf(yyout, "Inserting id in symtable\n");
                                        int res = symTable.insert(entry);

                                        if (res == 2) myerror(&@3, "Error: Variable already declared in this scope.");
                                        if (res == 3) myerror(&@3, "Error: Cannot shadow lib functions.");
                                        if (res == 4) myerror(&@3, "Error: Cannot shadow user-active functions");

                                        funcStack.top()->args.push_back(entry);
                                        
                                        fprintf(yyout, "[-] Inserting %s as forarg in func %s\n", $3, funcStack.top()->name.c_str());

                                        fprintf(yyout, "[-] Reduced: idlist -> idlist COMMA IDENTIFIER\n");
                                    }
        | /* empty */           {
                                        fprintf(yyout, "[-] Reduced: idlist -> /* empty */\n");
                                }
        ;

ifstmt: IF LEFT_PARENTHESIS     {

                                } expr RIGHT_PARENTHESIS stmt %prec LOWER_THAN_ELSE   {
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
                                myerror(&@1, "Error: Invalid comment");
                                exit(1);
                        }

        | ERROR_STRING  {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_STRING\n");
                                myerror(&@1, "Error: Invalid string");
                                exit(1);
                        }

        | ERROR_ESCAPE  {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_ESCAPE\n");
                                myerror(&@1, "Error: Invalid escape sequence");
                                exit(1);
                        }

        | UNDEF         {
                                fprintf(yyout, "[-] Reduced: errors -> UNDEF\n");
                                myerror(&@1, "Error: Undefined token");     
                                exit(1);
                        }
        ;
%%


void myerror(YYLTYPE* loc, const char* msg) {
    fprintf(stderr, "Error at line %d, column %d: %s\n", loc->first_line, loc->first_column, msg);
}

void yyerror(const char* msg) {
    fprintf(stderr, "Bison error: %s\n", msg);
}