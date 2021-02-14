# Directories
# PROJDIR := $(realpath $(CURDIR)/)/
SRCDIR     := src
INCLUDEDIR := include
EXAMPLEDIR := example
BUILDDIR   := build
BINDIR     := bin
BINEXAMPLEDIR := $(BINDIR)/$(EXAMPLEDIR)/

# 
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(subst $(SRCDIR)/, $(BUILDDIR)/, $(SOURCES:.cpp=.o))

# Library
LIBNAME	:= butterfly
LIBFILENAME := lib$(strip $(LIBNAME)).a
LIBPATH := $(BINDIR)/$(LIBFILENAME)

# Example
EXAMPLESOURCES := $(wildcard $(EXAMPLEDIR)/*.cpp)
EXAMPLES := $(addprefix $(BINEXAMPLEDIR), $(notdir $(EXAMPLESOURCES:.cpp=.out)))

# Compiler
CC = g++ -std=c++17
CCFLAGS = -Wall -Wextra -pedantic
AR = ar rcs

# Commands
MKDIR := mkdir -p
RM := rm -rf

.PHONY : all build rebuild directories clean examples

build : directories $(LIBPATH) examples

all : rebuild

rebuild : clean build

directories :
	@ $(MKDIR) $(BUILDDIR) $(BINDIR) $(BINDIR)/$(EXAMPLEDIR)

clean : 
	@ echo "Cleaning up project builds"
	@ $(RM) $(BUILDDIR)/* $(BINDIR)/*
	@ $(RM) log-*.txt

examples : $(LIBPATH) $(EXAMPLES)

#########################################################
######################	RULES	#########################
#########################################################

# build/objects
$(BUILDDIR)/%.o : $(SRCDIR)/%.cpp
	@ echo "Building $(@F)" 
	@ $(CC) $(CCFLAGS) -I $(INCLUDEDIR)/ -c $< -o $@ 

# bin/lib
$(LIBPATH) : $(OBJECTS)
	@ echo "Building $(@F)"
	@ $(AR) $@ $^

# bin/example-
$(BINDIR)/$(EXAMPLEDIR)/%.out : $(EXAMPLEDIR)/%.cpp $(LIBPATH) 
	@ echo "Building $(@F)"
	@ $(CC) $(CCFLAGS) -I $(INCLUDEDIR) -L$(BINDIR) $< -o $@ -l$(LIBNAME) -lpthread 
