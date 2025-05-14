%{
#include "parser.tab.hpp"
#include "../src/symtable.hpp"

extern void yyerror(const char* msg);

std::stack<int> tokenStack;

static char* string_buffer = NULL;
static size_t string_bufsize = 0;
static size_t string_len = 0;

void reset_string_buffer() {
    free(string_buffer);
    string_buffer = NULL;
    string_bufsize = 0;
    string_len = 0;
}

void append_to_string_buffer(const char* text) {
    size_t new_len = string_len + strlen(text) + 1;
    if (new_len > string_bufsize) {
        string_bufsize = new_len * 2;
        string_buffer = (char*)realloc(string_buffer, string_bufsize);
    }
    strcpy(string_buffer + string_len, text);
    string_len += strlen(text);
}

%}

/* Options  section */
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



/* Token Rules section */
%%
    /* Keywords */
"if"|"else"|"while"|"for"|"function"|"return"|"break"|"continue"|"true"|"false"|"nil"|"and"|"not"|"or"|"local" {                                
                                                                    if (strcmp(yytext, "if") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: IF\n");
                                                                        return IF;
                                                                    } else if (strcmp(yytext, "else") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: ELSE\n");
                                                                        return ELSE;
                                                                    } else if (strcmp(yytext, "while") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: WHILE\n");
                                                                        return WHILE;
                                                                    } else if (strcmp(yytext, "for") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: FOR\n");
                                                                        return FOR;
                                                                    } else if (strcmp(yytext, "function") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: FUNCTION\n");
                                                                        return FUNCTION;
                                                                    } else if (strcmp(yytext, "return") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: RETURN\n");
                                                                        return RETURN;
                                                                    } else if (strcmp(yytext, "break") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: BREAK\n");
                                                                        return BREAK;
                                                                    } else if (strcmp(yytext, "continue") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: CONTINUE\n");
                                                                        return CONTINUE;
                                                                    } else if (strcmp(yytext, "true") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: TRUE\n");
                                                                        return TRUE;
                                                                    } else if (strcmp(yytext, "false") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: FALSE\n");
                                                                        return FALSE;
                                                                    } else if (strcmp(yytext, "nil") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: NIL\n");
                                                                        return NIL;
                                                                    } else if (strcmp(yytext, "and") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: AND\n");
                                                                        return AND;
                                                                    } else if (strcmp(yytext, "not") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: NOT\n");
                                                                        return NOT;
                                                                    } else if (strcmp(yytext, "or") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: OR\n");
                                                                        return OR;
                                                                    } else if (strcmp(yytext, "local") == 0) {
                                                                        fprintf(yyout, "[+] Shift token keyword: LOCAL\n");
                                                                        return LOCAL;
                                                                    }
                                                                }



    /* Operators */
