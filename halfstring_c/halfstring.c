/*****************************************************************

NAME: Nancy Mogire

DATE: JUNE, 2016

FILE: halfstring.c

DESCRIPTION: This file contains the definition for the function halfstring that takes a string and copies the second half into a new array

****************************************************************/

#include <stdio.h>

#define MAXLINE 50


/*****************************************************************

Function name: halfstring

DESCRIPTION: string copy function

This function takes a char array and copies the seond half of it to 
another array.

Parameters: char from[], char to[] : the first array contains the string whose second half will be copied, the second one is the destination of the copy.

Return values: none

****************************************************************/

void halfstring(char from[], char to[]){
    int k, h, half;
    int strlength=0;	
    /*check length of string*/
    for(h=0; (h<MAXLINE) && (from[h] != '\n') && (from[h] != '\0'); h++){
        ++strlength;
    }
    half= strlength/2;	
    /*copy from half to end of string and add an null character*/
    for(k=half; k<strlength; k++){
        to[k-half]=from[k];	
        to[half+1]='\0'; 
    }	
}
