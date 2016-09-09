/*****************************************************************
NAME: Nancy Mogire

DATE: JULY, 2016

FILE: llist.cpp

DESCRIPTION: header for interface functions

****************************************************************/

#ifndef RECORD_H
#define RECORD_H
#include <iostream>
using namespace std;
struct record
{
    int              accountno;
    char             name[25];
    char             address[200];
    int              yearofbirth;
    struct record*   next;

};

void readAddress(char address[], FILE *filename);
void getAddress(char address[]);
int getyearofbirth(int num, int lowerlimit, int upperlimit);
int getrecordnum(int num);
void getname(char fullname[]);
#endif
