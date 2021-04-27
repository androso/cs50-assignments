CREDIT CARD PROBLEM

AMERICAN EXPRESS NUMBERS start with 34 or 27 -> 15 digit numbers
MASTERCARD numbers start with 51, 52, 53, 54, 55 -> 16 digit numbers
VISA numbers start with 4 -> 13. 16 digit numbers



Storing the credit card number in a variable.

creditCard = get int

First case
getting the last number, let's say our cc is 4,908,670,605,040,304

    creditCard % 10 will give back 4
Now, to get the third to-last number:

    creditCard / 100 will give back 3

Getting the next other digit.
    Using a loop, each iteration we increase n * 100
        starting from 10.
            10 * 10 = 100; third to-last, will give 3
            100 * 100 = 10,000; fifth to-last, will give 4
            1000 * 100 = 1,000,000; seventh to-last, will give 5
            1,000,000 * 100 = 100,000,000; ninth to-last, will give 6
            100,000,000 * 100 = 10,000,000,000; eleventh to-last, will give 7
            10,000,000,000 * 100 = 1,000,000,000,000; thirteenth to-last, will give 8
            1,000,000,000,000 * 100 = 100,000,000,000,000; fourteenth to-last, will give 9
                and so on.

Second case
getting the penultimate number of 4 908 670 605 040 314
    First, delete the last value, so that the second to-last number ends up being the last one
        creditCard / 10 will give back 490867060504031
    Second, we use the last function to get the last value
        creditCard % 10 will give back 3.

Getting the next other digit
    While using a loop starting with value 10 (I think) we just use the following i = i*100 where i is firstly 10 but takes the product as its value after each iteration

AMERICAN EXPRESS: 34 or 37 and 15 digit numbers.
MASTERCARD: 51, 52, 53,54, or 55 and 16 digit numbers.
VISA: 4, 13 and 16 digit numbers.
