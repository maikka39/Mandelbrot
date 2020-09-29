#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include "image.h"

void mandelbrot(bitmap_t *image, long double zoom, long double r, long double i, int bailout, int max_iterations);

#endif