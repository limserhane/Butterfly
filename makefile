# Directories
# PROJDIR := $(realpath $(CURDIR))/
SRCDIR     := src/
INCLUDEDIR := include/
EXAMPLEDIR := example/
BUILDDIR   := build/
BINDIR     := bin/

# 
SOURCES := $(wildcard $(SRCDIR)*.cpp)
OBJECTS := $(subst $(SRCDIR), $(BUILDDIR), $(SOURCES:.cpp=.o))

# Library
NAME	:= butterfly
LIBNAME := lib$(strip $(NAME)).a
LIBRARY := $(BINDIR)$(LIBNAME)

# Example
EXAMPLE := $(BINDIR)example.out

# Compiler
CC = g++ -std=c++17
CCFLAGS = -Wall -Wextra -pedantic
AR = ar rcs

# Commands
MKDIR := mkdir -p
RM := rm -rf

.PHONY : all directories clean sandbox run

all : rebuild

# Build objects
$(BUILDDIR)%.o : $(SRCDIR)%.cpp
	@echo "Building $(notdir $@)" 
	@$(CC) $(CCFLAGS) -I $(INCLUDEDIR) -c $< -o $@

# Build static library
$(LIBRARY) : $(OBJECTS)
	@echo "Building $(notdir $@)"
	@$(AR) $@ $^

# Build example
$(EXAMPLE) : $(EXAMPLEDIR)example.cpp $(LIBRARY)
	@echo "Building $(notdir $@)"
	@$(CC) $(CCFLAGS) -I $(INCLUDEDIR) -L$(BINDIR) $^ -o $@

# Create directories
$(BUILDDIR) $(BINDIR) :
	@echo "Making $@"
	@$(MKDIR) $@

directories : $(BUILDDIR) $(BINDIR)

build : directories $(LIBRARY) $(EXAMPLE)

rebuild : clean build

clean : 
	@echo "Cleaning up project builds"
	@$(RM) $(BUILDDIR)* $(BINDIR)*

sandbox : $(LIBRARY)
	@echo "Building sandbox.out"
	@$(CC) $(CCFLAGS) -I $(INCLUDEDIR) sandbox/*.cpp -o sandbox/sandbox.out -L$(BINDIR) $^
