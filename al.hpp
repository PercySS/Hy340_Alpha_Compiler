#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>


using namespace std;

// External Vars from lex.yy.c
extern int yylex();
extern int yylineno;
extern char* yytext;

int tokCount = 0; // Ascending token counter


// Token structure
enum TokenType {
    UNEXPECTED = -1,
    INTCONST = 0,
    REALCONST = 1,
    STRING,
    COMMENTLINE,
    STARTBLOCKCOMMENT,
    ENDBLOCKCOMMENT,

};

// Token structure
struct alpha_token_t {
    unsigned int     numline;
    unsigned int     numToken;
    char          *content;
    char          *type;
    struct alpha_token_t *alpha_yylex;
  
};
