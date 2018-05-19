#ifndef FILTERS_H_
#define FILTERS_H_
#include <stdio.h>
#include "pixel.h"
#include "macrologger.h"

Image scaleInGray(Image image);
Image sepia(Image image);
Image blur(Image image);
Image rotate90Right(Image image);
Image rotate(Image image);
Image mirroringImage(Image image);
Image invertColors(Image image);
Image cutImage(Image image);

#endif