# Compiler and flags
CXX = g++ 

# Input and output files
LEX_FILE = scanner.l
HEADER_FILE = al.hpp
HEADER2_FILE = scanner.hpp
IMPL_FILE = al.cpp
OUTPUT_FILE = scanner.o
SCAN_FILE = scanner.cpp

# Targets
all: $(OUTPUT_FILE)

$(OUTPUT_FILE): $(SCAN_FILE) $(IMPL_FILE)
	$(CXX) -o $(OUTPUT_FILE) $(SCAN_FILE) $(IMPL_FILE) -lfl
	@echo "Generated scanner"

$(SCAN_FILE): $(LEX_FILE)
	flex --outfile=$(SCAN_FILE) $(LEX_FILE)
	@echo "Generated scanner.cpp"

clean:
	rm -f $(OUTPUT_FILE) $(SCAN_FILE) $(HEADER2_FILE)
	@echo "Cleaned"
