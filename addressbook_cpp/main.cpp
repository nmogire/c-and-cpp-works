
/*****************************************************************
NAME: Nancy Mogire

DATE: JULY, 2016

FILE: main.cpp

DESCRIPTION: This file is a driver for address record list project. It contains the interface to get user input and display output.

****************************************************************/
#include <string>
#include <iostream>
#include <stdlib.h>
#include "record.h"
#include "llist.h"

using namespace std;

#define MAX_ADDRESS 100
#define MAX_NAME 25

bool debugmode = true;


int main(int argc, char* argv[])
{

    
    char menuchoice;      
    int num, recordno, yearofbirth;
    char accAddress[MAX_ADDRESS];
    char fullname[MAX_NAME];
    int consoleOpen;	
    consoleOpen = 1;
   // llist mylist;
   // llist mylist( "proj2.txt" )----deprecated

    char filename[] = "./dblist.txt";
    llist mylist(filename);

    system("clear");

    do
    {
    cout<< "Choose action: " <<endl;
    cout<<"[1]Add a new record " <<endl;
    cout<<"[2]Modify a record using record number as primary key " <<endl;
    cout<<"[3]Print info about a record using record number as primary key " <<endl;
    cout<<"[4]Print all information in the list " <<endl;
    cout<<"[5]Delete a record using record number as primary key " <<endl;
    cout<<"............... " <<endl;
    cout<<"[q]Quit Program " <<endl;
    cout<<"  " <<endl;          
    cin>>menuchoice;        
    switch(menuchoice)
        {
         case '1':
             
         num = 0;                          
         cout<<"Enter Record Number: " << endl;
         cin.ignore();
         recordno=getrecordnum(num);
         

         cout<<"Enter Full Name: " << endl;
         cin.get( fullname, 25 );
         
         cout<<"Enter Address: " << endl;
         getAddress(accAddress);
         
         
         cout<<"Enter Year of Birth: " << endl;         
         yearofbirth = getyearofbirth(yearofbirth, 1900, 2016);
         cout<<" "<<endl;       
         cout<<"Thank you! a new record will be created " << endl;
         cout<<" "<<endl;        
         mylist.addRecord(recordno, fullname, accAddress, yearofbirth);
                    
         break;

         case '2':                                        
             cout<<"Record number to modify: " << endl;
             cin.ignore();
             recordno=getrecordnum(num);
        
             cout<<"New Address: " << endl;
             getAddress(accAddress);
             cout<<" "<<endl;           
             cout<<"Thank you! The record will be modified " << endl;
             cout<<" "<<endl;
             mylist.modifyRecord (recordno, accAddress);            
                     
             break;

         case '3':
             cout<<"Enter record number to print: " << endl;
             cin.ignore();
             recordno=getrecordnum(num);
             cout<<"record " << recordno<< ":"<< endl;
             mylist.printRecord(recordno);
             cout<<" "<<endl;
             cout<<"Done!" << endl;
             cout<<" "<<endl;        
             break;

         case '4':
             cout<<"Address list:" << endl;
             mylist.printAll();
             break;

         case '5': 
             cout<<"Enter record number to delete: " << endl;
             cin.ignore();
             recordno=getrecordnum(num);
             cout<<" "<<endl;
             cout<<"Thank you! The record will be deleted " << endl;
             cout<<" "<<endl;

             mylist.deleteRecord(recordno);                                 
                
             break;

         case 'q':
             consoleOpen=0;
             break;

         case '\n':           
             break;

         default:
             cout<<"Please choose an option from the list above."<<endl;
             break;
        }
    }while(consoleOpen!=0);
  
return 0;
}
