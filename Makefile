CC=g++
CFLAGS=-c

all: ./main

main: DynamicTimeWarping.o main.cpp
	@$(CC) -o main DynamicTimeWarping.o main.cpp

DynamicTimeWarping.o: DynamicTimeWarping.hpp DynamicTimeWarping.cpp
	@$(CC) DynamicTimeWarping.hpp DynamicTimeWarping.cpp $(CFLAGS)
	
run:
	@./main
