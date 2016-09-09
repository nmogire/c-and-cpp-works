#Author: Nancy Mogire
#Run with make -B

all: halfdriver

halfdriver: halfdriver.o halfstring.o
	gcc -o halfdriver halfdriver.o halfstring.o	

halfdriver.o: halfdriver.c halfstring.h
	gcc -c -Wall halfdriver.c

halfstring.o: halfstring.c
	gcc -c -Wall halfstring.c

clean:
	rm -rf *.o main
