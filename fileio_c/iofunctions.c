/*****************************************************************

NAME: Nancy Mogire

DATE: JUNE, 2016

FILE: iofunctions.c

DESCRIPTION: This file contains the definitions of the functions readfile, writefile, readAddress, getAddress,
numreader and accountreader

****************************************************************/
#include <stdio.h>
#include <string.h>

#include "account.h"

#define MAX_USER_INPUT 200
#define MAXADDRESS 200
#define MAX_NAME 25

void readAddress(char address[], FILE *filename);

/*****************************************************************

Function name: readfile

DESCRIPTION: file reader function

reads from a specified file

Parameters: struct account *, int*, char *

Return values: none

****************************************************************/

void readfile(struct account *accounts, int *numAccounts, char *filename)
{  
  
    FILE *fileToRead;

    int i=0;
    *numAccounts=-1;
    char dummy[60];

    fileToRead= fopen(filename, "r");
    if (fileToRead!=NULL)
    {
        while(!feof(fileToRead))
        {  
            fscanf(fileToRead, "%d", &accounts[i].accountno);
            fgets(dummy, 25, fileToRead);
            fgets(accounts[i].name, MAX_NAME, fileToRead);            
            readAddress(accounts[i].address, fileToRead);
            fscanf(fileToRead, "%d", &accounts[i].yearofbirth);
            fgets(dummy, 25, fileToRead);            
            i++;
            (*numAccounts)++;

        }
        fclose(fileToRead);
    }
    else
    {
        printf("unable to read file.\n");
    }

}

/*****************************************************************

Function name: writefile

DESCRIPTION: file writer functions

writes from account struct array to file starting from the first newly created account

Parameters: struct account *, int, char *

Return values: none

****************************************************************/

void writefile(struct account *accounts, int numAccounts, char *filename)
{   
    int j;    
    FILE *fileToWrite;

    fileToWrite = fopen(filename, "a");
    if (fileToWrite == NULL)
    {
        printf("Error: could not open the file!\n");
    }
    for(j=numAccounts; j<5 && accounts[j].accountno!= 0; j++) 
    {
        fprintf(fileToWrite, "%d\n", accounts[j].accountno);
        fprintf(fileToWrite, "%s", accounts[j].name);
        fprintf(fileToWrite, "%s\n", accounts[j].address);
        fprintf(fileToWrite, "%d\n", accounts[j].yearofbirth);
    }
        fclose(fileToWrite);
}

/*****************************************************************

Function name: getAddress

DESCRIPTION: multiple line character reader function

uses getchar to read characters from the screen and allows a single intervening
newline character between any two sequences of non-newline characters. 
if the ! sign is entered it terminates

Parameters: char *, to the array that will store the read characters

Return values: none

****************************************************************/

void getAddress(char address[])
{
       int i=0;
    
       while ((i< MAXADDRESS) && (address[i]=getchar())!= '!'){           
          i++;
       }
       address[i+1]='\0';

}

/*****************************************************************

Function name: readAddress

DESCRIPTION: multiple line character reader function
reads multiple lines from a file.
it stops reading after reading in a ! sign.

Parameters: char *, to the array that will store the read characters and a FILE * to the file to be read

Return values: none

****************************************************************/

void readAddress(char address[], FILE filename[])
{
    int i=0;    
    while ((i< MAXADDRESS) && (address[i]=fgetc(filename))!= '!'){           
    i++;
    }
    address[i+1]='\0';

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
    num = 0;
    while(num == 0)
    {        
        fgets(userInput,MAX_USER_INPUT,stdin);

        if(strlen(userInput)<2 || strlen(userInput)> 5){
            printf("Please check that you entered a number between 1 and 3 digits\n");
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
            printf("Please check that you entered a valid age.\n");
            continue;
        }
          
        }
return num;
}

/*****************************************************************

Function name: accountreader

DESCRIPTION: numeric input function

gets input from stdin using fgets and then validates that it is a number and it
lies between a specified lower limit and upper limit

Parameters: int num, int lowerlimit, int upperlimit

Return values: int num, which is the number value entered by the user and validated

****************************************************************/

int accountreader(int num, int lowerlimit, int upperlimit)
{
    char userInput[MAX_USER_INPUT];
    num = 0;
    while(num == 0)
    {        
        fgets(userInput,MAX_USER_INPUT,stdin);
           
        if(sscanf(userInput, "%d", &num)!=1){
            num = 0;
            printf("please enter a number.\n");
            continue;
        }
        if(num<lowerlimit|| num>upperlimit){
            num=0;
            printf("Please ensure that you entered an 8 digit number.\n");
            continue;
        }
          
        }

return num;
}

