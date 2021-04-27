#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main (void) {
    //PROMPTING HEIGHT
    int height = get_positive_int();

    //CREATE N ROWS
    for (int row = 0; row < height; row++) {

        //PRINT " " (height - row - 1) times
        int dots = height - row - 1;
        for (int i = 0; i<dots; i++ ) {
            printf(" ");
        }

        //PRINT # (row+1) times
        for (int x = -1 ; x < row; x++) {
            printf ("#");
        }
        printf ("\n");
    }
}

int get_positive_int(void){
    int n;
    do{
        n = get_int("Height between 1-8: ");
    } while (n < 1 || n > 8);
    return n;
}