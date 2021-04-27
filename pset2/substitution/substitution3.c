#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool key_checker(string key);

int main (int argc, string argv[])
{
    // Validating key
    if (argc != 2)
    {
        printf("You need to give me 2 arguments");
        return 1;
    } else if (!key_checker(argv[1])) {
        printf("usage: ./substitution3 key");
        return 1;
    }
    string text = get_string("plaintext: ");
    // Finding the difference between text[i] and key[i]
    string difference = argv[1];
    for (int i = 'A'; i < 'Z'; i ++)
    {
        difference[i-'A'] = toupper(difference[i-'A']) - i;
      //difference[T-A] = toupper(difference[T-A] - T;
      //difference[19] = toupper(difference[19]) - T;
      //difference[19] = Z - T;
      //difference[19] = 6;
    }
    printf("ciphertext: ");
    //
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            text[i] = text[i] + difference[text[i] - (isupper(text[i]) ? 'A' : 'a')];
        }
        printf("%c", text[i]);
    }
    printf("\n");
    return 0;
}

bool key_checker(string key)
{
    int len = strlen(key);
    
    //Checking the length 
    if (len != 26) {
        return false;
    }
    
    // This way if key[i] is J, index = 9
    int freq[26] = {0};
    //Iterating through key
    for (int i = 0; i < len; i++) {
        //Cheking if it's not a digit
        if (isdigit(key[i]))
        {
            return false;
        }
        
        int index = toupper(key[i]) - 'A';
        // Checking if it's repeated
        if  (freq[index] > 0)
        {
            return false;
        } 
            freq[index]++;
    
    }
    return true;
}