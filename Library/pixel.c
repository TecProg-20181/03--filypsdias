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
                                printf("%hu %hu %hu ", img.pixel[line][column][RED],
                                       img.pixel[line][column][GREEN],
                                       img.pixel[line][column][BLUE]);

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
                                        scanf("%hu %hu %hu", &img.pixel[row][column][RED],
                                              &img.pixel[row][column][GREEN],
                                              &img.pixel[row][column][BLUE]);
                                }
                        }
                }
                else {
                        printf("This isn't a PPM file. Please try again");
                        assert(image_type[0] == 'P');
                } 
    return img;
}