"+"|"-"|"*"|"/"|"%"|"="|"=="|"!="|"<"|"<="|">"|">="|"++"|"--"|"+="|"-=" {
                                                                if (strcmp(yytext, "+") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: PLUS\n");
                                                                    return PLUS;
                                                                } else if (strcmp(yytext, "-") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: MINUS\n");
                                                                    return MINUS;
                                                                } else if (strcmp(yytext, "*") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: MULTIPLY\n");
                                                                    return MULTIPLY;
                                                                } else if (strcmp(yytext, "/") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: DIVIDE\n");
                                                                    return DIVIDE;
                                                                } else if (strcmp(yytext, "%") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: MODULO\n");
                                                                    return MODULO;
                                                                } else if (strcmp(yytext, "=") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: ASSIGN\n");
                                                                    return ASSIGN;
                                                                } else if (strcmp(yytext, "==") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: EQUAL\n");
                                                                    return EQUAL;
                                                                } else if (strcmp(yytext, "!") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: NOT_EQUAL\n");
                                                                    return NOT_EQUAL;
                                                                } else if (strcmp(yytext, "!=") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: NOT_EQUAL\n");
                                                                    return NOT_EQUAL;
                                                                } else if (strcmp(yytext, "<") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: LESS_THAN\n");
                                                                    return LESS_THAN;
                                                                } else if (strcmp(yytext, "<=") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: LESS_THAN_EQUAL\n");
                                                                    return LESS_THAN_EQUAL;
                                                                } else if (strcmp(yytext, ">") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: GREATER_THAN\n");
                                                                    return GREATER_THAN;
                                                                } else if (strcmp(yytext, ">=") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: GREATER_THAN_EQUAL\n");
                                                                    return GREATER_THAN_EQUAL;
                                                                } else if (strcmp(yytext, "++") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: INCREMENT\n");
                                                                    return INCREMENT;
                                                                } else if (strcmp(yytext, "--") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: DECREMENT\n");
                                                                    return DECREMENT;
                                                                } else if (strcmp(yytext, "+=") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: PLUS_ASSIGN\n");
                                                                    return PLUS_ASSIGN;
                                                                } else if (strcmp(yytext, "-=") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: MINUS_ASSIGN\n");
                                                                    return MINUS_ASSIGN;
                                                                } else if (strcmp(yytext, "*=") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: MULTIPLY_ASSIGN\n");
                                                                    return PLUS_ASSIGN;
                                                                } else if (strcmp(yytext, "/=") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: DIVIDE_ASSIGN\n");
                                                                    return PLUS_ASSIGN;
                                                                } else if (strcmp(yytext, "%=") == 0) {
                                                                    fprintf(yyout, "[+] Shift token operator: MODULO_ASSIGN\n");
                                                                    return PLUS_ASSIGN;
                                                                }
                                                            }

    /* Delimiters */
"("|")"|"{"|"}"|"["|"]"|";"|","|":"|"::"|"."|".." {

                                                                if (strcmp(yytext, "(") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: LEFT_PARENTHESIS\n");
                                                                    return LEFT_PARENTHESIS;
                                                                } else if (strcmp(yytext, ")") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: RIGHT_PARENTHESIS\n");
                                                                    return RIGHT_PARENTHESIS;
                                                                } else if (strcmp(yytext, "{") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: LEFT_BRACE\n");
                                                                    return LEFT_BRACE;
                                                                } else if (strcmp(yytext, "}") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: RIGHT_BRACE\n");
                                                                    return RIGHT_BRACE;
                                                                } else if (strcmp(yytext, "[") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: LEFT_BRACKET\n");
                                                                    return LEFT_BRACKET;
                                                                } else if (strcmp(yytext, "]") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: RIGHT_BRACKET\n");
                                                                    return RIGHT_BRACKET;
                                                                } else if (strcmp(yytext, ";") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: SEMICOLON\n");
                                                                    return SEMICOLON;
                                                                } else if (strcmp(yytext, ",") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: COMMA\n");
                                                                    return COMMA;
                                                                } else if (strcmp(yytext, ":") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: COLON\n");
                                                                    return COLON;
                                                                } else if (strcmp(yytext, "::") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: DOUBLE_COLON\n");
                                                                    return DOUBLE_COLON;
                                                                } else if (strcmp(yytext, "->") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: ARROW\n");
                                                                    return PLUS;
                                                                } else if (strcmp(yytext, ".") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: DOT\n");
                                                                    return DOT;
                                                                } else if (strcmp(yytext, "..") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: DOUBLE_DOT\n");
                                                                    return DOUBLE_DOT;
                                                                } else if (strcmp(yytext, "?") == 0) {
                                                                    fprintf(yyout, "[+] Shift token delimiter: TURNARY\n");
                                                                    return PLUS;
                                                                }
                                                            }

    /* Identifiers */   
{Alpha}({Alpha}|{Digit}|_)*     {
                                    fprintf(yyout, "[+] Shift token identifier: %s\n", yytext);
                                    yylval.str_val = strdup(yytext);
                                    return IDENTIFIER;
                                }
    
    /* Constants */
{Digit}+                        {   
                                    fprintf(yyout, "[+] Shift token integer: %s\n", yytext);
                                    yylval.int_val = atoi(yytext);
                                    return INTEGER;
                                }

