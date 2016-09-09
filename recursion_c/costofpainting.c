/*****************************************************************

NAME: Nancy Mogire

DATE: JUL, 2016

FILE: costofpainting.c

DESCRIPTION: This file contains a function to calculate the cost of painting a road section based on specified rules --project on recursion

--Each painter will only paint a section of 2 miles of stripes on the road and charge $200.If the road is longer than 2 miles, the painter will divide the road into three equal parts, and subcontract each of those parts to three other painters, charging $100 to hire the three painters. Each of the hired painters will do the same thing.
****************************************************************/

#include <stdio.h>


/*****************************************************************

Function name: costofpainting

DESCRIPTION: function to calculate cost of painting a road section based on the length in miles and return the output as an integer

Parameters: double length

Return value: int

****************************************************************/

int costofpainting(double length)
{   
    int cost;
    int subcost;
    
    if(length<=2)
    {
        cost = 200;
    }
    else
    {
        length= length/3;
        subcost= 3*(costofpainting(length));
        cost = subcost+300;
    }

    return (int) cost;
}
