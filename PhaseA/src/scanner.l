%{
#include "../src/al.hpp"

extern int tokenNum;
stack<int> tokenStack;
string tempString = "";
string tempStringRaw = "";
%}

/* Options  section */
%option c++
%option yyclass="MyParser::parser"
%option header-file="scanner.hpp"
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
"+"|"-"|"*"|"/"|"%"|"="|"=="|"!="|"<"|"<="|">"|">="|"++"|"--" { 
                
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
"("|")"|"{"|"}"|"["|"]"|";"|","|":"|"::"|"."|".." { 
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
{Digit}+                        { 
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
    /* Strings */
"\""                            { 
                                    BEGIN(STRING);
                                    tempString.append("\"");
                                    tempStringRaw.append("\"");
                                    return (TokenType)STRING;
                                }

<STRING>\"                      {   
                                    alpha_token_t* token = new alpha_token_t();
                                    tempString.append("\"");
                                    tempStringRaw.append("\"");
                                    token->line = yylineno;
                                    token->numToken = tokenNum++;
                                    token->type = (TokenType)STRING;
                                    token->content = tempString;
                                    token->instance = "char*";
                                    token->tokUpp = tempStringRaw;

                                    enqueueToken(token);
                                    tempString = "";
                                    tempStringRaw = "";
                                    BEGIN(INITIAL);
                                    return (TokenType)STRING;
                                }

<STRING>{NL}|{WINLN}|{MACLN}    {                     
                                    tempString.append("\n");
                                    tempStringRaw.append("\n");
                                    return (TokenType)STRING;
                                }
    /* escaped cahracters */
<STRING>"\\n"                   { 
                                    tempString.append("\n");
                                    tempStringRaw.append(yytext);
                                }


<STRING>"\\t"                   { 
                                    tempString.append("\t"); 
                                    tempStringRaw.append(yytext);
                                }

<STRING>"\\r"                   { 
                                    tempString.append("\r");
                                    tempStringRaw.append(yytext);
                                }   

<STRING>"\\\""                  { 
                                    tempString.append("\"");
                                    tempStringRaw.append(yytext); 
                                }

<STRING>"\\\'"                  { 
                                    tempString.append("\'");
                                    tempStringRaw.append(yytext);
                                }

<STRING>"\\\\"                    { 
                                    tempString.append("\\");
                                    tempStringRaw.append(yytext);
                                }

    /* Invalid Escapes */
<STRING>"\\".                   { 
                                    illegal_escape(yytext, yylineno);
                                    return (TokenType)ERROR_STRING;
                                }



<STRING>.                       { 
                                    tempString.append(yytext);
                                    tempStringRaw.append(yytext);
                                }

<STRING><<EOF>>                 {
                                    illegal_string(yylineno);
                                    return (TokenType)ERROR_STRING;
                                }

    /* Single Line Comments */
"//"                            { 
                                    BEGIN(SLCOMMENT);
                                }

<SLCOMMENT>.+                   { 
                                    return (TokenType)COMMENT;
                                }

<SLCOMMENT>{NL}|{WINLN}|{MACLN}     {   
                                        alpha_token_t* token = new alpha_token_t();

                                        token->line = yylineno - 1;
                                        token->numToken = tokenNum++;
                                        token->type = (TokenType)COMMENT;
                                        token->content = "\" \"";
                                        token->instance = "enumerated";
                                        token->tokUpp = "SL_COMMENT";

                                        enqueueToken(token);
                                        BEGIN(INITIAL);
                                        
                                        return (TokenType)COMMENT;
                                    }


    /* Multi Line Comments */
"/*"                            {   
                                    tokenStack.push(yylineno);
                                    BEGIN(COMMENT);
                                    return (TokenType)COMMENT;
                                }

<COMMENT>"*/"                   {
                                    alpha_token_t* token = new alpha_token_t();
                                    token->line = tokenStack.top();
                                    token->numToken = tokenNum++;
                                    token->type = (TokenType)COMMENT;
                                    token->content = "\"" + intToString(token->line) + "-" + intToString(yylineno) + "\"";
                                    token->instance = "enumerated";
                                    token->tokUpp = "ML_COMMENT";

                                    enqueueToken(token);
                                    tokenStack.pop();
                                    BEGIN(INITIAL);
                                    return (TokenType)COMMENT; 
                                }

<COMMENT>{NL}|{WINLN}|{MACLN}   {
                                    return (TokenType)NL;
                                }

<COMMENT><<EOF>>                { 
                                    illegal_comment(tokenStack.top());
                                    return (TokenType)ERROR_COMMENT;
                                }

<COMMENT>.                      { 
                                    return (TokenType)COMMENT;
                                }

<COMMENT>"/*"                   { 
                                    tokenStack.push(yylineno);
                                    BEGIN(NESTED);
                                    return (TokenType)COMMENT;
                                }

<NESTED>"*/"                    { 
                                    alpha_token_t* token = new alpha_token_t();
                                    token->line = tokenStack.top();
                                    token->numToken = tokenNum++;
                                    token->type = (TokenType)COMMENT;
                                    token->content = "\"" + intToString(token->line) + "-" + intToString(yylineno) + "\"";
                                    token->instance = "enumerated";
                                    token->tokUpp = "NESTED_ML_COMMENT";

                                    enqueueToken(token);
                                    tokenStack.pop();
                                    
                                    if (tokenStack.size() > 1) {
                                        BEGIN(NESTED);
                                    } else {
                                        BEGIN(COMMENT);
                                    }
                                    return (TokenType)COMMENT;
                                }

<NESTED>{NL}|{WINLN}|{MACLN}    {
                                    return (TokenType)NL;
                                }

<NESTED><<EOF>>                 { 
                                    illegal_comment(tokenStack.top());
                                    return (TokenType)ERROR_COMMENT;
                                }

<NESTED>.                       { 
                                    return (TokenType)COMMENT;
                                }

<NESTED>"/*"                    {
                                    tokenStack.push(yylineno);
                                    BEGIN(NESTED);
                                    return (TokenType)COMMENT;
                                }



    /* WhiteSpaces */
{WhiteSpace}+                   {  
                                    return (TokenType)WS;
                                } 

    /* New Line  for all environments */
{NL}|{WINLN}|{MACLN}            { 
                                    return (TokenType)NL;
                                }


    /* EOF */
<<EOF>> {
            return (TokenType)END; 
        }

.       {
            illegal_token(yytext, yylineno);
            return (TokenType)UNEXPECTED;
        }
%%