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
    }
    while(given_amount <= 0);

    // Given amount is convert to cent
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
    
    // printf("You get %d coins: %d quarters, %d dimes, %d nickels and %d pennies.\n", coin_count, quarter_count, dime_count, nickel_count, leftover);
    //Required output:
    printf("%d\n", coin_count);
    
    return 0;
}