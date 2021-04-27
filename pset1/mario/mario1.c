#include <cs50.h>
#include <stdio.h>


int main (void) {
    //PROMPTING THE USER FOR A HEIGHT
    int height;
    do{
        height = get_int("Give me a height between 1-8: ");
    } while (height > 8 || height < 1);
    
    //CREATING THE PYRAMID
    for (int rows = 0; rows < height; rows ++) {
        
        //PRINTING " "
        int space = height - rows - 1;
        for (int i = 0; i < space; i++) {
            printf(" ");
        }
        
        for (int columns = -1; columns < rows; columns ++) {
            printf("#");
        }
        printf("\n");
    }
}