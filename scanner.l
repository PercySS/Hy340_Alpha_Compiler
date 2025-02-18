/*
    csd4676 Dimitrios Makrogiannis
    csd4621 Katerina Gyparaki
    csd5141 Kallia Samaritaki

    This is the lexical analyzer for the compiler. We will use cpp to implement the lexical analyzer.
*/

/* Declarations  section */

%option noyywrap

Alpha       [a-zA-Z]
Digit       [0-9]
WhiteSpace  [ \t\n]
LineEnd     \n



%{
    #include <iostream>
    #include <stack>
    #include <queue
    #include <string>
    extern YYSTYPE yylval;
    extern FILE *yyin;
    int yyerrror(char *s);


    using namespace std;


}%

/* Token Rules section */
%%
    /* Keywords */
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"return"    { return RETURN; }
"int"       { return INT; }
"void"      { return VOID; }
"char"      { return CHAR; }
"main"      { return MAIN; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }
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
"register"  { return REGISTER; }
"auto"      { return AUTO; }
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
"&&"        { return AND; }
"||"        { return OR; }
"!"         { return NOT; }
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
"."         { return DOT; }
"?"         { return TURNARY; }

    /* Identifiers */   
{Alpha}({Alpha}|{Digit})* { return ID; }
    
        /* Constants */
{Digit}+                                { return INTCONST; }
{Digit}+"."{Digit}*                     { return FLOATCONST; }
{Digit}+"."{Digit}*[eE][+-]?{Digit}+    { return FLOATCONST; }
{Digit}+"."{Digit}+                     { return REALCONST; }


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