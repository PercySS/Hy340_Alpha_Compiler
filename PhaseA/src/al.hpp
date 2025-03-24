#ifndef AL_HPP
#define AL_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <fstream>
#include <cassert>
#include <cstring>

using namespace std;


typedef enum TokenType {
    ERROR_STRING = -4,
    ERROR_COMMENT = -3,
    UNEXPECTED = -2,
    END = -1,
    COMMENT = 1,
    INTCONST = 2,
    REALCONST,
    STRING,
    IDENTIFIER,
    NL,
    WS,
    KEYWORD,
    OPERATOR,
    PUNCTUATION
} TokenType;

typedef struct alpha_token {
    int line;
    int numToken;
    string content;
    TokenType type;
    string tokUpp;
    string instance;
} alpha_token_t;


// Methods to be used in the driver program
string toUpper(string str);

string intToString(int num);

string enumToString(enum TokenType type);

void printQueue();

void enqueueToken(alpha_token_t* token);

int alpha_yylex(void* token);

void illegal_comment(int line);

void illegal_string(int line);

void illegal_token(char* yytext, int line);

void illegal_escape(char* yytext, int line);
#endif // AL_HPP