/* Declarations  section */

%option noyywrap
%option nounput yylineno

Alpha       [a-zA-Z]
Digit       [0-9]
Identifiers {Alpha}({Alpha}{Digit}_)*
WhiteSpace  [ \t\n]
LineEnd     \n



%{
    
#include "al.hpp"

}%

/* Token Rules section */
%%
    /* Keywords */
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"function"  { return FUNCTION; }
"return"    { return RETURN; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }
"true"      { return TRUE; }
"false"     { return FALSE; }
"nil"       { return NIL; }
"local"     { return LOCAL; }
"global"    { return GLOBAL; }
"and"       { return AND; }
"not"       { return NOT; }
"or"        { return OR; }
"int"       { return INT; }
"void"      { return VOID; }
"char"      { return CHAR; }
"main"      { return MAIN; }
"switch"    { return SWITCH; }
"case"      { return CASE; }
"default"   { return DEFAULT; }
"do"        { return DO; }
"double"    { return DOUBLE; }
"float"     { return FLOAT; }
"long"      { return LONG; }
"short"     { return SHORT; }
"unsigned"  { return UNSIGNED; }
"signed"    { return SIGNED; }
"const"     { return CONST; }
"static"    { return STATIC; }
"extern"    { return EXTERN; }
"typedef"   { return TYPEDEF; }
"struct"    { return STRUCT; }
"union"     { return UNION; }
"enum"      { return ENUM; }
"sizeof"    { return SIZEOF; }
"volatile"  { return VOLATILE; }
"goto"      { return GOTO; }

    /* Operators */
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULT; }
"/"         { return DIV; }
"%"         { return MOD; }
"="         { return ASSIGN; }
"=="        { return EQ; }
"!="        { return NEQ; }
"<"         { return LT; }
"<="        { return LE; }
">"         { return GT; }
">="        { return GE; }
"++"        { return INC; }
"--"        { return DEC; }
"+="        { return PLUSEQ; }
"-="        { return MINUSEQ; }
"*="        { return MULTEQ; }
"/="        { return DIVEQ; }
"%="        { return MODEQ; }

    /* Delimiters */
"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"["         { return LBRACKET; }
"]"         { return RBRACKET; }
";"         { return SEMICOLON; }
","         { return COMMA; }
":"         { return COLON; }
"::"        { return SCOPE; }
"->"        { return ARROW; }
"."         { return DOT; }
".."        { return DOTDOT; }
"?"         { return TURNARY; }

    /* Identifiers */   
{Alpha}({Alpha}|{Digit}|_)* { return ID; }
    
    /* Constants */
{Digit}*                                { return INTCONST; }
{Digit}+"."{Digit}+                     { return REALCONST; }

    /* WhiteSpaces */
{WhiteSpace}+   {} 
{LineEnd}       { return EOL; }

    /* Comments */
"//"            { return LINECOMMENT; }
"/*"            { return STARTBLOCKCOMMENT; }
"*/"            { return ENDBLOCKCOMMENT; }

    /* Strings */
\"[^"]*\"       { return STRING; }

    /* Error */
.               { return UNEXPECTED; }



%%

/* File reading */
int main(int argc, char **argv) {   
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            fprintf(stderr, "Cannot open file %s\n", argv[1]);
            return 1;
        } else {
            yyin = stdin;
        }
    }

    yylex();
    return 0;
}