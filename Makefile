# makefile for alpha compiler
# Compiler  
CXX = g++
LEX = flex

# Compiler flags  
CXXFLAGS = 

# Source files  
SRCS = al.cpp lex.yy.cpp  
OBJS = $(SRCS:.cpp=.o)  

# Output executable  
TARGET = alpha_compiler  

# Default rule  
all: $(TARGET)

# Generate scanner from Flex file  
lex.yy.cpp: scanner.l  
	$(LEX) scanner.l  

# Linking  
$(TARGET): $(OBJS)  
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compiling source files into object files  
%.o: %.cpp  
	$(CXX) $(CXXFLAGS) -c $< -o $@  

# Clean up  
clean:  
	rm -f $(OBJS) $(TARGET) 
	rm -f lex.yy.cpp
