$(CC) = gcc

all : prog

prog : main.o functions.o 
	$(CC) -o prog main.o -lm

main.o : main.c
	$(CC) -o main.o -c main.c 

Clean : 
	rm *.o prog
