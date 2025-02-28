#include "al.hpp"

int tokenNum = 1;
queue<alpha_token_t*> tokenQueue;

// external variables
extern FILE* yyin;
extern FILE* yyout;
extern int yylex();


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
        case COMMENT:
            return "COMMENT";
        case PUNCTUATION:
            return "PUNCTUATION";
        case END:
            return "END";
        case NL:
            return "NL";
        case WS:
            return "WS";
        default:
            return "UNEXPECTED";
    }
}

void printQueue() {
    // fprintf -> yyout
    fprintf(yyout, "+--------+--------+-------------------+-----------------+---------------------+----------------+\n");
    fprintf(yyout, "|%*s%-56s|\n", 38, " ","LEXICAL ANALYSIS REPORT");
    fprintf(yyout, "+--------+--------+-------------------+-----------------+---------------------+----------------+\n");
    fprintf(yyout, "| %-6s | %-6s | %-17s | %-15s | %-19s | %-14s |\n", "Line", "Num", "Content", "Type", "Uppercase", "Instance");
    fprintf(yyout, "+--------+--------+-------------------+-----------------+---------------------+----------------+\n");
    while (!tokenQueue.empty()) {
        alpha_token_t* token = tokenQueue.front();
        tokenQueue.pop();
        fprintf(yyout, "| %-6d | %-6d | %-17s | %-15s | %-19s | %-14s |\n", token->line, token->numToken, token->content.c_str(), enumToString(token->type).c_str(), token->tokUpp.c_str(), token->instance.c_str());
        delete token;
    }
    fprintf(yyout, "+--------+--------+-------------------+-----------------+---------------------+----------------+\n");
    fprintf(yyout, "|%*s%-51s|\n", 43, " ","END OF REPORT");
    fprintf(yyout, "+--------+--------+-------------------+-----------------+---------------------+----------------+\n");
}

void enqueueToken(alpha_token_t* token) {
    tokenQueue.push(token);
}

int alpha_yylex(void* token) {
    int res = yylex();
    return res;
}

void illegal_comment(int line) {
    fprintf(yyout, "Error: Comment not closed at line %d\n", line);
    exit(1);
}

void illegal_string(int line) {
    fprintf(yyout, "Error: String not closed at line %d\n", line);
    exit(1);
}

void illegal_token(char* yytext, int line) {
    fprintf(yyout, "Error: Illegal token %s in line %d\n", yytext,line);
    exit(1);
}

void illegal_escape(char* yytext, int line) {
    fprintf(yyout, "Error: Illegal escape sequence %s in line %d\n", yytext, line);
    exit(1); 
}

int main(int argc, char* argv[]) {
    alpha_token_t* token = new alpha_token_t();
    int res;


    // Check if the correct number of arguments are provided
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> [output_file]" << std::endl;
        return 1;
    }

    // Open the input file
    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
        return 1;
    }

    // If an output file is provided, open it for writing
    FILE* outputFile;
    if (argc == 3) {
        outputFile = fopen(argv[2], "w");
        if (!outputFile) {
            std::cerr << "Error: Could not open output file " << argv[2] << std::endl;
            fclose(inputFile);
            return 1;
        }
        yyout = outputFile;
    } else {
        // If no output file, default to printing to console
        yyout = stdout;
    }
   
   
    // Set the input file for the scanner
    yyin = inputFile;

    assert(yyin && yyout); 

    token = new alpha_token_t();
    res = alpha_yylex(token);
    
    while (res >= 0) {
        res = alpha_yylex(token);
    }

    // Print the tokens
    printQueue();

    // Close the input and output files
    fclose(inputFile);
    if (argc == 3) {
        fclose(outputFile);
    }

    return 0;
}