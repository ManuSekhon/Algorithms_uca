# Makefile

# Compiler to use
CC ?= clang

# Flags to pass to compiler
CFLAGS := -ggdb3 -std=c11 -Wall -Werror -Wextra

# Name for executable
EXE = test

# Space separated list of header-files
HDRS = $(wildcard *.h)

# Space separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS =

# Space separated list of source-files
SRCS = $(wildcard *.c)

# Automatically generated list of object files
OBJS = $(SRCS:.c=.o)

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
