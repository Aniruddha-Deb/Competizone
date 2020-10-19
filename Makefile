CC = gcc
CPPC = g++

CFLAGS = -std=c99 -Wall
CPPFLAGS = -std=c++14 -Wall

LDCFLAGS = -lm
LDCPPFLAGS = -lm

NAME ?= "new"

new:
	./new_file.sh $(NAME)

%.c:
	$(CC) $(CFLAGS) src/$@ -o $(patsubst %.c,exec/%,$@) $(LDCFLAGS)

%.cpp: 
	$(CPPC) $(CPPFLAGS) src/$@ -o $(patsubst %.cpp,exec/%,$@) $(LDCPPFLAGS)
