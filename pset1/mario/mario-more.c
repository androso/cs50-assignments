#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main (void) {
    //PROMPTING THE USER FOR A NUMBER
    int height = get_positive_int();
    
    //CREATING ROWS
    for (int row = 0; row < height; row++){
        
        //LEFT SIDE OF PYRAMID
        //printing dots
        int dots = height - row - 1;
        for (int i = 0; i < dots; i++) {
            printf(" ");
        }
        
        //printing hashes
        for (int yy = -1; yy < row; yy++) {
            printf("#");
        }
        
        //Printing space between pyramids
        printf("  ");
        
        //RIGHT SIDE OF PYRAMID
        for (int y = -1; y < row; y++) {
            printf("#");
        }
        printf("\n");
    }
}

int get_positive_int(void) {
    int n;
    do {
        n = get_int("Height between 1-8: ");        
    } while (n < 1 || n > 8);
    return n;
}