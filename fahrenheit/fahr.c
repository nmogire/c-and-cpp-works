/*****************************************************************
Author: Nancy Mogire

DATE: JUNE 2016

FILE: fahr.c

DESCRIPTION: This program converts temperature from celsius to fahrenheit. It takes input from a user for the maximum value in celsius and rounds it up to the nearest multiple of five if it's not already a multiple of 5. It prints the output in a table

****************************************************************/

#include <stdio.h>
#include <string.h>


int upperMultOfFive(int);
void convertFtoC(int);

/*rounding up the max to 5*/
int upperMultOfFive(int num){
    if((num%5)==0){
        num = num;
    }
    else{
        num = num + (5-(num%5));
    }
 return num;
}

/*converts celsius to fahreheit and prints out*/
void convertFtoC(int max){
    int Fahr=0;
    int step=5;
    float Celsius;
    int i=0, l=0;
 
      while(Fahr<=max){
      Celsius=(5.0/9.0)*(Fahr-32);
      printf("%3d\t%10.2f\n", Fahr, Celsius);
      Fahr= Fahr+step;
      }


  }


int main()
{
  
    char userInput[62];
    char celsius[500];
    char fahr[500];
    int num=0, max, l=0;

    printf("Please enter a number between 1 and 300\n");
    while(num == 0){        
        fgets(userInput,63,stdin);

        if(strlen(userInput)<2 || strlen(userInput)> 4){
            printf("Please check that you entered a number between 1 and 3 digits\n");
            num=0;
            continue;
         }
        if(sscanf(userInput, "%d", &num)!=1){
           num = 0;
           printf("please enter a number.\n");
           continue;
        }
        if(num<1|| num>300){
          num=0;
          printf("please enter a number between 1 and 300.\n");
          continue;
        }
    }

    max= upperMultOfFive(num);
    printf("your max is: %d\n", max);
    
    convertFtoC(max);

    return(0);
}

  



