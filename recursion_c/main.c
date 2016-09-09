/*****************************************************************

NAME: Nancy Mogire

DATE: JUL, 2016

FILE: main.c

DESCRIPTION: This file is a driver for the file recursion project. It contains the interface to get user input and display some output as well as a function to help validate the user input while getting it.

****************************************************************/

#include <stdio.h>
#include <string.h>

#include "costofpainting.h"

#define MAX_USER_INPUT 10

int numreader(int num, int lowerlimit, int upperlimit);


/*****************************************************************

Function name: main

DESCRIPTION: gets a number as input from user and assigns it to the length variable [asses it to the costofpainting function and afterwards displays the calculated cost of painting an area of the length entered

Parameters: argc, argv[], uses fgets to read from stdin

Return values: 0 for success, non-zero for failure

****************************************************************/


int main(int argc, char* argv[])
{
    double length =0;
    int cost;
    
    printf("Please enter the length of the road section you want painted, in miles between 1 and 1000\n");
    length = numreader(length, 1, 1000);    
    cost= costofpainting(length);

    printf("cost of painting will be $%d\n", cost);

    return 0;
}


/*****************************************************************

Function name: numreader

DESCRIPTION: numeric input function

gets input from stdin using fgets and then validates that it is a number and it
lies between a specified lower limit and upper limit

Parameters: int num, int lowerlimit, int upperlimit

Return values: int num, which is the number value entered by the user and validated

****************************************************************/

int numreader(int num, int lowerlimit, int upperlimit)
{
    char userInput[MAX_USER_INPUT];
    
    while(num == 0)
    {        
        fgets(userInput,MAX_USER_INPUT,stdin);

        if(strlen(userInput)<1 || strlen(userInput)>5){
            printf("Please check that you entered a number between 1 and 1000\n");
            num=0;
            continue;
            }    
        if(sscanf(userInput, "%d", &num)!=1){
            num = 0;
            printf("please enter a number.\n");
            continue;
        }
        if(num<lowerlimit|| num>upperlimit){
            num=0;
            printf("Please check that you entered a length between 1 and 1000.\n");
            continue;
        }
          
        }
return num;
}
