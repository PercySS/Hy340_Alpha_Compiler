%{
#include "../src/al.hpp"

extern int tokenNum;
extern int inmlcomment;
extern int inslcomment;
extern int instring;
int nest_level = 0;
int currline;
int prev_state;

%}

/* Options  section */
%option header-file="scanner.hpp"
%option noyywrap
%option yylineno
%option nounput
%option noinput

%x COMMENT NESTED


Alpha       [a-zA-Z]
Digit       [0-9]
WhiteSpace  [ \t]
NL          \n
WINLN       [\r\n]
MACLN       [\r]



/* Token Rules section */
%%
    /* Keywords */
"if"|"else"|"while"|"for"|"function"|"return"|"break"|"continue"|"true"|"false"|"nil"|"local"|"global"|"and"|"not"|"or"|"int"|"void"|"char"|"main"|"switch"|"case"|"default"|"do"|"double"|"float"|"long"|"short"|"unsigned"|"signed"|"const"|"static"|"extern"|"typedef"|"struct"|"union"|"enum"|"sizeof"|"volatile"|"goto" {
                                                                    
                                                                    if (inslcomment > 0) {
                                                                        return (TokenType)KEYWORD;
                                                                    }
                                                                    
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
                                                                if (inslcomment > 0) {
                                                                    return (TokenType)OPERATOR;
                                                                }  
                
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
                                                                if (inslcomment > 0) {
                                                                    return (TokenType)PUNCTUATION;
                                                                }
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
                                    if (inslcomment > 0) {
                                        return (TokenType)IDENTIFIER;
                                    }

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
                                    if (inslcomment > 0) {
                                        return (TokenType)INTCONST;
                                    }
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
                                    if (inslcomment > 0) {
                                        return (TokenType)REALCONST;
                                    }

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

    /* String Literals */
"\""                            { }


    /* Single Line Comments */
"//"                            {   
                                    if (inslcomment > 0) {
                                        return (TokenType)COMMENT;
                                    }

                                    inslcomment++;

                                    /* token for comment */
                                    alpha_token_t* token = new alpha_token_t();
                                    
                                    /* token and res for iterating */
                                    alpha_token_t* token2 = new alpha_token_t();
                                    int res = 0;

                                    /* Load the token with the necessary information */
                                    token->line = yylineno;
                                    token->numToken = tokenNum++;
                                    token->type = (TokenType)COMMENT;
                                    token->content = "\" \"";
                                    token->instance = "enumerated";
                                    token->tokUpp = "SL_COMMENT";
                                    
                                    /* eat other tokens till i find a new line */
                                    res = alpha_yylex(token2);
                                    while (res != (TokenType)NL) {
                                        res = alpha_yylex(token2);
                                    }

                                    inslcomment--;

                                    delete token2;
                                    enqueueToken(token);
                                }


    /* Multi Line Comments */
"/*"                            {   
                                    if (inslcomment > 0) {
                                        return (TokenType)COMMENT;
                                    }
                                    nest_level++;
                                    alpha_token_t* token = new alpha_token_t();
                                    token->line = yylineno;
                                    token->numToken = tokenNum++;
                                    token->type = (TokenType)COMMENT;
                                    token->content = "\"" + to_string(token->line) + " - ";
                                    
                                    prev_state = YY_START;

                                    BEGIN(COMMENT);
                                }

<COMMENT> {
    "*/" {   
        nest_level--;  
        token->content += yylineno;
        if (nest_level == 0) {
            BEGIN(prev_state);
        }
    }

    "/*" {                       
        nest_level++;
        prev_state = YY_START;
        alpha_token_t* token = new alpha_token_t();
        token->line = yylineno;
        token->numToken = tokenNum++;
        token->type = (TokenType)COMMENT;
        token->content = "\"" + to_string(token->line) + " - ";
        token->instance = "enumerated";
        token->tokUpp = "BLOCK_COMMENT";

        BEGIN(NESTED);
    }   

    <<EOF>> {           
        fprintf(stderr, "Error: Unterminated comment!\n"); 
        yyterminate(); 
    }

    .{ }

}

<NESTED> {
    "*/" {   
        nest_level--;
        token->content += std::to_string(yylineno);
        
        if (nest_level == 0) {
            BEGIN(prev_state); 
        }
    }

    "/*" {   
        nest_level++;
        prev_state = YY_START;

        alpha_token_t* token = new alpha_token_t();
        token->line = yylineno;
        token->numToken = tokenNum++;
        token->type = (TokenType)COMMENT;
        token->content = "\"" + to_string(token->line) + " - ";
        token->instance = "enumerated";
        token->tokUpp = "NESTED_BL_COMMENT";

        BEGIN(NESTED);
    }

    <<EOF>> {   
        fprintf(stderr, "Error: Unterminated comment!\n"); 
        yyterminate(); 
    }

    . { } 
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
            if (inmlcomment > 0) return (TokenType)ERROR_COMMENT;
            
            if (instring > 0) return (TokenType)ERROR_STRING; 
            
            return (TokenType)END; 
        }

. { return (TokenType)UNEXPECTED; }
%%