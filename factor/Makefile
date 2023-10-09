# Makefile for factor

# Compiler to use
CC = gcc

# Flags to pass compiler
CFLAGS = -Wall -std=c11

# Name for executable
EXE = factor

# Space-separated list of source files
SOURCES = main.c factor.c

# Automatically generated list of object files
OBJS = $(SOURCES:.c=.o)

# Default target
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

# Dependencies
main.o: main.c factor.h
factor.o: factor.c factor.h

# Housekeeping
clean:
	rm -f core $(EXE) $(OBJS)
