#include <cs50.h>
#include <stdio.h>

int main (void) {
    //Prompting for credit card
    long ccNumber;
    do {
        ccNumber = get_long("Credit number: ");
    } while (ccNumber < 1);
    
    
    //CHECKSUM
    //CASE 1 -> last digit
    int sum = 0;
    for (long workingCC = ccNumber; workingCC > 0; workingCC = workingCC / 100) {
        int lastDigit = workingCC % 10;
        sum = sum + lastDigit;
    }
    
    //Case 2 -> second to-last digit
    for (long workingCC = ccNumber / 10; workingCC >= 10; workingCC = workingCC/100) {
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
    
    //Getting first digits
    long firstDigits = ccNumber;
    for (int i = 0; firstDigits > 100; i++) {
        firstDigits = firstDigits / 10;
    }
    
    //Checking how long it is
    int counter = 0;
    for (long workingCC = ccNumber; workingCC > 0; workingCC = workingCC/10) {
        counter++;
    }
    
    //checkint the type of card and if its size is valid
    if ((firstDigits / 10 == 5) && (0 < firstDigits % 10 && firstDigits % 10 < 6) && (counter == 16)) {
        printf("MASTERCARD\n");
    }else if ((firstDigits == 34 || firstDigits == 37) && (counter == 15)) {
        printf("AMEX\n");
    }else if ((firstDigits / 10 == 4 || firstDigits == 13) && (counter == 16)){
        printf("VISA\n");
    } else{
        printf("INVALID\n");
    }
}