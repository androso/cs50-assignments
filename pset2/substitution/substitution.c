#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

bool key_checker (string s);

int main (int argc, string argv[])
{
    // Validating key
    if (argc != 2 || !key_checker(argv[1]))
    {
        printf("usage: ./substitution key\n");
        return 1;
    }
    
    string key = argv[1];
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: ");

    // Going through the plaintext
    for (int i = 0, len_text = strlen(plaintext); i < len_text; i++)
    {
        char c = plaintext[i];

        // Separating lowers and uppers
        if (islower(c))
        {
            // Knowing in which position in the alphabet is the current letter from plaintext and keeping track
            int counter1 = 0;
            for(int lower = 'a'; lower < c; lower ++){
                counter1++;
            }

            // Iterating through the key
            for (int j = 0, len = strlen(key); j < len; j++)
            {
                // Checking if both the counter from alphabet and the counter from the key coincide
                if (counter1 == j)
                {
                    // If so, we replace c with the letter in the index from key
                    c = tolower(key[j]);
                    printf("%c", c);
                }
            }
        } else if (isupper(c))
        {
            // Knowing in which position in the alphabet is the current letter from plaintext and keeping track
            int counter1 = 0;
            for (int upper = 'A'; upper < c; upper++)
            {
                counter1++;
            }

            // Iterating through the key
            for (int j = 0, len = strlen(key); j < len; j++)
            {
                // Checking if both the counter from alphabet and the counter from the key coincide
                if(counter1 == j)
                {
                    // If so, we replace c with the letter in the index from key
                    c = toupper(key[j]);
                    printf("%c", c);
                }
            }
        } else {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}

bool key_checker (string s) {
    int len = strlen(s);

    // Checking for length
    if (len != 26)
    {
        return false;
    }

    // Checking if every number is alphabetical
    for (int i = 0; i < len; i++) {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }

    // Checking for repeated values
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (s[i] == s[j])
            {
                return false;
            }
        }
    }
    return true;
}
