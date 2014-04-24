/*
    greedy.c
    
    Author: Chris Anders, chris@hell-labs.de
    
    This file is a solution of the greedy algorithm problem from
    pset1 of CS50.
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define QUARTER 25;
#define DIME 10;
#define NICKEL 5;

int main(void) 
{
    // Variable declarations
    float given_amount = 0;
    int cent_amount = 0;
    int quarter_count = 0;
    int dime_count = 0;
    int nickel_count = 0;
    int leftover = 0;
    int coin_count = 0;
    
    //Input handling
    do 
    {
        printf("You gave me: ");
        given_amount = GetFloat();
        //If given amount is zero or less then zero checked
        if(given_amount == 0||given_amount <= 0)
        printf("Number Should be greater then Zero EG:10\n:");
    }
    while(given_amount <= 0);

    // Given amount is convert to cents
    cent_amount = (int)round(given_amount*100);

    // Quarters
    quarter_count = cent_amount / QUARTER;
    leftover = cent_amount % QUARTER;
    
    // Dimes
    dime_count = leftover / DIME;
    leftover = leftover % DIME;
    
    // Nickels
    nickel_count = leftover / NICKEL;
    leftover = leftover % NICKEL;
    
    // Leftover at this stage is pennies
    coin_count = quarter_count + dime_count + nickel_count + leftover;
    
    // Pretty print
    // printf("You get %d coins: %d quarters, %d dimes, %d nickels and %d pennies.\n", coin_count, quarter_count, dime_count, nickel_count, leftover);
    
    //Required output:
    printf("%d\n", coin_count);
    
    return 0;
}
