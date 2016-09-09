#Author: Nancy Mogire
#Run with make -B

all: main

main: main.o iofunctions.o
	gcc -o main main.o iofunctions.o

main.o: main.c account.h
	gcc -c -Wall main.c

iofunctions.o: iofunctions.c
	gcc -c -Wall iofunctions.c

clean:
	rm -f *.o main
