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
#include <cassert>
#include <cstring>

using namespace std;


typedef enum TokenType {
    UNEXPECTED = -2,
    END = -1,
    INTCONST = 1,
    REALCONST = 2,
    STRING,
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    PUNCTUATION,
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


// Methods to be used in the driver program
string toUpper(string str);

string intToString(int num);

string enumToString(enum TokenType type);

void printQueue();

void enqueueToken(alpha_token_t* token);

int alpha_yylex(void* token);


#endif // AL_HPP