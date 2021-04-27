#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check_valid_key(string s);

int main (int argc, string argv[]) {
    if (argc != 2 || !check_valid_key(argv[1])) {
        printf("usage: ./caesar3 key\n");
        return 1;
    }
    
    int key = atoi(argv[1]);
    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");
    
    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        
        char c = plaintext[i];
        if (islower(c)) {
            printf("%c", (c - 'a' + key) % 26 + 'a');
        } else if (isupper(c)) {
            printf("%c", (c - 'A' + key) % 26 + 'A');
        }
    }
    printf("\n");
    return 0;
}

bool check_valid_key(string s) {
    for (int i = 0, n = strlen(s); i < n; i++) {
        if (!isdigit(s[i])){
            return false;
        } else {
            return true;
        }
    }
    return true;
}