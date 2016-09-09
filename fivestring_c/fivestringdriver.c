/*****************************************************************

NAME: Nancy Mogire

DATE: JUNE, 2016

FILE: fivestringdriver.c

DESCRIPTION: This file contains the definition for the driver to test fivestring.c . it has a main function, user interface to get input and and print output

****************************************************************/
#include <stdio.h>
#include <string.h>
#include "fivestring.h"

#define MAXLINE 25

void username(char from[], char to[], int size);
size_t strlen(const char *str);

/*****************************************************************

Function name: main

DESCRIPTION: driver function

gets input to test the function fivestring and puts the output on the string

Parameters: none, uses fgets to read text from stdin and scanf to read a number

Return values: 0 for success, non-zero for failure

****************************************************************/


int main(){
    char from[MAXLINE];
	char to[MAXLINE];
    int nameMax,l;   
   	
    printf("This program will help you make up usernames. Enter a word or sentence:\n ");
    fgets(from,25,stdin);
    printf("pick a number between 5 and 10: ");
    scanf("%d", &nameMax);    
    	
    
    username(from,to, nameMax);
	
    printf("Try this Username: ");	
    while(to[l]!='\0'){		
        printf("%c", to[l]);
        ++l;
        }	
        printf("\n");	
	
return 0;
}

