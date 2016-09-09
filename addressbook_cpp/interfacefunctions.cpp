/*****************************************************************

NAME: Nancy Mogire

DATE: JULY, 2016

FILE: interfacefunctions.cpp

DESCRIPTION: This file contains the functions running the interface to collect input for
the address list

****************************************************************/


#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#define MAX_USER_INPUT 10
#define MAX_ADDRESS 100
#define MAX_NAME 25
extern bool debugmode;

int getrecordnum(int num)
{
    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"getrecordnum() was called successfully:"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }


   while(num<=0){
             cin >> num;
             cin.ignore();
       
             if (cin){
             if(num<=0)
             {
               cout<<"Please enter a number greater than 0:"<<endl;           
             }       
             }
             else if(!cin)
             {  cin.clear();
             cin.ignore();
             cout<<"Please enter a number:"<<endl;
             cin.ignore();          
            }            
         }
    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"account number received:"<< num<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
return num;
}

void getAddress(char address[])
{
       if(debugmode==true)
       {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"getAddress() was called successfully:"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
       }

       int i=0;
           
       while ((i< MAX_ADDRESS) && (address[i]= cin.get())!='!')
       {                  
         i++;
       }
       address[i+1]='\0';

if(debugmode==true)
       {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"address received:"<<address <<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
       }

}

int getyearofbirth(int num, int lowerlimit, int upperlimit)
{
   if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"getyearofbirth() was called successfully:"<<endl;
        cout<<"lower age limit:"<< lowerlimit <<endl;
        cout<<"upper age limit:"<< upperlimit<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }

    num=0;

    while(num<=0){
             cin >> num;
             cin.ignore();
       
             if (cin){
             if(num<=0)
             {
               cout<<"Please enter a number greater than 0: "<<endl;
               continue;           
             }
             else if(num<lowerlimit)
             {
               cout<<"Please enter a year not earlier than:"<<lowerlimit<<endl;
               continue;           
             }
             else if(num>upperlimit)
             {
               cout<<"Please enter a year not later than:"<<upperlimit<<endl;           
             }       
             }
             else if(!cin)
             {  cin.clear();
             cin.ignore();
             cout<<"Please enter a number:\n";
             cin.ignore();          
            }            
         }

    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"year of birth received:"<< num<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }


return num;
}

void getname(char fullname[])
{
    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"getname() was called successfully:"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }

    int i=0;

    while ((i< MAX_NAME) && (fullname[i]= cin.get())!= '!')
    {                  
        i++;
    }
    fullname[i+1]='\0';

    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"name received:"<<endl<< fullname<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }

}

void readAddress(char address[], FILE *filename)
{
    if(debugmode==true)
    {   
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"readAddress() was called successfully:"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }

    int i=0; 
    while ((i< MAX_ADDRESS) && (address[i]=fgetc(filename))!='!'){           
    i++;
    }
    address[i+1]='\0';


}
