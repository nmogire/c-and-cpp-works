#Makefile for costofpainting project
#Author: Nancy Mogire
#Run with make -B

all: main

main: main.o costofpainting.o
	gcc -o main main.o costofpainting.o

main.o: main.c costofpainting.h
	gcc -c -Wall main.c 

costofpainting.o: costofpainting.c
	gcc -c -Wall costofpainting.c

clean:
	rm -f *.o main
