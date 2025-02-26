# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -ansi -pedantic -g
FLEX = flex

# Directories
SRC_DIR = src
OUT_DIR = out

# Files
LEX_FILE = $(SRC_DIR)/scanner.l
SCANNER_CPP = $(OUT_DIR)/scanner.cpp
SCANNER_OBJ = $(OUT_DIR)/scanner.o
AL_CPP = $(SRC_DIR)/al.cpp
AL_OBJ = $(OUT_DIR)/al.o
HEADER = $(SRC_DIR)/al.hpp
EXEC = $(OUT_DIR)/scanner

# Targets
all: $(EXEC)

# Generate scanner.cpp from scanner.l
$(SCANNER_CPP): $(LEX_FILE)
	@mkdir -p $(OUT_DIR)
	$(FLEX) --outfile=$(SCANNER_CPP) $(LEX_FILE)

# Compile scanner.cpp
$(SCANNER_OBJ): $(SCANNER_CPP) $(HEADER)
	$(CXX) $(CXXFLAGS) -c $(SCANNER_CPP) -o $(SCANNER_OBJ)

# Compile al.cpp
$(AL_OBJ): $(AL_CPP) $(HEADER)
	$(CXX) $(CXXFLAGS) -c $(AL_CPP) -o $(AL_OBJ)

# Link everything into the final executable
$(EXEC): $(SCANNER_OBJ) $(AL_OBJ) 
	$(CXX) $(CXXFLAGS) $(SCANNER_OBJ) $(AL_OBJ) $(HEADER) -o $(EXEC)

# Clean compiled files
clean:
	rm -rf $(OUT_DIR)/*.o $(OUT_DIR)/scanner.cpp $(EXEC)
	rmdir $(OUT_DIR) 2> /dev/null || true
