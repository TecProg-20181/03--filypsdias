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
                LOG_ERROR("INVALID OPTION! SHOULD BE GREATER THAN 0!");
                assert(option_numbers != 0);
        }
                for(unsigned int iterator = 1; iterator <= option_numbers; iterator++) {
                        // Read one number to choose a image filter.
                        int option;
                        scanf("%d", &option);
                        assert(&option != NULL);
                        LOG_INFO("OPTION %d STARTED", option);

                        switch(option) {
                                // Scale in Gray
                                case 1: {
                                        LOG_INFO("Scale in gray started...");
                                        img = scaleInGray(img);
                                        break;
                                }
                                // Sepia 
                                case 2: {
                                        LOG_INFO("Sepia filter started...");
                                        img = sepia(img);
                                        break;
                                }
                                // Blur 
                                case 3: {
                                        LOG_INFO("Bluring...");
                                        img = blur(img);
                                        break;
                                }
                                // Rotate 
                                case 4: {
                                        LOG_INFO("Rotating...");
                                        img = rotate(img);
                                        break;
                                }
                                // Mirroring effect 
                                case 5: {
                                        LOG_INFO("Mirroring...");
                                        img = mirroringImage(img);
                                        break;
                                }
                                // Invert Colors
                                case 6: {
                                        LOG_INFO("Inverting colors...");
                                        img = invertColors(img);
                                        break;
                                }
                                // Cut image
                                case 7: {
                                        LOG_INFO("Cutting image...");
                                        img = cutImage(img);
                                        break;
                                }

                                default: {
                                        LOG_ERROR("INVALID OPTION. PLEASE TRY AGAIN");
                                }
                        }

                }

                printImage(img);
        return 0;
}