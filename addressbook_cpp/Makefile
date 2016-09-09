#Author: Nancy Mogire
#Run with make -B

all: main

main: main.o llist.o interfacefunctions.o
	g++ -o main main.o llist.o interfacefunctions.o

main.o: main.cpp record.h llist.h
	g++ -c -Wall main.cpp 

llist.o: llist.cpp llist.h record.h
	g++ -c -Wall llist.cpp

interfacefunctions.o: interfacefunctions.cpp record.h
	g++ -c -Wall interfacefunctions.cpp

clean:
	rm -f *.o main
