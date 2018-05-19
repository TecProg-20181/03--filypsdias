#include <stdio.h>
#include "Library/filters.h"

int main() {
        
        Image img;

        img = readImage(img);

        // Read a number filter.
        int option_numbers;
        scanf("%d", &option_numbers);
        assert(&option_numbers != NULL);

        if(option_numbers <= 0){
                assert(option_numbers != 0);
        }
                for(unsigned int iterator = 1; iterator <= option_numbers; iterator++) {
                        // Read one number to choose a image filter.
                        int option;
                        scanf("%d", &option);
                        assert(&option != NULL);

                        switch(option) {
                                // Scale in Gray
                                case 1: {
                                        img = scaleInGray(img);
                                        break;
                                }
                                // Sepia 
                                case 2: {
                                        img = sepia(img);
                                        break;
                                }
                                // Blur 
                                case 3: {
                                        img = blur(img);
                                        break;
                                }
                                // Rotate 
                                case 4: {
                                        img = rotate(img);
                                        break;
                                }
                                // Mirroring effect 
                                case 5: {
                                        img = mirroringImage(img);
                                        break;
                                }
                                // Invert Colors
                                case 6: {
                                        img = invertColors(img);
                                        break;
                                }
                                // Cut image
                                case 7: {
                                        img = cutImage(img);
                                        break;
                                }
                        }

                }

                printImage(img);
        return 0;
}