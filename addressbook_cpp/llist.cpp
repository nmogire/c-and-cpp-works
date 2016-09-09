
/*****************************************************************
NAME: Nancy Mogire

DATE: JULY, 2016

FILE: llist.cpp

DESCRIPTION: This file contains function definitions for all the class member functions

****************************************************************/

#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "llist.h"
using namespace std;

#define MAX_NAME 25
extern bool debugmode;



llist::llist()
{
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"llist() constructor was called successfully:"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
   
        start = NULL;
        
        //to prevent a writefile() fail because no file is passed in to constructor:
        strcpy(filename, "./dblist.txt");
    
}

llist::llist(char filename[])
{
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"llist() constructor was called successfully:"<<endl;
        cout<<"list filename received was:"<< filename <<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        
        start=NULL; 
        
        //using filename passed in to initialize llist filename variable
        strcpy(llist::filename, filename); 

        readfile();        
}

int llist::readfile()
{
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"readfile() was called successfully:"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    FILE *fileToRead;    
    char dummy[60];
    struct record fileRecord[80];
    int i=0;
    
    fileToRead= fopen(filename, "r");
    if (fileToRead!=NULL)
    {
        while(!feof(fileToRead))
        {   
            int ret = fscanf(fileToRead, "%d", &fileRecord[i].accountno);
            
            if (ret <= 0)
                break;
            
            fgets(dummy, 25, fileToRead);
            fgets(fileRecord[i].name, MAX_NAME, fileToRead);
            
            strtok(fileRecord[i].name, "\n");
            
            readAddress(fileRecord[i].address, fileToRead);
            
            strtok(fileRecord[i].address, "!");
            
            fscanf(fileToRead, "%d", &fileRecord[i].yearofbirth);
            fgets(dummy, 25, fileToRead);
            llist::addRecord (fileRecord[i].accountno, fileRecord[i].name, fileRecord[i].address, fileRecord[i].yearofbirth);                     
            i++;
            
        }
        fclose(fileToRead);
    }
    else
    {
        cout<<"unable to read file."<<endl;
    }

return 0;
}

int llist::writefile()
{
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"writefile() was called successfully:"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    FILE *fileToWrite;
    struct record* current;
    current = start;
   
    fileToWrite = fopen(filename, "w");
    if (fileToWrite == NULL)
    {
        cout<<"Error: could not open the file!"<<endl;
    }
    
   
    while(current!=NULL)
    {
        fprintf(fileToWrite, "%d\n", current->accountno);
        fprintf(fileToWrite, "%s\n", current->name);
        fprintf(fileToWrite, "%s\n", current->address);
        fprintf(fileToWrite, "%d\n", current->yearofbirth);
        current=current->next;
       }
    fclose(fileToWrite);

return 0;
}

record *  llist::reverse(record * start)
{
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"reverse() was called successfully:"<<endl;
        cout<<"record ptr received was:"<< start <<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

record * reverse_start=start;


return reverse_start;
}


int llist::addRecord(int accountno, char accountname[], char accountaddress[], int yearofbirth)
{
    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"addRecord() was successfully called:"<<endl;
        cout<<"acc no received was:"<< accountno<<endl;
        cout<<"year of birth received:"<< yearofbirth <<endl;
        cout<<"acc name received:"<< accountname <<endl;
        cout<<"acc address received:"<< accountaddress <<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
    
    record * newRecord = new record;
    record *current;
    
    newRecord -> accountno = accountno;
    newRecord -> yearofbirth = yearofbirth;
    strncpy(newRecord -> name, accountname, 25);
    strncpy(newRecord -> address, accountaddress, 200);
    newRecord -> next = NULL;
    
    if (start == NULL) {
        start = newRecord;       
        }
    else
    {   current = start;
        while(current->next!=NULL)
        {
            current = current ->next;
        }
        
        current->next = newRecord;
    } 
        

    return 0;
}


int llist::printRecord(int accountno)
{
    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"printRecord() was called successfully:"<<endl;
        cout<<"acc no received was:"<< accountno <<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }

    record *current;
    int count=0;
    current= start;

    while(current!= NULL)
    {
        if((current->accountno)==accountno)
        {
            cout<<current->accountno<<endl;
            cout<<current->name<<endl;
            cout<<current->address<<endl;
            cout<<current->yearofbirth<<endl;
                    
            current = current->next;
            count++;            
        }
        else
        {
            current=current->next;
        }             
    }

    if(current==NULL && count==0)
    {
        cout<<"record not found!"<<endl;
    }
    



    return 0;
}

int llist::modifyRecord(int accountno, char new_address[])
{
    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"modifyRecord() was called successfully:"<<endl;
        cout<<"acc no received was:"<< accountno <<endl;
        cout<<"new address received was:"<< new_address <<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }

    record *current;
    int count=0;
    current= start;

    while(current!= NULL)
    {
        if((current->accountno)==accountno)
        {
            strncpy(current->address, new_address, 200);
            count++;            
            current = current->next;
        }
        else
        {
            current=current->next;
        }             
    }
    if(current==NULL && count==0)
    {
        cout<<"record not found!"<<endl;
    }

    return 0;
}

void llist::printAll()
{
    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"printAll() was called successfully:"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }

    int count=0;
    record *current;
    current = start;
    
    if(current==NULL)
    {
        cout<<"record not found!"<<endl;
    }
  
    while(current!=NULL)
    { 
        cout<<current->accountno<<endl;
        cout<<current->name<<endl;
        cout<<current->address<<endl;
        cout<<current->yearofbirth<<endl;
        current=current->next;
        count++;
    }

    cout<<"total records found:"<<count<<endl;
    

}

int llist::deleteRecord(int accountno)
{
    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"deleteRecord() was called successfully:"<<endl;
        cout<<"acc no received was:"<< accountno<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
    
    record *current;
    record *temp;
    int count=0;
    current = start;
    
    while(current!= NULL)
    {
        if((current->accountno)==accountno)
        {   
            if(current->next!=NULL)
            {
            temp = current;
            current= current->next;
            free(temp);
            }
            else
            {
            temp = current;
            current = NULL;
            free(temp);
            }
            count++;             
        }
        else
        {
            current=current->next;
        }             
    }
    if(current==NULL && count==0)
    {
        cout<<"record not found!"<<endl;
    }

    return 0;
}

llist::~llist()
{
    writefile();
};


