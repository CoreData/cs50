#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Variable declarations
    float given_amount = 0;
    int cent_amount = 0;
    int twenty_count = 0;
    int ten_count = 0;
    int five_count = 0;
    int dollar_count = 0;
    int quarter_count = 0;
    int dime_count = 0;
    int nickel_count = 0;
    int leftover = 0;
    int coin_count = 0;
    int TWENTY = 2000;
    int TEN = 1000;
    int FIVE = 500;
    int DOLLAR = 100;
    int QUARTER = 25;
    int DIME = 10;
    int NICKEL = 5;

    //Input handling
    do
    {
        printf("You gave me: $");
        given_amount = get_float();
        //If given amount is zero or less then zero checked
        if(given_amount == 0||given_amount <= 0)
        printf("Number Should be greater then Zero EG:10\n:");
    }
    while(given_amount <= 0);

    // Given amount is convert to cents
    cent_amount = (int)round(given_amount*100);

    // TWENTY'S
    twenty_count = cent_amount / TWENTY;
    leftover = cent_amount % TWENTY;

    // TEN'S
    ten_count = leftover / TEN;
    leftover = leftover % TEN;

    // FIVE'S
    five_count = leftover / FIVE;
    leftover = leftover % FIVE;

    // Dolla Dolla Bills Y'all
    dollar_count = leftover / DOLLAR;
    leftover = leftover % DOLLAR;

    // Quarters
    quarter_count = leftover / QUARTER;
    leftover = leftover % QUARTER;

    // Dimes
    dime_count = leftover / DIME;
    leftover = leftover % DIME;

    // Nickels
    nickel_count = leftover / NICKEL;
    leftover = leftover % NICKEL;

    // Leftover at this stage is pennies
    coin_count = quarter_count + dime_count + nickel_count + leftover;

    // Pretty print
    printf("Bills: %d Twentys, %d tens, %d fives, %d dollars -- And %d coins: %d quarters, %d dimes, %d nickels and \n%d pennies.\n", twenty_count, ten_count, five_count, dollar_count, coin_count, quarter_count, dime_count, nickel_count, leftover);

    //Required output:
    //printf("%d\n", coin_count);

    return 0;
}
