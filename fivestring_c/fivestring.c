/*****************************************************************

NAME: Nancy Mogire

DATE: JUNE, 2016

FILE: fivestring.c

DESCRIPTION: practice on the string.h library functions

This file contains the definition for the function fivestring that takes a string and manipulates it to make a substring that
can be used as a username

****************************************************************/

#include <stdio.h>
#include <string.h>


#define MAXLINE 25


/*****************************************************************

Function name: fivestring

DESCRIPTION: string manipulation function

This function takes a char array and manipulates the string to make a random string

Parameters: char from[], char to[], int size : the first array contains the string that will be manipulated, the second one is the destination of the final string while the int parameter specifies the number of text characters that should be in the final string.

Return values: none

****************************************************************/

void username(char from[], char to[], int size){
		
    int inputLen, k;
    inputLen = strlen(from);	
    char addstring[]="drolfewolfentetwland";
    char temp[MAXLINE];
    int half = strlen(temp)/2;
    
    if(inputLen<15){		
        strcpy(temp, addstring);
        strcat(temp, from);           
    }
    else{
        strcpy(temp, from);	
		
    }
    for(k=half; k<half+size && temp[k]!=' '; k++){
        to[k-half]=temp[k];
    }
	
    to[strlen(to)]='\0'; 
}
