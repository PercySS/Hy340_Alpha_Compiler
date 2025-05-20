#include "./include/symTable.hpp"
#include "include/backpatch.hpp"
#include "include/expr.hpp"
#include "include/symTable.hpp"
#include "include/quad.hpp"
#include "include/temp.hpp"
#include "include/types.hpp"
#include <cstdio>
#include <cstdlib> 

extern FILE* yyin;
extern FILE* yyout;
extern int yyparse();
extern int yydebug;

// Global variables for correct handling of the symbol table
SymbolTable symTable;
bool skipBlockScope = false;
int loopCounter = 0;
extern std::vector<quad*> quads;
std::stack<int> loopCounterStack;

void cleanup();


int main(int argc, char** argv) {
    // Initialize the quads
    init_quads();
    // handle the input output according to arguments
    yydebug = 0;
    FILE* input = stdin;
    FILE* output = stdout;

    if (argc < 2) {
        printf("Usage: %s <input_file> [output_file]\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    if (!input) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    yyin = input;

    // if an output file is provided, open it for writing
    FILE* outputFile;
    if (argc == 3) {
        outputFile = fopen(argv[2], "w");
        if (!outputFile) {
            printf("Error: Could not open output file\n");
            fclose(input);
            return 1;
        }
        yyout = outputFile;
    }

    yyout = output;

    
    int result = yyparse();

    if (result == 0) {
        printf("Parsing completed successfully!\n");
    } else {
        printf("Parsing failed.\n");
    }
    
    print_quads(output);
    /* // Print the symbol table
    symTable.printTable(output); */

    // Print the quads

    // Close the input and output files
    fclose(input);
    if (argc >= 3) {
        fclose(output);
    }

    cleanup();

    return 0;
}

void cleanup() {
    // Cleanup code here
    // Free any dynamically allocated memory, close files, etc.
    for (auto& quad : quads) {
        delete quad;
    }
    quads.clear();
}