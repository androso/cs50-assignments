#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check_valid_key(string s);

int main (int argc, string argv[]) {
    if (argc != 2 || !check_valid_key(argv[1])) {
        printf("Usage: ./caesar2 key\n");
        return 1;
    }
    
    int key = atoi(argv[1]);
    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");
    
    // Iterating trough each letter of plaintext
    for (int i = 0, n = strlen(argv[1]); i < n; i++) {
        
        char c = plaintext[i];
        if (isalpha(c)) {
            char m = 'A';
            if (islower(c)) {
                m = 'a';
            }
            printf("%c", (c-m + key) % 26 + m);
        } else {
            printf("%c", c);
        }
    }
    printf("\n");
}

bool check_valid_key(string s) {
    for (int i = 0, n = strlen(s); i < n; i++) {
        if (!isdigit(i)) {
            return false;
        } else {
            return true;
        }
    }
    return true;
}