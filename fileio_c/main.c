/*****************************************************************

NAME: Nancy Mogire

DATE: JUNE, 2016

FILE: main.c

DESCRIPTION: This file is a driver for the file read and write project. It contains the interface to get user input and display some output.

****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "account.h"

void readfile( struct account *accounts, int * numAccounts, char filename[ ] );
void writefile( struct account *accounts, int numAccounts, char filename[ ] );
void getAddress(char address[]);
int numreader(int, int, int);
int accountreader(int num, int lowerlimit, int upperlimit);

/*****************************************************************

Function name: main

DESCRIPTION: project driver and interface function
prints out the files read from the input file,
displays a menu using a do while loop and accepts input to be added to the accounts struct

Parameters: argc, argv[], also uses getchar() and fgets to read from stdin

Return values: 0 for success, non-zero for failure

****************************************************************/

int main(int argc, char* argv[])
{

    struct account accounts[5];
    int numAccounts;
    int *numsAccounts = &numAccounts;
    int numOfAccounts;
    char dummy[62];
    char menuchoice;
    int i=0;
    int j=0;
    int consoleOpen;	
    consoleOpen = 1;
/*for(i=0; i<5 && accounts[i].accountno!= 0; i++)
    {
accounts[i].accountno = 0;
memset(accounts[i].name,'\0', 25); 
memset(accounts[i].address,'\0', 80); 
accounts[i].yearofbirth = 0;
}
*/

    readfile(accounts, numsAccounts, "inputfile2.txt");

    system("clear");


    for(i=0; i<5 && accounts[i].accountno!= 0; i++)
    {
     printf("%d\n", accounts[i].accountno);
     printf("%s", accounts[i].name);
     printf("%s\n", accounts[i].address);
     printf("%d\n", accounts[i].yearofbirth);
    }

    printf("Do you wish to add records? You can add upto %d more records\n", (5-numAccounts));
    puts("[1]Yes\n"
         "[2]No\n"
         "...............\n"
         "[q]Quit Program\n");  
    
    do
    {          
        menuchoice = getchar();        
        switch(menuchoice)
        {
            case '1':                          
            printf("Please enter the number of records you wish to add? (not more than 3).\n");
            fgets(dummy,63,stdin);
            numOfAccounts= numreader(numOfAccounts, 1, 3);//what if he enters 0?
            i = numAccounts;
            while (i<5 && j<numOfAccounts)//less than array size and what the user wants to enter 
            {                 
               
                printf("Please enter an 8 digit account number\n");               
                accounts[i].accountno = accountreader(accounts[i].accountno, 10000000, 99999999);
              

                printf("Please enter a name, no more than 25 characters long:\n ");
                fgets(accounts[i].name,25,stdin);
            
                printf("Please enter an address for the user:\n");
                getAddress(accounts[i].address);
                fgets(dummy,63,stdin);
               
                printf("Please enter a year of birth for: %s", accounts[i].name);
                accounts[i].yearofbirth=numreader(accounts[i].yearofbirth, 1900, 2016);
                 
                i++;
                j++;
             }           
             break;

             case '2':
                 printf("Nothing to be done\n");
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

    writefile(accounts,numAccounts, "inputfile3.txt");
    return 0;
}
