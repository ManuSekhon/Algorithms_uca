# Makefile

# Compiler to use
CXX := clang++-6.0

# Flags to pass to compiler
CXXFLAGS := -ggdb3 -std=c++17 -Wall -Werror -Wextra -O0

# Name for executable
EXE = main

# Space separated list of header-files
HDRS = $(wildcard *.h)

# Space separated list of source-files
SRCS = $(wildcard *.cpp lib/*.cpp)

# Automatically generated list of object files
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: $(EXE)

# Default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

# Dependencies
$(OBJS): $(HDRS) Makefile

.PHONY: clean
clean:
	rm -f core $(EXE) *.o lib/*.o
