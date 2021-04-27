#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool key_checker(string s);

int main (int argc, string argv[])
{
    // 
    if (argc!= 2 || !key_checker(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string text = get_string("plaintext: ");
    string difference = argv[1]; 
    for (int i = 'A'; i < 'Z'; i++){
        difference[i - 'A'] = toupper(difference[i-'A']) - i;
      //difference ['A'-'A'] = toupper(difference['A'-'A']) - 'A';
      //difference [0] = toupper(difference[0]-'A');
      //difference [0] = difference[0] - 'A'
      //difference [0] = 21 <- the difference from A
    } 
    printf("ciphertext: ");
    //
    for (int i = 0, len = strlen(text); i < len; i ++)
    {
        //Let's say the first one is 'a'
        if (isalpha(text[i]))
        {
            text[i] = text[i] + difference [text[i]- (isupper(text[i]) ? 'A' : 'a')];
          //text[0] = text[0] + difference[text[0] - (isupper(text[0]) ? 'A' : 'a')];
          //text[0] = 'a'     + difference[  'a'   - (isupper(  'a'  ) ? 'A' : 'a')]; 
          //text[0] = 'a'     + difference[  'a'   - 'a'];
          //text[0] = 'a'     + difference[0];
          //text[0] = 'a'     + 21;
          //text[0] = 
        }
        printf("%c", s[i]);
    }
    printf("\n");
}

bool key_checker(string s)
{
    int len = strlen(s);
    
    //Checking for length
    if (len != 26) {
        return false;
    }
    
    int freq[26] = {0};
    for (int i = 0; i < len; i++)
    {
        // Checking if every number is alphabetical
        if (!isalpha(s[i]))
        {
            return false;
        }
        // Finding what's the location of s[i] related to 'A', i.e The location of J in the alphabet = 9 -> it's the ninth position in an array from 0-25
        int index = toupper(s[i]) - 'A';
        // Checking for repeated values / letters
        if (freq[index] > 0) {
            return false; 
        }
        freq[index]++;
    }
    return true;
}