{Digit}+"."{Digit}+             {   
                                    fprintf(yyout, "[+] Shift token real: %s\n", yytext);
                                    yylval.float_val = atof(yytext);
                                    return REAL;
                                }
    /* Strings */
\"                              { 
                                    reset_string_buffer(); // we make a clean buffer for the string
                                    BEGIN(STRING);
                                }

    /* escaped cahracters */
<STRING>"\\n"                   { 
                                    append_to_string_buffer("\n");
                                }


<STRING>"\\t"                   { 
                                    append_to_string_buffer("\t");
                                }

<STRING>"\\r"                   { 
                                    append_to_string_buffer("\r");
                                }   

<STRING>"\\\""                  { 
                                    append_to_string_buffer("\"");
                                }

<STRING>"\\\'"                  { 
                                    append_to_string_buffer("\'");
                                }

<STRING>"\\\\"                  { 
                                    append_to_string_buffer("\\");
                                }

<STRING>{NL}|{WINLN}|{MACLN}    {
                                    append_to_string_buffer("\n");
                                }

<STRING>\"                      {   
                                    string_buffer[string_len] = '\0'; // null-terminate the string
                                    yylval.str_val = strdup(string_buffer);

                                    fprintf(yyout, "[+] Shift token string: %s\n", yylval.str_val);

                                    BEGIN(INITIAL);
                                    return STRINGT;
                                }


<STRING>.                       {
                                    append_to_string_buffer(yytext);
                                }

    /* Invalid Escapes */
<STRING>"\\".                   {
                                    return ERROR_ESCAPE;
                                }




<STRING><<EOF>>                 {
                                    return ERROR_STRING;
                                }


    /* Single Line Comments */
"//"                            { 
                                    BEGIN(SLCOMMENT);
                                }

<SLCOMMENT>.+                   { }

<SLCOMMENT>{NL}|{WINLN}|{MACLN}     {    
                                        fprintf(yyout, "[+] Shift token single-line comment (ignored).\n");
                                        BEGIN(INITIAL);
                                    }


    /* Multi Line Comments */
"/*"                            {   
                                    tokenStack.push(yylineno);
                                    BEGIN(COMMENT);
                                }

<COMMENT>"*/"                   {   
                                    fprintf(yyout, "[+] Shift token multi-line comment (ignored).\n");
                                    tokenStack.pop();
                                    BEGIN(INITIAL); 
                                }

<COMMENT>{NL}|{WINLN}|{MACLN}   { }

<COMMENT><<EOF>>                {
                                    return ERROR_COMMENT;
                                }

<COMMENT>.                      { }

<COMMENT>"/*"                   { 
                                    tokenStack.push(yylineno);
                                    BEGIN(NESTED);
                                }

<NESTED>"*/"                    {   
                                    fprintf(yyout, "[+] Shift token nested comment (ignored).\n");
                                    tokenStack.pop();
                                    
                                    if (tokenStack.size() > 1) {
                                        BEGIN(NESTED);
                                    } else {
                                        BEGIN(COMMENT);
                                    }
                                }

<NESTED>{NL}|{WINLN}|{MACLN}    { }

<NESTED><<EOF>>                 {
                                    return ERROR_COMMENT;
                                }

<NESTED>.                       { }

<NESTED>"/*"                    {
                                    tokenStack.push(yylineno);
                                    BEGIN(NESTED);
                                }



    /* WhiteSpaces */
{WhiteSpace}+                   { } 

    /* New Line  for all environments */
{NL}|{WINLN}|{MACLN}            { }


    /* EOF */
<<EOF>> {   
            fprintf(yyout, "[+] Shift token EOF.\n");
            return EOF; 
        }

.       {   
            fprintf(yyout, "[-] Error: Unrecognized token: %s\n", yytext);
            return UNDEF;
        }
%%