#include <stdio.h>
#include "pixel.h"
#include "filters.h"

// Print image.
void printImage(Image img) {

                // Print image's type.
                printf("P3\n");

                // Print width, height/color of image.

                printf("%u %u\n255\n", img.width, img.height);
                // Print image's pixels.

                for(unsigned int line = 0; line < img.height; ++line) {
                        for (unsigned int column = 0; column < img.width; ++column) {
                                printf("%hu %hu %hu ", img.pixel[line][column][0],
                                       img.pixel[line][column][1],
                                       img.pixel[line][column][2]);

                        }
                        printf("\n");
                }
}

// Read image
Image readImage(Image img) {

                // Read image's type.
                char image_type[4];
                scanf("%s", image_type);
                if(image_type[0] == 'P') {
                        
                        // Read width and height/color of image.

                        int max_color;
                        scanf("%u %u %d", &img.width, &img.height, &max_color);
                        
                        // Read all pixels of image
                        for(unsigned int row = 0; row < img.height; ++row) {
                                for(unsigned int column = 0; column < img.width; ++column) {
                                        scanf("%hu %hu %hu", &img.pixel[row][column][0],
                                              &img.pixel[row][column][1],
                                              &img.pixel[row][column][2]);
                                }
                        }
                } 
    return img;
}