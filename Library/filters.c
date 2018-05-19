#include "filters.h"

Image scaleInGray(Image img) {
    LOG_INFO("SCALE IN GRAY EFFECT STARTED");
    for (unsigned int row = 0; row < img.height; ++row) {
        for (unsigned int column = 0; column < img.width; ++column) {
            int average = img.pixel[row][column][RED] +
                        img.pixel[row][column][GREEN] +
                        img.pixel[row][column][BLUE];
            average /= 3;
            img.pixel[row][column][RED] = average;
            img.pixel[row][column][GREEN] = average;
            img.pixel[row][column][BLUE] = average;
        }
    }

    return img;
}


Image sepia(Image img) {
    LOG_INFO("SEPIA EFFECT STARTED");
    for (unsigned int row = 0; row < img.height; ++row) {
        for (unsigned int column = 0; column < img.width; ++column) {
            
            Pixel pix;
            pix.red = img.pixel[row][column][RED];
            pix.green = img.pixel[row][column][GREEN];
            pix.blue = img.pixel[row][column][BLUE];

            int newImage = pix.red * .393 + pix.green * .769 + pix.blue * .189;
            
            img.pixel[row][column][RED] = fmin(newImage,255);

            newImage =  pix.red * .349 + pix.green * .686 + pix.blue * .168;
            img.pixel[row][column][GREEN] = fmin(newImage,255);

            newImage =  pix.red * .272 + pix.green * .534 + pix.blue * .131;
            img.pixel[row][column][BLUE] = fmin(newImage,255);

        }
    }
    return img;
}

Image blur(Image img) {
        LOG_INFO("BLUR EFFECT STARTED");
        int magnitude = 0;
        scanf("%d", &magnitude);

        for(int row = 0; row < img.height; row++) {
                for (int column = 0; column < img.width; column++) {
                        Pixel media = {0, 0, 0};
                        for(int pixelRow = fmax(0, row - magnitude/2); pixelRow <= fmin(img.height - 1, row + magnitude/2); ++pixelRow) {
                                for(int pixelColumn = fmax(0, column - magnitude/2); pixelColumn <= fmin(img.width - 1, column + magnitude/2); ++pixelColumn) {
                                        media.red += img.pixel[pixelRow][pixelColumn][RED];
                                        media.green += img.pixel[pixelRow][pixelColumn][GREEN];
                                        media.blue += img.pixel[pixelRow][pixelColumn][BLUE];
                                }
                        }
                        media.red /= magnitude * magnitude;
                        media.green /= magnitude * magnitude;
                        media.blue /= magnitude * magnitude;

                        img.pixel[row][column][RED] = media.red;
                        img.pixel[row][column][GREEN] = media.green;
                        img.pixel[row][column][BLUE] = media.blue;
                }
        }

        return img;
}


Image rotate90Right(Image img) {
    LOG_INFO("ROTATE EFFECT STARTED");
    Image rotated;

    rotated.width = img.height;
    rotated.height = img.width;

    for (int column = 0, j = 0; column < rotated.height; ++column, ++j) {
        for (int row = rotated.width - 1, i = 0; row >= 0; --row, ++i) {
            rotated.pixel[column][row][RED] = img.pixel[i][j][RED];
            rotated.pixel[column][row][GREEN] = img.pixel[i][j][GREEN];
            rotated.pixel[column][row][BLUE] = img.pixel[i][j][BLUE];
        }
    }

    return rotated;
}

Image rotate(Image img) {
    int quantity = 0;
    scanf("%d", &quantity);
    quantity %= 4;
    for (int j = 0; j < quantity; ++j) {
        img = rotate90Right(img);
    }
    return img;
}

Image mirroringImage(Image img) {
    LOG_INFO("MIRROR EFFECT STARTED");
    int horizontal = 0;
    scanf("%d", &horizontal);

    int width, height;
    width = img.width;
    height = img.height;
    
    if (horizontal == 1) 
        width /= 2;
    else 
        height /= 2;

    for (unsigned int row = 0; row < height; ++row) {
        for (unsigned int column = 0; column < width; ++column) {
            int pixelColumn = column, pixelRow = row;

                        if(horizontal == 1) {
                                pixelColumn = img.width - 1 - column;
                        } else {
                                pixelRow = img.height - 1 - column;
                        }

                        Pixel auxPix;
                        auxPix.red = img.pixel[row][column][RED];
                        auxPix.green = img.pixel[row][column][GREEN];
                        auxPix.blue = img.pixel[row][column][BLUE];

                        img.pixel[row][column][RED] = img.pixel[pixelRow][pixelColumn][RED];
                        img.pixel[row][column][GREEN] = img.pixel[pixelRow][pixelColumn][GREEN];
                        img.pixel[row][column][BLUE] = img.pixel[pixelRow][pixelColumn][BLUE];

                        img.pixel[row][pixelColumn][RED] = auxPix.red;
                        img.pixel[row][pixelColumn][GREEN] = auxPix.green;
                        img.pixel[row][pixelColumn][BLUE] = auxPix.blue;
        }
    }
    return img;
}

Image invertColors(Image img) {
    LOG_INFO("INVERT COLORS EFFECT STARTED");
    for (unsigned int row = 0; row < img.height; ++row) {
        for (unsigned int column = 0; column < img.width; ++column) {
            img.pixel[row][column][RED] = 255 - img.pixel[row][column][RED];
            img.pixel[row][column][GREEN] = 255 - img.pixel[row][column][GREEN];
            img.pixel[row][column][BLUE] = 255 - img.pixel[row][column][BLUE];
        }
    }
    return img;
}

Image cutImage(Image img) {
    LOG_INFO("CUT IMAGE EFFECT STARTED");
    int pix_width, pix_height;
    int width, height;

    scanf("%d %d", &pix_width, &pix_height);
    scanf("%d %d", &width, &height);

    Image cutted;

    cutted.width = width;
    cutted.height = height;

    for(int row = 0; row < height; ++row) {
        for(int column = 0; column < width; ++column) {
            cutted.pixel[row][column][RED] = img.pixel[row + pix_height][column + pix_width][RED];
            cutted.pixel[row][column][GREEN] = img.pixel[row + pix_height][column + pix_width][GREEN];
            cutted.pixel[row][column][BLUE] = img.pixel[row + pix_height][column + pix_width][BLUE];
        }
    }

    return cutted;
}

/* red image's Type */
char readImageType(char *pixels) {
    scanf("%s", pixels);
    return *pixels;
}