# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -ansi -pedantic -g -I$(OUT_DIR)
FLEX = flex

# Directories
SRC_DIR = src
OUT_DIR = out

# Files
LEX_FILE = $(SRC_DIR)/scanner.l
SCANNER_CPP = $(OUT_DIR)/scanner.cpp
SCANNER_HPP = $(OUT_DIR)/scanner.hpp
SCANNER_OBJ = $(OUT_DIR)/scanner.o
AL_CPP = $(SRC_DIR)/al.cpp
AL_OBJ = $(OUT_DIR)/al.o
HEADER = $(SRC_DIR)/al.hpp
EXEC = scanner.exe

# Targets
all: $(EXEC)

# Generate scanner.cpp and scanner.hpp from scanner.l
$(SCANNER_CPP) $(SCANNER_HPP): $(LEX_FILE)
	@mkdir -p $(OUT_DIR)
	$(FLEX) --outfile=$(SCANNER_CPP) $(LEX_FILE)
	@mv scanner.hpp $(OUT_DIR)

# Compile scanner.cpp
$(SCANNER_OBJ): $(SCANNER_CPP) $(SCANNER_HPP) $(HEADER)
	$(CXX) $(CXXFLAGS) -c $(SCANNER_CPP) -o $(SCANNER_OBJ)

# Compile al.cpp
$(AL_OBJ): $(AL_CPP) $(HEADER) $(SCANNER_HPP)
	$(CXX) $(CXXFLAGS) -c $(AL_CPP) -o $(AL_OBJ)

# Link everything into the final executable
$(EXEC): $(SCANNER_OBJ) $(AL_OBJ)
	$(CXX) $(CXXFLAGS) $(SCANNER_OBJ) $(AL_OBJ) -o $(EXEC)

# Clean compiled files
clean:
	rm -rf $(OUT_DIR)/*.o $(OUT_DIR)/scanner.cpp $(OUT_DIR)/scanner.hpp $(EXEC)
	rmdir $(OUT_DIR) 2> /dev/null || true