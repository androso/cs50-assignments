#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void) {
    //PRINTING FOR CHANGE
    float changeOwed;
    do {
        changeOwed = get_float("Change owed: ");
    } while (changeOwed < 0);

    //Converting dollars to cents
    int cents = round(changeOwed * 100);

    //Variables keeping track of coins and how much is remaining
    int coins = 0;
    int remaining = cents;

    //
    for (int quarter = 25; remaining >= 25; remaining = remaining - quarter) {
        coins ++;
    }
    for (int dime = 10; remaining >= dime; remaining = remaining - dime) {
        coins ++;
    }
    for (int nickel = 5; remaining >= nickel; remaining = remaining - nickel) {
        coins ++;
    }
    for (int penny = 1; remaining >= penny; remaining = remaining - penny) {
        coins ++;
    }

    //PRINTING NUMBER OF COINS
    printf ("%i\n", coins);
}