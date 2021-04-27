#include <cs50.h>
#include <stdio.h>

int main (void) {
    //PROMPTING FOR HEIGHT
    int height;
    do {
        height = get_int("Height between 1-8: ");
    } while (height < 1 || height > 8);
    
    //MAKING PYRAMIDS
    for (int rows = 0; rows < height; rows++) {
        //PRINTING SPACES
        int spaces = height - rows - 1;
        for (int i = 0; i < spaces; i++) {
            printf(" ");
        }
        
        //PRINTING #
        for(int columns = -1; columns < rows; columns ++) {
            printf("#");
        }
        
        //PRINTING SPACE BETWEEN PYRAMIDS
        printf("  ");
        
        //MAKING THE SECOND PYRAMID
        for (int columns = -1; columns < rows; columns++) {
            printf("#");
        }
        printf("\n");
    }
}