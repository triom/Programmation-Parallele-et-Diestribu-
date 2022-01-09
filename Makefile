$(CC) = gcc

all : prog

prog : main.o  
	$(CC) -fopenmp -o prog main.o -lm

main.o : SonwaTriomphante-MagnekouAivi_codeSourcePUISS.c
	$(CC) -o main.o  -c SonwaTriomphante-MagnekouAivi_codeSourcePUISS.c 

Clean : 
	rm *.o prog
