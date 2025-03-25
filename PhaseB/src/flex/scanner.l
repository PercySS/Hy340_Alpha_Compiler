%{
#include <memory>
#include <string>
#include <iostream>
#include "../yacc/parser.tab.hpp"

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

stack<int> tokenStack;

%}

/* Options  section */
%option c++
%option yyclass="MyParser::parser"
%option noyywrap
%option yylineno
%option nounput
%option noinput

%x COMMENT NESTED SLCOMMENT STRING


Alpha       [a-zA-Z]
Digit       [0-9]
WhiteSpace  [ \t]
NL          \n
WINLN       [\r\n]
MACLN       [\r]



/* Tok` Rules section */
%%
    /* Keywords */
"if"|"else"|"while"|"for"|"function"|"return"|"break"|"continue"|"true"|"false"|"nil"|"and"|"not"|"or"|"local" {                                
                                                                    if (strcmp(yytext, "if") == 0) {
                                                                        return IF;
                                                                    } else if (strcmp(yytext, "else") == 0) {
                                                                        return ELSE;
                                                                    } else if (strcmp(yytext, "while") == 0) {
                                                                        return WHILE;
                                                                    } else if (strcmp(yytext, "for") == 0) {
                                                                        return FOR;
                                                                    } else if (strcmp(yytext, "function") == 0) {
                                                                        return FUNCTION;
                                                                    } else if (strcmp(yytext, "return") == 0) {
                                                                        return RETURN;
                                                                    } else if (strcmp(yytext, "break") == 0) {
                                                                        return BREAK;
                                                                    } else if (strcmp(yytext, "continue") == 0) {
                                                                        return CONTINUE;
                                                                    } else if (strcmp(yytext, "true") == 0) {
                                                                        return TRUE;
                                                                    } else if (strcmp(yytext, "false") == 0) {
                                                                        return FALSE;
                                                                    } else if (strcmp(yytext, "nil") == 0) {
                                                                        return NIL;
                                                                    } else if (strcmp(yytext, "and") == 0) {
                                                                        return AND;
                                                                    } else if (strcmp(yytext, "not") == 0) {
                                                                        return NOT;
                                                                    } else if (strcmp(yytext, "or") == 0) {
                                                                        return OR;
                                                                    } else if (strcmp(yytext, "local") == 0) {
                                                                        return LOCAL;
                                                                    }
                                                                }



    /* Operators */
"+"|"-"|"*"|"/"|"%"|"="|"=="|"!="|"<"|"<="|">"|">="|"++"|"--" {
                                                                if (strcmp(yytext, "+") == 0) {
                                                                    return PLUS;
                                                                } else if (strcmp(yytext, "-") == 0) {
                                                                    return MINUS;
                                                                } else if (strcmp(yytext, "*") == 0) {
                                                                    return MULTIPLY;
                                                                } else if (strcmp(yytext, "/") == 0) {
                                                                    return DIVIDE;
                                                                } else if (strcmp(yytext, "%") == 0) {
                                                                    return MODULO;
                                                                } else if (strcmp(yytext, "=") == 0) {
                                                                    return ASSIGN;
                                                                } else if (strcmp(yytext, "==") == 0) {
                                                                    return EQUAL;
                                                                } else if (strcmp(yytext, "!") == 0) {
                                                                    return NOTOP;
                                                                } else if (strcmp(yytext, "!=") == 0) {
                                                                    return NOT_EQUAL;
                                                                } else if (strcmp(yytext, "<") == 0) {
                                                                    return LESS_THAN;
                                                                } else if (strcmp(yytext, "<=") == 0) {
                                                                    return LESS_THAN_EQUAL;
                                                                } else if (strcmp(yytext, ">") == 0) {
                                                                    return GREATER_THAN;
                                                                } else if (strcmp(yytext, ">=") == 0) {
                                                                    return GREATER_THAN_EQUAL;
                                                                } else if (strcmp(yytext, "++") == 0) {
                                                                    return INCREMENT;
                                                                } else if (strcmp(yytext, "--") == 0) {
                                                                    return DECREMENT;
                                                                } else if (strcmp(yytext, "+=") == 0) {
                                                                    return PLUS_ASSIGN;
                                                                } else if (strcmp(yytext, "-=") == 0) {
                                                                    return MINUS_ASSIGN;
                                                                } else if (strcmp(yytext, "*=") == 0) {
                                                                    return MULTIPLY_ASSIGN;
                                                                } else if (strcmp(yytext, "/=") == 0) {
                                                                    return DIVIDE_ASSIGN;
                                                                } else if (strcmp(yytext, "%=") == 0) {
                                                                    return MODULO_ASSIGN;
                                                                }
                                                            }

    /* Delimiters */
