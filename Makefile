CC = gcc
CPPC = g++

CFLAGS = -std=c99 -Wall
CPPFLAGS = -std=c++14 -Wall

LDCFLAGS = -lm
LDCPPFLAGS = -lm

NAME ?= "new"

OJ ?= 0

help:
	$(info Makefile for Competizone)
	$(info Use new_file.sh to create a new file, mentioning the file name. Paste)
	$(info the output required and press ^D to enter edit mode.)
	$(info )
	$(info Use archive.sh <file1> <file2> ... <Competition Name> to archive all)
	$(info source files with the given file names into folder <Comeptition Name>)
	$(info )
	$(info do make clean to clean all executables in the exec/ folder)
	$(info )
	$(info do make <program name> to make the given program (program in src folder))

clean:
	rm exec/*
	rm src/*

clprc:
	mv src/*.cpp old/practice/
	rm -rf src/*

%.c:
ifeq ($(OJ), 0)
	$(CC) $(CFLAGS) -DDEBUG src/$@ -o $(patsubst %.c,exec/%,$@) $(LDCFLAGS)
else
	$(CC) $(CFLAGS) src/$@ -o $(patsubst %.c,exec/%,$@) $(LDCFLAGS)
endif
	$(patsubst %.c,exec/%,$@) < in.txt

%.cpp: 
ifeq ($(OJ), 0)
	$(CPPC) $(CPPFLAGS) -DDEBUG src/$@ -o $(patsubst %.cpp,exec/%,$@) $(LDCPPFLAGS)
else
	$(CPPC) $(CPPFLAGS) src/$@ -o $(patsubst %.cpp,exec/%,$@) $(LDCPPFLAGS)
endif
	$(patsubst %.cpp,exec/%,$@) < in.txt
