/*****************************************************************

NAME: Nancy Mogire

DATE: JUL, 2016

FILE: main.c

DESCRIPTION: This file is a driver for the tcp project. It contains the interface to get user input and display some output.

****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "binfileio.h"
#include "headers.h"

struct t_header header;
unsigned char replyheader[20];
unsigned char *read_in;

/*****************************************************************

Function name: main

DESCRIPTION: project driver and interface function. displays a menu using a do while loop to accept a file selection. Prints out the header read from the input file,

Parameters: argc, argv[], also uses getchar() and fgets to read from stdin

Return values: 0 for success, non-zero for failure

****************************************************************/

int main(int argc, char* argv[])
{
    
    char b_filename[15];
    char menuchoice;
    int consoleOpen;	
    consoleOpen = 1;

    
    system("clear");

    printf("Select a header file to process and send\n");
    puts("[1]test1.bin\n"
         "[2]test2.bin\n"
         "[3]test3.bin\n"
         "...............\n"
         "[q]Quit Program\n");


    do
    {          
        menuchoice = getchar();        
        switch(menuchoice)
        {
         case '1':
             strncpy(b_filename, "test1.bin", 10);
             consoleOpen=0;
             break;

         case '2':
             strncpy(b_filename, "test2.bin", 10);
             consoleOpen=0;
             break;

         case '3':
             strncpy(b_filename, "test3.bin", 10);
             consoleOpen=0;
             break;

         case 'q':
             consoleOpen=0;
             break;

         case '\n':            
             break;

         default:
             printf("Please choose an option from the list above.\n");
             break; 
        }
        

    }while(consoleOpen!=0);

    printf("Request Header\n");
    printf("---------------\n");
    readfile(b_filename);
    buildResponse();
    writefile("response.bin");
    printf("\n\n");
    printf("Response Header\n");
    printf("---------------\n");
    readfile("response.bin");
    return 0;
}
