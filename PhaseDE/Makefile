# Tools
CXX      = g++
FLEX     = flex
BISON    = bison

# Directories
SRC_DIR  = src
INC_DIR  = include
OUT_DIR  = out

# Source files
SCANNER_L      = $(SRC_DIR)/scanner.l
PARSER_Y       = $(SRC_DIR)/parser.y
MAIN_CPP       = $(SRC_DIR)/main.cpp
SYMTABLE_CPP   = $(SRC_DIR)/src/symtable.cpp
TEMP_CPP       = $(SRC_DIR)/src/temp.cpp
EXPR_CPP       = $(SRC_DIR)/src/expr.cpp
BACKPATCH_CPP  = $(SRC_DIR)/src/backpatch.cpp
QUAD_CPP       = $(SRC_DIR)/src/quad.cpp
TARGET_CPP      = $(SRC_DIR)/src/target.cpp

# Generated files
PARSER_CPP     = $(OUT_DIR)/parser.tab.cpp
PARSER_HPP     = $(OUT_DIR)/parser.tab.hpp
SCANNER_CPP    = $(OUT_DIR)/scanner.cpp
SCANNER_HPP    = $(OUT_DIR)/scanner.hpp

# Executable
TARGET         = compiler

# Build flags
CXXFLAGS  = -Wall -ansi -pedantic -g -std=c++17 \
            -I$(OUT_DIR) -I$(INC_DIR)
LDFLAGS   = -lfl

# Default target
all: $(TARGET)

# Link everything
$(TARGET): 	\
	$(PARSER_CPP) \
	$(SCANNER_CPP) \
	$(MAIN_CPP) \
	$(SYMTABLE_CPP) \
	$(TEMP_CPP) \
	$(EXPR_CPP) \
	$(BACKPATCH_CPP) \
	$(QUAD_CPP)	\
	$(TARGET_CPP)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Bison parser generation
$(PARSER_CPP) $(PARSER_HPP): $(PARSER_Y)
	@mkdir -p $(OUT_DIR)
	$(BISON) -d -Wcounterexamples \
	  --defines=$(PARSER_HPP) \
	  -o $(PARSER_CPP) $(PARSER_Y)

# Flex scanner generation
$(SCANNER_CPP) $(SCANNER_HPP): $(SCANNER_L)
	@mkdir -p $(OUT_DIR)
	$(FLEX) -o $(SCANNER_CPP) --header-file=$(SCANNER_HPP) $(SCANNER_L)

# Clean up
clean:
	rm -rf $(OUT_DIR) $(TARGET) quads.txt output.bin

.PHONY: all clean
