/* -*- mode: bison -*- */

%language       "C++"
%define         api.value.type          variant

%define         api.token.constructor
%define         parse.assert            true
%define         parse.trace             true
%define         parse.error             verbose
%define         parse.lac               full
%require        "3.2"

%{
#include <iostream>
#include <string>
#include <cstdarg>
#include <cstdio>
#include "../symtable/symtable.hpp"

extern int yylex();
void yyerror(const char *s, int line);

%}


%code requires {
    #include <memory> 
    #include <iostream>
    #include <string>
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
%token TURNARY
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
%token <int> INTEGER;
%token <float> REAL
%token <std::string> STRING
%token <std::string> IDENTIFIER 

%token IGNORED


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

%right ASSIGN

%right UMINUS

%left RIGHT_BRACE LEFT_BRACE


%%
program: stmt_list
        ;

stmt: expr SEMICOLON
        | ifstmt
        | whilestmt
        | forstmt
        | returnstmt
        | BREAK SEMICOLON
        | CONTINUE SEMICOLON
        | block
        | funcdef
        | SEMICOLON
        ;
    
stmt_list:  stmt stmt_list
            | /* empty */
            ;

expr:   assignexpr
        | expr PLUS expr
        | expr MINUS expr
        | expr MULTIPLY expr
        | expr DIVIDE expr
        | expr MODULO expr
        | expr GREATER_THAN expr
        | expr LESS_THAN expr
        | expr GREATER_THAN_EQUAL expr
        | expr LESS_THAN_EQUAL expr
        | expr EQUAL expr
        | expr NOT_EQUAL expr
        | expr AND expr
        | expr OR expr
        | term
        ;

term:   LEFT_PARENTHESIS expr RIGHT_PARENTHESIS
        | MINUS expr %prec UMINUS
        | NOT expr
        | INCREMENT lvalue
        | lvalue INCREMENT
        | DECREMENT lvalue
        | lvalue DECREMENT
        | primary
        ;

assignexpr: lvalue ASSIGN expr
            ;

primary: lvalue
        | call
        | objectdef
        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS
        | const
        ;

lvalue: IDENTIFIER
        | LOCAL IDENTIFIER
        | DOUBLE_COLON IDENTIFIER
        | member
        ;

member: lvalue DOT IDENTIFIER
        | lvalue LEFT_BRACKET expr RIGHT_BRACKET
        | call DOT IDENTIFIER
        | call LEFT_BRACKET expr RIGHT_BRACKET 
        ;

call:   call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
        | lvalue callsuffix
        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
        ;

callsuffix: normcall
            | methodcall
            ;

normcall:   LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
            ;

methodcall: DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
            ;

elist: expr
        | expr COMMA elist
        | /* empty */
        ;

objectdef: LEFT_BRACKET elist RIGHT_BRACKET     
        | LEFT_BRACKET indexed RIGHT_BRACKET
        ;

indexed: indexedelem
        | indexed COMMA indexedelem
        ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE
            ;

block: LEFT_BRACE stmt_list RIGHT_BRACE
        ;

funcdef: FUNCTION IDENTIFIER LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block
        ;
        
const:  INTEGER
        | REAL
        | STRING
        | TRUE
        | FALSE
        | NIL
        ;

idlist: IDENTIFIER
        | idlist COMMA IDENTIFIER
        | /* empty */
        ;

ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt %prec LOWER_THAN_ELSE
        | IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt
        ;

whilestmt: WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt
        ;

forstmt: FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt
        ;

returnstmt: RETURN expr SEMICOLON
            | RETURN SEMICOLON
            ;
%%



void yyerror(const char *s, int line) {
    std::cerr << "Error at line " << line << ": " << s << std::endl;
    exit(1);
}
