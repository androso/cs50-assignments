#include <cs50.h>
#include <stdio.h>

int main (void) {
    //Prompting user for number
    long ccNumber;
    do {
        ccNumber = get_long("Card Number: ");
    } while (ccNumber < 1);

    //CHECKSUM

    //CASE 1
    int sum = 0;
    for(long workingCC = ccNumber; workingCC > 0; workingCC = workingCC/100){
        int lastDigit = workingCC % 10;
        sum = sum + lastDigit;
    }
    //CASE 2
    long workingCC = ccNumber;
    for(workingCC = workingCC/10; workingCC > 0; workingCC = workingCC/100) {
        int lastDigit = workingCC % 10;
        int multipliedDigit = lastDigit *2;
        if (multipliedDigit > 9) {
            int first = multipliedDigit / 10;
            int second = multipliedDigit % 10;
            sum = sum + first + second;
        } else if (multipliedDigit <= 9) {
            sum = sum + multipliedDigit;
        }
    }
    //CHECKING CARD LENGHT IF IT'S 15 OR 16
    int counter = 0;
    for(long workingCredit = ccNumber; workingCredit>0; workingCredit = workingCredit/10) {
        counter ++;
    }
    if (counter != 16 && counter != 15) {
        printf("INVALID");
    }

    //GETTING THE FIRST TWO NUMBERS
    int remainderNumber;
    for (long workingCredit = ccNumber; workingCredit > 10; workingCredit = workingCredit/10) {
        remainderNumber = workingCredit;
    }

    if ((remainderNumber /10 == 5) && (0 < remainderNumber % 10 && remainderNumber < 6)) {
        printf("MASTERCARD");
    } else if (remainderNumber == 34 || remainderNumber == 37) {
        printf("AMEX");
    } else if ((remainderNumber / 10 == 4) || (remainderNumber == 13)) {
        printf("VISA");
    } else {
        printf("INVALID");
    }

}
