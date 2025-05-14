# === File: PhaseC/Makefile ===

# Tools
CXX      = g++
FLEX     = flex
BISON    = bison

# Directories
SRC_DIR  = src
OUT_DIR  = out

# Source Files
SCANNER     = $(SRC_DIR)/scanner.l
PARSER      = $(SRC_DIR)/parser.y
MAIN        = $(SRC_DIR)/main.cpp
SYMTABLE    = $(SRC_DIR)/symtable.cpp
IOPCODE     = $(SRC_DIR)/iopcode.cpp

# Generated Files
PARSER_CPP  = $(OUT_DIR)/parser.tab.cpp
PARSER_HPP  = $(OUT_DIR)/parser.tab.hpp
SCANNER_CPP = $(OUT_DIR)/scanner.cpp
SCANNER_HPP = $(OUT_DIR)/scanner.hpp

# Executable
TARGET   = compiler

# Build flags
CXXFLAGS = -Wall -ansi -pedantic -g -std=c++17 -I$(OUT_DIR) -I$(SRC_DIR)
LDFLAGS  = -lfl

# Default target
all: $(TARGET)

# Final linking
$(TARGET): $(PARSER_CPP) $(SCANNER_CPP) $(SYMTABLE) $(IOPCODE) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Bison
$(PARSER_CPP) $(PARSER_HPP): $(PARSER)
	@mkdir -p $(OUT_DIR)
	$(BISON) -d -Wcounterexamples --defines=$(PARSER_HPP) -o $(PARSER_CPP) $(PARSER)

# Flex
$(SCANNER_CPP) $(SCANNER_HPP): $(SCANNER)
	@mkdir -p $(OUT_DIR)
	$(FLEX) -o $(SCANNER_CPP) --header-file=$(SCANNER_HPP) $(SCANNER)

# Clean
clean:
	rm -rf $(OUT_DIR) $(TARGET)

.PHONY: all clean
