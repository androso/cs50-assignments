#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // An image is just a 2-d array.
    // We'll need a loop to iterate through each row of image
    for (int i = 0; i < height; i++) {
        // Another loop to iterate through each column of that row
        for (int j = 0; j < width; j++) {
            int avrg;
            avrg = round( ((float)image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);

            image[i][j].rgbtBlue = avrg;
            image[i][j].rgbtGreen = avrg;
            image[i][j].rgbtRed = avrg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    int mid = round((float) width / 2);
    for (int i = 0; i < height; i++) {

        for (int j = 0; j < mid; j++) {
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width - (j+1)];
            image[i][width - (j+1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            if (i == 0 && j == 0) {
                // First row, first item
                float red = 0;
                float blue = 0;
                float green = 0;

                for (int k = 0; k <= 1; k++) {
                    for (int l = 0; l <= 1; l++) {
                        red = red + image [k][l].rgbtRed;
                        blue = blue + image[k][l].rgbtBlue;
                        green = green + image[k][l].rgbtGreen;
                    }
                }

                // Averaging
                copy[i][j].rgbtRed = round (red / 4);
                copy[i][j].rgbtGreen = round(green / 4);
                copy[i][j].rgbtBlue = round(blue / 4);
            } else if (i == 0 && (j > 0 && j < width - 1)) {
                // Just first row
                float red = 0;
                float green = 0;
                float blue = 0;

                for (int k = i; k <= 1; k++) {
                    for (int l = j-1; l <= j+1; l++) {
                        red = red + image[k][l].rgbtRed;
                        blue = blue + image[k][l].rgbtBlue;
                        green = green + image[k][l].rgbtGreen;
                    }
                }

                 //Averaging
                 copy[i][j].rgbtRed = round(red / 6);
                 copy[i][j].rgbtGreen = round (green / 6);
                 copy[i][j].rgbtBlue = round (blue / 6);


            } else if (i == 0 && j == (width -1)) {
                float red = 0;
                float green = 0;
                float blue = 0;

                // First row, last item
                for (int k = i; k <= 1; k++) {
                    for (int l = j-1; l <= j; l++) {
                        red = red + image[k][l].rgbtRed;
                        green = green + image[k][l].rgbtGreen;
                        blue = blue + image[k][l].rgbtBlue;
                    }
                }

                // Averaging
                copy[i][j].rgbtRed = round (red / 4);
                copy[i][j].rgbtGreen = round (green / 4);
                copy[i][j].rgbtBlue = round (blue / 4);


            } else if (j == 0 && (i > 0 && i < height - 1)) {
                // Just first item
                float red = 0;
                float blue = 0;
                float green = 0;

                for (int k = i-1; k <= i+1; k++) {
                    for (int l = 0; l <=1; l++) {
                        red = red + image[k][l].rgbtRed;
                        green = green + image[k][l].rgbtGreen;
                        blue = blue + image[k][l].rgbtBlue;
                    }
                }

                // Averaging
                copy[i][j].rgbtRed = round (red / 6);
                copy[i][j].rgbtGreen = round (green / 6);
                copy[i][j].rgbtBlue = round (blue / 6);
            } else if (j == (width -1) && (i > 0 && i < height - 1) ) {
                // Just last item
                float red = 0;
                float green = 0;
                float blue = 0;

                for (int k = i-1; k <= i+1; k++) {
                    for (int l = j-1; l <= j; l++) {
                        red = red + image[k][l].rgbtRed;
                        green = green + image[k][l].rgbtGreen;
                        blue = blue + image[k][l].rgbtBlue;
                    }
                }

                // Averaging
                copy[i][j].rgbtRed = round (red / 6);
                copy[i][j].rgbtGreen = round (green / 6);
                copy[i][j].rgbtBlue = round (blue / 6);
            } else if (j == 0 && i == (height-1)) {
                // Last row, first item
                float red = 0;
                float blue = 0;
                float green = 0;

                for (int k = i-1; k <= i; k++) {
                    for (int l = 0; l <= 1; l++) {
                        red = red + image [k][l].rgbtRed;
                        blue = blue + image[k][l].rgbtBlue;
                        green = green + image[k][l].rgbtGreen;
                    }
                }

                // Averaging
                copy[i][j].rgbtRed = round (red / 4);
                copy[i][j].rgbtGreen = round(green / 4);
                copy[i][j].rgbtBlue = round(blue / 4);
            } else if (i == height -1 && (j > 0 && j < width - 1)) {
                // Just last row
                float red = 0;
                float green = 0;
                float blue = 0;

                for (int k = i-1; k <= i; k++) {
                    for (int l = j-1; l <= j+1; l++) {
                        red = red + image[k][l].rgbtRed;
                        blue = blue + image[k][l].rgbtBlue;
                        green = green + image[k][l].rgbtGreen;
                    }
                }

                 //Averaging
                 copy[i][j].rgbtRed = round(red / 6);
                 copy[i][j].rgbtGreen = round (green / 6);
                 copy[i][j].rgbtBlue = round (blue / 6);
            } else if (i == (height -1) && j == (width -1)) {
                // Last row, last item
                float red = 0;
                float green = 0;
                float blue = 0;

                for (int k = i-1; k <= i; k++) {
                    for (int l = j-1; l <= j; l++) {
                        red = red + image[k][l].rgbtRed;
                        green = green + image[k][l].rgbtGreen;
                        blue = blue + image[k][l].rgbtBlue;
                    }
                }

                // Averaging
                copy[i][j].rgbtRed = round (red / 4);
                copy[i][j].rgbtGreen = round (green / 4);
                copy[i][j].rgbtBlue = round (blue / 4);

            } else {
                float red = 0;
                float blue = 0;
                float green = 0;

                for (int k = i-1; k <= i+1; k++) {
                    for (int l = j-1; l <= j+1; l++) {
                        red = red + image[k][l].rgbtRed;
                        green = green + image[k][l].rgbtGreen;
                        blue = blue + image[k][l].rgbtBlue;
                    }
                }
                // Averaging

                copy[i][j].rgbtRed = round ( red / 9);
                copy[i][j].rgbtGreen = round ( green / 9);
                copy[i][j].rgbtBlue = round (blue / 9);
            }
        }
    }

    for (int i = 0; i < height; i ++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = copy[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    /*
    1. Iterate over every pixel in the image. (Done)
    2. Apply the Gx kernel
    3. Apply the Gy kernel
    4. Square root of Gx^2 + Gy^2
    5. Nomarlize gradient length to the range 0-255
    6. Set pixels to new values
    */

    int gradX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int gradY[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    // Adding two more columns and two more rows
    RGBTRIPLE copy[height+2][width+2];
    // Filling the first row, last row, first column and last column
    for (int j = 0; j <= width + 1; j++) {
        copy[0][j].rgbtRed = 0;
        copy[0][j].rgbtBlue = 0;
        copy[0][j].rgbtGreen = 0;
    }
    for (int j = 0; j <= width + 1; j++) {
        copy[height+1][j].rgbtRed = 0;
        copy[height+1][j].rgbtBlue = 0;
        copy[height+1][j].rgbtGreen = 0;
    }
    for (int i = 0; i <= height + 1; i++) {
        copy[i][0].rgbtRed = 0;
        copy[i][0].rgbtBlue = 0;
        copy[i][0].rgbtGreen = 0;
    }
    for (int i = 0; i <= height + 1; i++) {
        copy[i][width+1].rgbtRed = 0;
        copy[i][width+1].rgbtBlue = 0;
        copy[i][width+1].rgbtGreen = 0;
    }
    // Getting image into copy
    for (int i = 1; i < height+1; i ++) {
        for (int j = 1; j < width+1; j ++) {
            copy[i][j] = image[i-1][j-1];
        }
    }

    long gxRed, gxBlue, gxGreen, gyRed, gyBlue, gyGreen;
    long gRed, gBlue, gGreen;
    // Iterating over every pixel in the image
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            gxBlue = gxGreen = gyRed = gyBlue = gyGreen = 0;
            gxRed = 0;
            gGreen = gBlue = gRed = 0;
            // EDGE BOX

            int gradRow = 0;
            for (int row = i-1; row < i+2; row++) {
                int gradCol = 0;
                for (int col = j-1; col < j+2; col++) {
                    gxRed = gxRed + (gradX[gradRow][gradCol] * copy[row][col].rgbtRed);
                    /*if (i==2 && j==2) {
                        printf("gxRed of middle pixel %ld\n", gxRed);
                    }*/
                    gxBlue = gxBlue + (gradX[gradRow][gradCol] * copy[row][col].rgbtBlue);
                    gxGreen = gxGreen + (gradX[gradRow][gradCol] * copy[row][col].rgbtGreen);

                    gyRed = gyRed + (gradY[gradRow][gradCol] * copy[row][col].rgbtRed);
                    gyBlue = gyBlue + (gradY[gradRow][gradCol] * copy[row][col].rgbtBlue);
                    gyGreen = gyGreen + (gradY[gradRow][gradCol] * copy[row][col].rgbtGreen);
                    //printf("GradCol%i\n", gradCol);
                    gradCol++;
                }
                //printf("GradRow %i\n", gradRow);
                gradRow++;
                
            }


            // Storing square root of Gx^2 + Gy^2 in gRed, gBlue, gGreen

            gRed = (long) round( sqrt((gxRed * gxRed) + (gyRed * gyRed)) );
            gBlue = (long) round( sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue)) );
            gGreen = (long) round( sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen)) );

            // Normalizing gradient length to the range 0-255
            if (gRed < 0) {
                gRed = 0;
            } else if (gRed > 255) {
                gRed = 255;
            }
            if (gBlue < 0) {
                gBlue = 0;
            } else if (gBlue > 255) {
                gBlue = 255;
            }
            if (gGreen < 0) {
                gGreen = 0;
            } else if (gGreen > 255) {
                gGreen = 255;
            }
            // Set copy pixel to new values
            image[i-1][j-1].rgbtRed = gRed;
            image[i-1][j-1].rgbtBlue = gBlue;
            image[i-1][j-1].rgbtGreen = gGreen;
        }
    }
    return;
}

