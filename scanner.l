/* Options  section */
%option header-file="scanner.hpp"
%option noyywrap
%option yylineno
%option nounput
%option c++
%option noinput

Alpha       [a-zA-Z]
Digit       [0-9]
WhiteSpace  [ \t\n]
LineEnd     \n


%{
#include "al.hpp"
queue<alpha_token_t*> tokenQueue;
int tokenNum = 0;
int incomment = 0;
int instring = 0;

#define YY_DECL int alpha_yylex(alpha_token_t* token)

%}
/* Token Rules section */
%%
    /* Keywords */
"if"        {
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"else"      {  
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"while"     { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }


"for"       { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"function"  { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"return"    { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"break"     {
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"continue"  { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"true"      { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"false"     { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"nil"       { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"local"     { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"global"    { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"and"       { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"not"       { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"or"        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }


"int"       { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"void"      { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"char"      { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"main"      { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"switch"    { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"case"      { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"default"   { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"do"        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"double"    { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"float"     { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"long"      { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"short"     { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"unsigned"  { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"signed"    { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"const"     { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"static"    { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"extern"    { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"typedef"   { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"struct"    { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"union"     { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"enum"      { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"sizeof"    { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"volatile"  { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

"goto"      { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = KEYWORD;  
                token->tokUpp = toUpper(yytext);
                token->instance = "enumerated";
                return KEYWORD;
            }

    /* Operators */
"+"         {   
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "PLUS";
                token->instance = "enumerated";
                return OPERATOR;
            }

"-"         {   
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "MINUS";
                token->instance = "enumerated";
                return OPERATOR;
            }

"*"         {  
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "MULT";
                token->instance = "enumerated";
                return OPERATOR;
            }

"/"         { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "DIV";
                token->instance = "enumerated";
                return OPERATOR;
            }

"%"         { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "MOD";
                token->instance = "enumerated";
                return OPERATOR;
            }

"="         { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "ASSIGN";
                token->instance = "enumerated";
                return OPERATOR;
            }

"=="        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "EQ";
                token->instance = "enumerated";
                return OPERATOR;
            }

"!="        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "NE";
                token->instance = "enumerated";
                return OPERATOR;
            }

"<"         { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "LT";
                token->instance = "enumerated";
                return OPERATOR;
            }

"<="        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "LE";
                token->instance = "enumerated";
                return OPERATOR;
            }

">"         { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "GT";
                token->instance = "enumerated";
                return OPERATOR;
            }

">="        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "GE";
                token->instance = "enumerated";
                return OPERATOR;
            }

"++"        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "PLUS_PLUS";
                token->instance = "enumerated";
                return OPERATOR;
            }

"--"        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "MINUS_MINUS";
                token->instance = "enumerated";
                return OPERATOR;
            }

"+="        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "PLUSEQ";
                token->instance = "enumerated";
                return OPERATOR;
            }

"-="        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "MINUSEQ";
                token->instance = "enumerated";
                return OPERATOR;
            }

"*="        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "MULTEQ";
                token->instance = "enumerated";
                return OPERATOR;
            }

"/="        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "DIVEQ";
                token->instance = "enumerated";
                return OPERATOR;
            }

"%="        { 
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->content = strdup(yytext);
                token->type = OPERATOR;  
                token->tokUpp = "MODEQ";
                token->instance = "enumerated";
                return OPERATOR;
            }

    /* Delimiters */
"("         { return LEFT_PARENTHESIS; }
")"         { return RIGHT_PARENTHESIS; }
"{"         { return LEFT_BRACE; }
"}"         { return RIGHT_BRACE; }
"["         { return LEFT_BRACKET; }
"]"         { return RIGHT_BRACKET; }
";"         { return SEMICOLON; }
","         { return COMMA; }
":"         { return COLON; }
"::"        { return SCOPE; }
"->"        { return ARROW; }
"."         { return DOT; }
".."        { return DOTDOT; }


"?"         { return TURNARY; }

    /* Identifiers */   
{Alpha}({Alpha}|{Digit}|_)*     { 
                                    token->line = yylineno;
                                    token->numToken = tokenNum++;
                                    token->content = strdup(yytext);
                                    token->type = IDENTIFIER;  
                                    token->tokUpp = yytext;
                                    token->instance = "char*";
                                    return IDENTIFIER;
                                }
    
    /* Constants */
{Digit}+                        { 
                                    token->line = yylineno;
                                    token->numToken = tokenNum++;
                                    token->content = strdup(yytext);
                                    token->type = INTCONST;  
                                    token->tokUpp = yytext;
                                    token->instance = "integer";
                                    return INTCONST;
                                }

{Digit}+"."{Digit}+             { 
                                    token->line = yylineno;
                                    token->numToken = tokenNum++;
                                    token->content = strdup(yytext);
                                    token->type = REALCONST;  
                                    token->tokUpp = yytext;
                                    token->instance = "real";
                                    return REALCONST;
                                }

    /* WhiteSpaces */
{WhiteSpace}+   {} 

%%


int main(int argc, char* argv[]) {
     // Check if the correct number of arguments are provided
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> [output_file]" << std::endl;
        return 1;
    }

    // Open the input file
    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
        return 1;
    }

    // If an output file is provided, open it for writing
    std::ofstream outputFile;
    if (argc == 3) {
        outputFile.open(argv[2]);
        if (!outputFile) {
            std::cerr << "Error: Could not open output file " << argv[2] << std::endl;
            fclose(inputFile);
            return 1;
        }
    } else {
        // If no output file, default to printing to console
        outputFile.setstate(std::ios::failbit);
    }

    // Set the input file for the scanner
    yyin = inputFile;

    // Get the first token
    alpha_token_t* token = alpha_yylex();

    // Loop through all the tokens
    while (token) {
        enqueueToken(token);
        // Get the next token
        token = alpha_yylex();
    }

    // Print the tokens
    printQueue();

    // Close the input and output files
    fclose(inputFile);
    if (outputFile.is_open()) {
        outputFile.close();
    }

    return 0;
}