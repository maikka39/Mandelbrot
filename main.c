#include "config.h"
#include "utils.h"
#include "image.h"
#include "color.h"
#include <stdio.h>

unsigned char frame[image_height][image_width][3] = {0};

int main()
{
    bitmap_t image;
    int status;

    status = 0;

    image.height = image_height;
    image.width = image_width;

    image.pixels = calloc(image.width * image.height, sizeof(pixel_t));

    if (!image.pixels)
    {
        return -1;
    }

    for (int px = 0; px < image.width; px++)
    {
        for (int py = 0; py < image.height; py++)
        {
            pixel_t *pixel = pixel_at(&image, px, py);

            long double mx = map(px, 0, image.width, -2.5 * zoom, 1 * zoom) + r;
            long double my = map(py, 0, image.height, -1 * zoom, 1 * zoom) + i;

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

    /* Write the image to a file 'image.png'. */

    if (save_png_to_file(&image, "mandelbrot.png"))
    {
        fprintf(stderr, "Error writing file.\n");
        status = -1;
    }

    free(image.pixels);

    return status;
}
