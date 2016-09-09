/*****************************************************************

NAME: Nancy Mogire

DATE: JULY, 2016

FILE: fahr.cpp

DESCRIPTION: This file contains a program that converts fahrenheit to celsius. 
Both the interface and the conversion functions are contain here 

****************************************************************/

#include <iostream>
#include <iomanip> 
 
using namespace std;

int upperMultOfFive(int);
void convertFtoC(int, float &);


/*****************************************************************

Function name: upperMultOfFive

DESCRIPTION: takes an integer and rounds it up to the nearest multiple of five

Parameters: int

Return values: int

****************************************************************/

int upperMultOfFive(int num)
{
    if((num%5)==0){
        num = num;
    }
    else{
        num = num + (5-(num%5));
    }
    
    return num;
}


/*****************************************************************

Function name: convertFtoC

DESCRIPTION: takes values in fahrenheit and converts the into celsius. 
also serves as the print function.

Parameters: int, float

Return values: none

****************************************************************/

void convertFtoC(int max, float (&results)[100])
{
    float Fahr=0;
    float step=5.0;
    float Celsius;
    int i=0;
    cout<<setw(3)<<right<<"Fahrenheit"<<setw(6)<<" "<< "Celsius"<<endl;
    while(Fahr<=max){
        Celsius=(5.0/9.0)*(Fahr-32);
        results[i]=Celsius;
        cout<<setw(3)<<right<<Fahr<<setw(10)<<right<<" ";
        cout<< setw(10)<<right<<setprecision(3)<< results[i]<<endl;
        i++;
        Fahr= Fahr+step;
    }          
}


/*****************************************************************

Function name: main

DESCRIPTION: project driver and interface function
displays a menu using a do while loop and accepts input to manipulate files

Parameters: argc, argv[], also uses getchar() and fgets to read from stdin

Return values: 0 for success, non-zero for failure

****************************************************************/

int main()
{
   int max_num=0;
   int max;
   float results[100];     
    
   cout<<"Please enter a number for the maximum temperature:\n";
   while(max_num<=0){
       cin >> max_num;
       cin.ignore();
       
       if (cin){
           if(max_num<=0)
           {
               cout<<"Please enter a number greater than 0:\n";           
           }       
       }
       else if(!cin)
       {  cin.clear();
          cin.ignore();
          cout<<"Please enter a number:\n";
          cin.ignore();          
       }            
   } 
  
   max= upperMultOfFive(max_num);
  
   convertFtoC(max, results);

   return 0;
}
