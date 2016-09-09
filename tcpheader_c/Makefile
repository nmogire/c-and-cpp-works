#Makefile for tcp header project
#Author: Nancy Mogire
#Run with make -B

all: main

main: main.o binfileio.o headers.o
	gcc -o main main.o binfileio.o headers.o

main.o:main.c binfileio.h headers.h
	gcc -c -Wall main.c

binfileio.o:binfileio.c headers.h
	gcc -c -Wall binfileio.c

headers.o:headers.c binfileio.h
	gcc -c -Wall headers.c

clean:
	rm -f *.o main
