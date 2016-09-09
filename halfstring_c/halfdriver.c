/*****************************************************************

NAME: Nancy Mogire

DATE: JUNE, 2016

FILE: halfdriver.c

DESCRIPTION: This file contains the definition for the driver to test halfstring.c . it has a main function, user interface to get input and and print output

****************************************************************/

#include <stdio.h>
#include "halfstring.h"

#define MAXLINE 50

#include <stdio.h>

void halfstring(char from[], char to[]);



/*****************************************************************

Function name: main

DESCRIPTION: driver function

gets input to test the function halfstring and puts the output on the string

Parameters: none, uses fgets to read from stdin

Return values: 0 for success, non-zero for failure

****************************************************************/

int main(){
    char from[MAXLINE];
    char to[MAXLINE];
    int l=0;
   	
    printf("please enter some text. This program will print back the second half:\n ");
    fgets(from,50,stdin);
	
    halfstring(from,to);

    printf("your second half is: ");
    while(to[l]!='\0'){		
        printf("%c", to[l]);
        ++l;
    }
    printf("\n");
	
return 0;
}

