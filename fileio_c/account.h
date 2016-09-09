/*****************************************************************

NAME: Nancy Mogire

DATE: JUNE, 2016

FILE: account.h

DESCRIPTION: This file contains the delcarations for the functions defined in iofunctions.c

****************************************************************/

#include <stdio.h>

#define MAXNAME 25
#define MAXADDRESS 200


struct account
{
    int          accountno;
    char         name[25];
    char         address[80];
    int          yearofbirth;
};

void readfile( struct account *accounts, int * numAccounts, char filename[ ] );
void writefile( struct account *accounts, int numAccounts, char filename[ ] );
void getAddress(char address[]);
void readAddress(char address[], FILE *filename);
int numreader(int, int, int);
int accountreader(int num, int lowerlimit, int upperlimit);

