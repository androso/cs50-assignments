#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void) {
    //PROMPING FOR CHANGE
    float changeOwed;
    do{
        changeOwed = get_float("Change Owed: ");
    } while (changeOwed < 0);
    
    //0.20 TO 20, DOLLAS TO CENTS
    int cents = round(changeOwed * 100);
    
    //Keeping track of coins and how much is remaining
    int remain = cents; 
    int counter = 0;
    
    for (int quarter = 25; remain >= quarter; remain = remain - quarter) {
        counter ++;
    }
    for (int dime = 10; remain >= dime; remain = remain - dime) {
        counter ++;
    }
    for (int nickel = 5; remain >= nickel; remain = remain - nickel) {
        counter ++;
    }
    for (int penny = 1; remain >= penny; remain = remain - penny) {
        counter ++;
    }
    printf("%i\n",counter);
}