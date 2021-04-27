#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

bool key_checker (string s);

int main (int argc, string argv[]) {
    if (argc != 2) {
        printf ("usage ./duplicate key");
        return 1;
    }else if (!key_checker(argv[1])) {
        printf ("usage ./duplicate key");
        return 1;
    }
}

bool key_checker (string s) {
    int len = strlen(s);
    // Checking for length
    if (len != 26) {
        return false;
    }
    // Checking if every number is alphabetical
    for (int i = 0; i < len; i++) {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    // Cheking for repeated values
    for (int i = 0; i < len-1; i++) {

        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}