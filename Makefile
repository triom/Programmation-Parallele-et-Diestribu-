$(CC) = gcc

all : prog

prog : main.o  
	$(CC) -o prog main.o -lm

main.o : SonwaTriomphante-MagnekouAivi_codeSourcePUISS.c
	$(CC) -fopenmp SonwaTriomphante-MagnekouAivi_codeSourcePUISS.c -o main.o 

Clean : 
	rm *.o prog
