%{
#include "../src/al.hpp"

extern int tokenNum;
%}

/* Options  section */
%option header-file="scanner.hpp"
%option noyywrap
%option yylineno
%option nounput
%option noinput


Alpha       [a-zA-Z]
Digit       [0-9]
WhiteSpace  [ \t\n]
LineEnd     \n



/* Token Rules section */
%%
    /* Keywords */
"if"|"else"|"while"|"for"|"function"|"return"|"break"|"continue"|"true"|"false"|"nil"|"local"|"global"|"and"|"not"|"or"|"int"|"void"|"char"|"main"|"switch"|"case"|"default"|"do"|"double"|"float"|"long"|"short"|"unsigned"|"signed"|"const"|"static"|"extern"|"typedef"|"struct"|"union"|"enum"|"sizeof"|"volatile"|"goto" {
                alpha_token_t* token = new alpha_token_t();
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->type = (TokenType)KEYWORD;
                token->content = yytext;
                token->instance = "enumerated";
                token->tokUpp = toUpper(token->content);

                enqueueToken(token);
                
                return (TokenType)KEYWORD;
            }



    /* Operators */
"+"|"-"|"*"|"/"|"%"|"="|"=="|"!"|"!="|"<"|"<="|">"|">="|"++"|"--"|"+="|"-="|"*="|"/="|"%=" {   
                
                alpha_token_t* token = new alpha_token_t();
                
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->type = (TokenType)OPERATOR;
                token->content = yytext;
                token->instance = "enumerated";
                
                if (strcmp(yytext, "+") == 0) {
                    token->tokUpp = "PLUS";
                } else if (strcmp(yytext, "-") == 0) {
                    token->tokUpp = "MINUS";
                } else if (strcmp(yytext, "*") == 0) {
                    token->tokUpp = "MULTIPLY";
                } else if (strcmp(yytext, "/") == 0) {
                    token->tokUpp = "DIVIDE";
                } else if (strcmp(yytext, "%") == 0) {
                    token->tokUpp = "MODULO";
                } else if (strcmp(yytext, "=") == 0) {
                    token->tokUpp = "ASSIGN";
                } else if (strcmp(yytext, "==") == 0) {
                    token->tokUpp = "EQUAL";
                } else if (strcmp(yytext, "!") == 0) {
                    token->tokUpp = "NOT";
                } else if (strcmp(yytext, "!=") == 0) {
                    token->tokUpp = "NOT_EQUAL";
                } else if (strcmp(yytext, "<") == 0) {
                    token->tokUpp = "LESS_THAN";
                } else if (strcmp(yytext, "<=") == 0) {
                    token->tokUpp = "LESS_THAN_EQUAL";
                } else if (strcmp(yytext, ">") == 0) {
                    token->tokUpp = "GREATER_THAN";
                } else if (strcmp(yytext, ">=") == 0) {
                    token->tokUpp = "GREATER_THAN_EQUAL";
                } else if (strcmp(yytext, "++") == 0) {
                    token->tokUpp = "INCREMENT";
                } else if (strcmp(yytext, "--") == 0) {
                    token->tokUpp = "DECREMENT";
                } else if (strcmp(yytext, "+=") == 0) {
                    token->tokUpp = "PLUS_ASSIGN";
                } else if (strcmp(yytext, "-=") == 0) {
                    token->tokUpp = "MINUS_ASSIGN";
                } else if (strcmp(yytext, "*=") == 0) {
                    token->tokUpp = "MULTIPLY_ASSIGN";
                } else if (strcmp(yytext, "/=") == 0) {
                    token->tokUpp = "DIVIDE_ASSIGN";
                } else if (strcmp(yytext, "%=") == 0) {
                    token->tokUpp = "MODULO_ASSIGN";
                }
                
                enqueueToken(token);
                return (TokenType)OPERATOR;
                
            }

    /* Delimiters */
"("|")"|"{"|"}"|"["|"]"|";"|","|":"|"::"|"->"|"."|".."|"?" { 
                
                alpha_token_t* token = new alpha_token_t();
                token->line = yylineno;
                token->numToken = tokenNum++;
                token->type = (TokenType)PUNCTUATION;
                token->content = yytext;
                token->instance = "enumerated";

                if (strcmp(yytext, "(") == 0) {
                    token->tokUpp = "LEFT_PARENTHESIS";
                } else if (strcmp(yytext, ")") == 0) {
                    token->tokUpp = "RIGHT_PARENTHESIS";
                } else if (strcmp(yytext, "{") == 0) {
                    token->tokUpp = "LEFT_BRACE";
                } else if (strcmp(yytext, "}") == 0) {
                    token->tokUpp = "RIGHT_BRACE";
                } else if (strcmp(yytext, "[") == 0) {
                    token->tokUpp = "LEFT_BRACKET";
                } else if (strcmp(yytext, "]") == 0) {
                    token->tokUpp = "RIGHT_BRACKET";
                } else if (strcmp(yytext, ";") == 0) {
                    token->tokUpp = "SEMICOLON";
                } else if (strcmp(yytext, ",") == 0) {
                    token->tokUpp = "COMMA";
                } else if (strcmp(yytext, ":") == 0) {
                    token->tokUpp = "COLON";
                } else if (strcmp(yytext, "::") == 0) {
                    token->tokUpp = "DOUBLE_COLON";
                } else if (strcmp(yytext, "->") == 0) {
                    token->tokUpp = "ARROW";
                } else if (strcmp(yytext, ".") == 0) {
                    token->tokUpp = "DOT";
                } else if (strcmp(yytext, "..") == 0) {
                    token->tokUpp = "DOUBLE_DOT";
                } else if (strcmp(yytext, "?") == 0) {
                    token->tokUpp = "TURNARY";
                }

                enqueueToken(token);
                return (TokenType)PUNCTUATION;
            }

    /* Identifiers */   
{Alpha}({Alpha}|{Digit}|_)*     { 
                                    alpha_token_t* token = new alpha_token_t();
                                    
                                    token->line = yylineno;
                                    token->numToken = tokenNum++;
                                    token->type = (TokenType)IDENTIFIER;
                                    token->content = yytext;
                                    token->tokUpp = token->content ;  
                                    token->instance = "char*";
                                    
                                    enqueueToken(token);
                                    return (TokenType)IDENTIFIER;
                                }
    
    /* Constants */
{Digit}+                { 

                            alpha_token_t* token = new alpha_token_t();
                            
                            token->line = yylineno;
                            token->numToken = tokenNum++;
                            token->type = (TokenType)INTCONST;
                            token->content = yytext;
                            token->instance = "integer";
                            token->tokUpp = yytext;
                            
                            enqueueToken(token);
                            return (TokenType)INTCONST;
                        }

{Digit}+"."{Digit}+             { 
                                    alpha_token_t* token = new alpha_token_t();
                                    
                                    token->line = yylineno;
                                    token->numToken = tokenNum++;
                                    token->type = (TokenType)REALCONST;
                                    token->content = yytext;
                                    token->instance = "float";
                                    token->tokUpp = yytext;
                                    
                                    enqueueToken(token);
                                    return (TokenType)REALCONST;
                                }

    /* WhiteSpaces */
{WhiteSpace}+   {;} 

    /* EOF */

.          { }

<<EOF>> { return (TokenType)END; }
%%