#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[]) {

    // Cheking if the number of arguments is valid
    if (argc > 2) {
        printf("Too many arguments supplied.\n");
        return 1;
    } else if (argc < 2) {
        printf("You must provide me an argument.\n");
        return 1;
    }


    // Iterating through the argument provided to know if it's a digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++){
        if (argv[1][i] < 48 || argv[1][i] > 57) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    int key = atoi(argv[1]);
    string text = get_string("Plaintext: ");
    printf("ciphertext: ");

    // Iterating through each letter of text string

    for (int i = 0, n = strlen(text); i < n; i++) {

        if (isupper(text[i]))
        {
            // Assigning a number from 0-25 to the letter
            int counter1= 0;
            for(int upper = 'A'; upper < text[i]; upper++)
            {
                counter1++;
            }
            // Knowing the number of spaces we'll need to move
            int position = (counter1 + key) % 26;

            // Moving to the destination letter
            int counter2  = 0;
            for (int upper = 'A'; position >= counter2; upper++)
            {
                if (counter2 == position) {
                    text[i] = upper;
                }
                counter2++;
            }
        } else if (islower(text[i])) {

            // Assigning a number from 0-25 to the letter
            int counter1= 0;
            for(int lower = 'a'; lower < text[i]; lower++)
            {
                counter1++;
            }
            // Knowing how many spaces we'll need to move
            int position = (counter1 + key) % 26;

            // Moving to the destination letter
            int counter2  = 0;
            for (int lower = 'a'; position >= counter2; lower++)
            {
                if (counter2 == position) {
                    text[i] = lower;
                }
                counter2++;

            }
        }
    }
    printf ("%s\n", text);
}