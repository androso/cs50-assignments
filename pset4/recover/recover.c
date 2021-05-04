#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;
#define BLOCKSIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./recover card.raw");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == NULL) {
        printf("Image cannot be opened");
        return 1;
    }
    
    
    BYTE buffer[BLOCKSIZE];
    int counter = 0;
    FILE *jpeg;
    char *name = malloc(4);
    while (fread(&buffer, BLOCKSIZE, 1, card)) {
        // If it's the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            // If it's the first JPEG
            
            if (counter == 0) {
                sprintf(name, "%03i.jpg", counter);
                jpeg = fopen(name, "w");
                fwrite(&buffer, BLOCKSIZE, 1, jpeg);
                counter++;
            } else {
                // If it's another JPEG we should close the last JPEG opened
                fclose(jpeg);
                sprintf(name, "%03i.jpg", counter);
                jpeg = fopen(name, "w");
                fwrite(&buffer, BLOCKSIZE, 1, jpeg);
                counter++;
            }
        } else {
            // If it's not the start of a JPEG we'll keep writing
            if (counter >= 1) {
                /* No matter if you'd opened a file inside an if that was inside a previous if, 
                the file will keep bein opened, AVOID DOING WHAT I DID
                sprintf(name, "%03i.jpg", counter);
                jpeg = fopen(name, "a");*/
                fwrite (&buffer, BLOCKSIZE, 1, jpeg);
            }
            
        }
        
    }
    fclose (jpeg);
    fclose (card);
    free(name);
    return 0;
}