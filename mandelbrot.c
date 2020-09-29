#include "mandelbrot.h"
#include "color.h"
#include "utils.h"

void mandelbrot(bitmap_t *image, long double zoom, long double r, long double i, int bailout, int max_iterations)
{
    for (int px = 0; px < image->width; px++)
    {
        for (int py = 0; py < image->height; py++)
        {
            pixel_t *pixel = pixel_at(image, px, py);

            long double mx = map(px, 0, image->width, -2.5 * zoom, 1 * zoom) + r;
            long double my = map(py, 0, image->height, -1 * zoom, 1 * zoom) + i;

            long double x = 0;
            long double y = 0;
            long double x2 = 0;
            long double y2 = 0;

            int iterations;
            for (iterations = 0; x2 + y2 <= bailout && iterations < max_iterations; iterations++)
            {
                y = 2 * x * y + my;
                x = x2 - y2 + mx;

                x2 = x * x;
                y2 = y * y;
            }

            color_pixel(pixel, iterations);
        }
    }
}