"("|")"|"{"|"}"|"["|"]"|";"|","|":"|"::"|"."|".." {

                                                                if (strcmp(yytext, "(") == 0) {
                                                                    return LEFT_PARENTHESIS;
                                                                } else if (strcmp(yytext, ")") == 0) {
                                                                    return RIGHT_PARENTHESIS;
                                                                } else if (strcmp(yytext, "{") == 0) {
                                                                    return LEFT_BRACE;
                                                                } else if (strcmp(yytext, "}") == 0) {
                                                                    return RIGHT_BRACE;
                                                                } else if (strcmp(yytext, "[") == 0) {
                                                                    return LEFT_BRACKET;
                                                                } else if (strcmp(yytext, "]") == 0) {
                                                                    return RIGHT_BRACKET;
                                                                } else if (strcmp(yytext, ";") == 0) {
                                                                    return SEMICOLON;
                                                                } else if (strcmp(yytext, ",") == 0) {
                                                                    return COMMA;
                                                                } else if (strcmp(yytext, ":") == 0) {
                                                                    return COLON;
                                                                } else if (strcmp(yytext, "::") == 0) {
                                                                    return DOUBLE_COLON;
                                                                } else if (strcmp(yytext, "->") == 0) {
                                                                    return ARROW;
                                                                } else if (strcmp(yytext, ".") == 0) {
                                                                    return DOT;
                                                                } else if (strcmp(yytext, "..") == 0) {
                                                                    return DOUBLE_DOT;
                                                                } else if (strcmp(yytext, "?") == 0) {
                                                                    return TURNARY;
                                                                }
                                                            }

    /* Identifiers */   
{Alpha}({Alpha}|{Digit}|_)*     {
                                    yylval.emplace<std::string>(yytext);
                                    return IDENTIFIER;
                                }
    
    /* Constants */
{Digit}+                        {
                                    yylval.emplace<int>(atoi(yytext));
                                    return INTEGER;
                                }

{Digit}+"."{Digit}+             {
                                    yylval.emplace<float>(atof(yytext));
                                    return REAL;
                                }
    /* Strings */
"\""                            { 
                                    yylval.emplace<std::string>(""); // we initialize the string with an empty string
                                    BEGIN(STRING);
                                }

<STRING>\"                      {
                                    BEGIN(INITIAL);
                                    return STRING;
                                }

<STRING>{NL}|{WINLN}|{MACLN}    {                     
                                    std::get<std::string>(yylval) += '\n';
                                    return STRING;
                                }
    /* escaped cahracters */
<STRING>"\\n"                   { 
                                    std::get<std::string>(yylval) += '\n';
                                }


<STRING>"\\t"                   { 
                                    std::get<std::string>(yylval) += '\t';
                                }

<STRING>"\\r"                   { 
                                    std::get<std::string>(yylval) += '\r';
                                }   

<STRING>"\\\""                  { 
                                    std::get<std::string>(yylval) += '\"';
                                }

<STRING>"\\\'"                  { 
                                    std::get<std::string>(yylval) += '\'';
                                }

<STRING>"\\\\"                    { 
                                    std::get<std::string>(yylval) += '\\';
                                }

    /* Invalid Escapes */
<STRING>"\\".                   { 
                                    yyerror("Invalid escape sequence", yylineno);
                                    return ERROR_STRING;
                                }



<STRING>.                       { 
                                    std::get<std::string>(yylval) += yytext;
                                }

<STRING><<EOF>>                 {
                                    yyerrror("Unterminated string", yylineno);
                                    return ERROR_STRING;
                                }

    /* Single Line Comments */
"//"                            { 
                                    BEGIN(SLCOMMENT);
                                }

<SLCOMMENT>.+                   { }

<SLCOMMENT>{NL}|{WINLN}|{MACLN}     {    
                                        BEGIN(INITIAL);
                                        
                                        return  COMMENT;
                                    }


    /* Multi Line Comments */
"/*"                            {   
                                    tokenStack.push(yylineno);
                                    BEGIN(COMMENT);
                                    return (TokenType)COMMENT;
                                }

<COMMENT>"*/"                   { 
                                    tokenStack.pop();
                                    BEGIN(INITIAL);
                                    return COMMENT; 
                                }

<COMMENT>{NL}|{WINLN}|{MACLN}   { }

<COMMENT><<EOF>>                { 
                                    yyerror("Unterminated comment", yylineno);
                                    return ERROR_COMMENT;
                                }

<COMMENT>.                      { }

<COMMENT>"/*"                   { 
                                    tokenStack.push(yylineno);
                                    BEGIN(NESTED);
                                }

<NESTED>"*/"                    { 
                                    tokenStack.pop();
                                    
                                    if (tokenStack.size() > 1) {
                                        BEGIN(NESTED);
                                    } else {
                                        BEGIN(COMMENT);
                                    }
                                    return COMMENT;
                                }

<NESTED>{NL}|{WINLN}|{MACLN}    { }

<NESTED><<EOF>>                 { 
                                    yyerror("Unterminated comment", yylineno);
                                    return ERROR_COMMENT;
                                }

<NESTED>.                       { }

<NESTED>"/*"                    {
                                    tokenStack.push(yylineno);
                                    BEGIN(NESTED);
                                    return COMMENT;
                                }



    /* WhiteSpaces */
{WhiteSpace}+                   { } 

    /* New Line  for all environments */
{NL}|{WINLN}|{MACLN}            { }


    /* EOF */
<<EOF>> {
            return END; 
        }

.       {
            yyerror("Unexpected character", yylineno);
            return UNEXPECTED;
        }
%%