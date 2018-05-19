
#ifndef STRUCUTURES_H_
#define STRUCUTURES_H_

#include <string.h>
#include <math.h>
#include <assert.h>
#define RED 0
#define GREEN 1
#define BLUE 2

typedef struct _pixel {
        unsigned short int red;
        unsigned short int green;
        unsigned short int blue;
} Pixel;

typedef struct _image {
    /* [width][height][rgb]
     0 -> r 
     1 -> g 
     2 -> b */
    unsigned short int pixel[512][512][3];
    unsigned int width;
    unsigned int height;
} Image;

#endif