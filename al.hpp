#ifndef AL_HPP
#define AL_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <fstream>


using namespace std;


typedef enum TokenType {
    INTCONST,
    REALCONST,
    STRING,
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    LEFT_BRACE,
    RIGHT_BRACE,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    SEMICOLON,
    COMMA,
    COLON,
    DOUBLE_COLON,
    ARROW,
    SCOPE,
    DOT,
    DOTDOT,
    TURNARY,
    COMMENT
} TokenType;

typedef struct alpha_token {
    int line;
    int numToken;
    string content;
    TokenType type;
    string tokUpp;
    string instance;
} alpha_token_t;

// external variables 
extern int line;
extern int tokenNum;
extern int incomment;
extern int instring;
extern queue<alpha_token_t*> tokenQueue;
extern char* yytext;
extern int yylineno;
extern FILE* yyin;




// Methods to be used in the driver program
string toUpper(string str);

string intToString(int num);

string enumToString(enum TokenType type);

void printQueue();

void enqueueToken(alpha_token_t* token);

alpha_token_t* alpha_yylex();


#endif // AL_HPP