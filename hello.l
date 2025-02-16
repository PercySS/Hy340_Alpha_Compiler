%option noyywrap

%{
#include <iostream>
%}

%%
hello   { std::cout << "Hello, World!" << std::endl; }
world   { std::cout << "World, Hello!" << std::endl; }
.       { std::cout << "Unknown" << std::endl; }
%%

int main(void) {
    yylex();
    return 0;
}