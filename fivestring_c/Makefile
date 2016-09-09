#Author: Nancy Mogire
#Run with make -B

all: fivestringdriver

fivestringdriver: fivestringdriver.o fivestring.o
	gcc -o fivestringdriver fivestringdriver.o fivestring.o	

fivestringdriver.o: fivestringdriver.c fivestring.h
	gcc -c -Wall fivestringdriver.c

fivestring.o: fivestring.c
	gcc -c -Wall fivestring.c

clean:
	rm -rf *.o fivestringdriver
