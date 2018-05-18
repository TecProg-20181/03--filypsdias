#include "filters.h"

Image scaleInGray(Image img) {
    for (unsigned int row = 0; row < img.height; ++row) {
        for (unsigned int column = 0; column < img.width; ++column) {
            int average = img.pixel[row][column][0] +
                        img.pixel[row][column][1] +
                        img.pixel[row][column][2];
            average /= 3;
            img.pixel[row][column][0] = average;
            img.pixel[row][column][1] = average;
            img.pixel[row][column][2] = average;
        }
    }

    return img;
}


Image sepia(Image img) {
    for (unsigned int row = 0; row < img.height; ++row) {
        for (unsigned int column = 0; column < img.width; ++column) {
            
            Pixel pix;
            pix.red = img.pixel[row][column][0];
            pix.green = img.pixel[row][column][1];
            pix.blue = img.pixel[row][column][2];

            int newImage = pix.red * .393 + pix.green * .769 + pix.blue * .189;
            
            img.pixel[row][column][0] = fmin(newImage,255);

            newImage =  pix.red * .349 + pix.green * .686 + pix.blue * .168;
            img.pixel[row][column][1] = fmin(newImage,255);

            newImage =  pix.red * .272 + pix.green * .534 + pix.blue * .131;
            img.pixel[row][column][2] = fmin(newImage,255);

        }
    }
    return img;
}

Image blur(Image img) {

        int magnitude = 0;
        scanf("%d", &magnitude);

        for(int row = 0; row < img.height; row++) {
                for (int column = 0; column < img.width; column++) {
                        Pixel media = {0, 0, 0};
                        for(int pixelRow = fmax(0, row - magnitude/2); pixelRow <= fmin(img.height - 1, row + magnitude/2); ++pixelRow) {
                                for(int pixelColumn = fmax(0, column - magnitude/2); pixelColumn <= fmin(img.width - 1, column + magnitude/2); ++pixelColumn) {
                                        media.red += img.pixel[pixelRow][pixelColumn][0];
                                        media.green += img.pixel[pixelRow][pixelColumn][1];
                                        media.blue += img.pixel[pixelRow][pixelColumn][2];
                                }
                        }
                        media.red /= magnitude * magnitude;
                        media.green /= magnitude * magnitude;
                        media.blue /= magnitude * magnitude;

                        img.pixel[row][column][0] = media.red;
                        img.pixel[row][column][1] = media.green;
                        img.pixel[row][column][2] = media.blue;
                }
        }

        return img;
}


Image rotate90Right(Image img) {
    Image rotated;

    rotated.width = img.height;
    rotated.height = img.width;

    for (int column = 0, j = 0; column < rotated.height; ++column, ++j) {
        for (int row = rotated.width - 1, i = 0; row >= 0; --row, ++i) {
            rotated.pixel[column][row][0] = img.pixel[i][j][0];
            rotated.pixel[column][row][1] = img.pixel[i][j][1];
            rotated.pixel[column][row][2] = img.pixel[i][j][2];
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
                        auxPix.red = img.pixel[row][column][0];
                        auxPix.green = img.pixel[row][column][1];
                        auxPix.blue = img.pixel[row][column][2];

                        img.pixel[row][column][0] = img.pixel[pixelRow][pixelColumn][0];
                        img.pixel[row][column][1] = img.pixel[pixelRow][pixelColumn][1];
                        img.pixel[row][column][2] = img.pixel[pixelRow][pixelColumn][2];

                        img.pixel[row][pixelColumn][0] = auxPix.red;
                        img.pixel[row][pixelColumn][1] = auxPix.green;
                        img.pixel[row][pixelColumn][2] = auxPix.blue;
        }
    }
    return img;
}

Image invertColors(Image img) {
    for (unsigned int row = 0; row < img.height; ++row) {
        for (unsigned int column = 0; column < img.width; ++column) {
            img.pixel[row][column][0] = 255 - img.pixel[row][column][0];
            img.pixel[row][column][1] = 255 - img.pixel[row][column][1];
            img.pixel[row][column][2] = 255 - img.pixel[row][column][2];
        }
    }
    return img;
}

Image cutImage(Image img) {
    int pix_width, pix_height;
    int width, height;

    scanf("%d %d", &pix_width, &pix_height);
    scanf("%d %d", &width, &height);

    Image cutted;

    cutted.width = width;
    cutted.height = height;

    for(int row = 0; row < height; ++row) {
        for(int column = 0; column < width; ++column) {
            cutted.pixel[row][column][0] = img.pixel[row + pix_height][column + pix_width][0];
            cutted.pixel[row][column][1] = img.pixel[row + pix_height][column + pix_width][1];
            cutted.pixel[row][column][2] = img.pixel[row + pix_height][column + pix_width][2];
        }
    }

    return cutted;
}

/* red image's Type */
char readImageType(char *pixels) {
    scanf("%s", pixels);
    return *pixels;
}