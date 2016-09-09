/*****************************************************************
NAME: Nancy Mogire

DATE: JULY, 2016

FILE: llist.cpp

DESCRIPTION: header file for llist.c

****************************************************************/

#include "record.h"
#ifndef LLIST_H
#define LLIST_H
class llist
{
  private:
    record *   start;
    char       filename[16];
    int        readfile();
    int        writefile();
    record *   reverse(record *);
    void       cleanup();

  public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord(int, char[], char[], int);
    int printRecord(int);
    int modifyRecord(int, char[]);
    void printAll();
    int deleteRecord(int);
    void reverse();
    
};

#endif
