#include "symtable.hpp"
#include "parser.tab.hpp"
#include <cstdio>
#include <cstdlib> 

extern FILE* yyin;
extern FILE* yyout;
extern int yyparse();
extern int yydebug;

// Global variables for correct handling of the symbol table
SymbolTable symTable;
bool skipBlockScope = false;
int rabbitHole = 0;

int main(int argc, char** argv) {
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
            std::cerr << "Error: Could not open output file." << argv[2] << std::endl;
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

    // Print the symbol table
    symTable.printTable(output);

    // Close the input and output files
    fclose(input);
    if (argc >= 3) {
        fclose(output);
    }

    return 0;
}