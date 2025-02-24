#include "al.hpp"

string toUpper(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

string enumToString(enum TokenType type) {
    switch (type) {
        case INTCONST:
            return "INTCONST";
        case REALCONST:
            return "REALCONST";
        case STRING:
            return "STRING";
        case IDENTIFIER:
            return "IDENTIFIER";
        case KEYWORD:
            return "KEYWORD";
        case OPERATOR:
            return "OPERATOR";
        case LEFT_BRACE:
            return "LEFT_BRACE";
        case RIGHT_BRACE:
            return "RIGHT_BRACE";
        case LEFT_BRACKET:
            return "LEFT_BRACKET";
        case RIGHT_BRACKET:
            return "RIGHT_BRACKET";
        case LEFT_PARENTHESIS:
            return "LEFT_PARENTHESIS";
        case RIGHT_PARENTHESIS:
            return "RIGHT_PARENTHESIS";
        case SEMICOLON:
            return "SEMICOLON";
        case COMMA:
            return "COMMA";
        case COLON:
            return "COLON";
        case DOUBLE_COLON:
            return "DOUBLE_COLON";
        case ARROW:
            return "ARROW";
        case SCOPE:
            return "SCOPE";
        case DOT:
            return "DOT";
        case DOTDOT:
            return "DOUBLE_DOT";
        case COMMENT:
            return "COMMENT";
        default:
            return "UNEXPECTED";
    }
}

void printQueue() {
    while (!tokenQueue.empty()) {
        alpha_token_t* token = tokenQueue.front();
        tokenQueue.pop();
        std::cout << token->content << std::endl;
    }
}

void enqueueToken(alpha_token_t* token) {
    tokenQueue.push(token);
}

alpha_token_t* alpha_yylex() {
    alpha_token_t* token = new alpha_token_t;
    token->line = yylineno;
    token->numToken = tokenNum++;
    token->content = yytext;
    token->tokUpp = toUpper(yytext);
    token->instance = " ";
    return token;
}