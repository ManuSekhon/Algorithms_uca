# Makefile

# Compiler to use
CC ?= clang

# Flags to pass to compiler
CFLAGS := -ggdb3 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter

# Name for executable
EXE = a.out

# Space separated list of header-files
HDRS = base64.h

# Space separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS =

# Space separated list of source-files
SRCS = test.c base64.c

# Automatically generated list of object files
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: $(EXE)

# Default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# Dependencies
$(OBJS): $(HDRS) Makefile

.PHONY: clean
clean:
	rm -f core $(EXE) *.o
