#include "color.h"
#include "utils.h"
#include "config.h"

void greeny(pixel_t *pixel, int iterations)
{
    int value = map(iterations, 0, max_iterations, 0, 255);

    pixel->red = value * 0.93;
    pixel->green = value;
    pixel->blue = value * 0.3;
}

void spectral(pixel_t *pixel, int iterations)
{
    double value = map(iterations, 0, max_iterations, 400, 700);

    double t;
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;
    if ((value >= 400.0) && (value < 410.0))
    {
        t = (value - 400.0) / (410.0 - 400.0);
        r = +(0.33 * t) - (0.20 * t * t);
    }
    else if ((value >= 410.0) && (value < 475.0))
    {
        t = (value - 410.0) / (475.0 - 410.0);
        r = 0.14 - (0.13 * t * t);
    }
    else if ((value >= 545.0) && (value < 595.0))
    {
        t = (value - 545.0) / (595.0 - 545.0);
        r = +(1.98 * t) - (t * t);
    }
    else if ((value >= 595.0) && (value < 650.0))
    {
        t = (value - 595.0) / (650.0 - 595.0);
        r = 0.98 + (0.06 * t) - (0.40 * t * t);
    }
    else if ((value >= 650.0) && (value < 700.0))
    {
        t = (value - 650.0) / (700.0 - 650.0);
        r = 0.65 - (0.84 * t) + (0.20 * t * t);
    }
    if ((value >= 415.0) && (value < 475.0))
    {
        t = (value - 415.0) / (475.0 - 415.0);
        g = +(0.80 * t * t);
    }
    else if ((value >= 475.0) && (value < 590.0))
    {
        t = (value - 475.0) / (590.0 - 475.0);
        g = 0.8 + (0.76 * t) - (0.80 * t * t);
    }
    else if ((value >= 585.0) && (value < 639.0))
    {
        t = (value - 585.0) / (639.0 - 585.0);
        g = 0.84 - (0.84 * t);
    }
    if ((value >= 400.0) && (value < 475.0))
    {
        t = (value - 400.0) / (475.0 - 400.0);
        b = +(2.20 * t) - (1.50 * t * t);
    }
    else if ((value >= 475.0) && (value < 560.0))
    {
        t = (value - 475.0) / (560.0 - 475.0);
        b = 0.7 - (t) + (0.30 * t * t);
    }

    pixel->red = r * 255;
    pixel->green = g * 255;
    pixel->blue = b * 255;
}

void color_pixel(pixel_t *pixel, int iterations)
{
    if (iterations >= max_iterations)
        iterations = 0;

    switch (color_theme)
    {
    case 0:
        greeny(pixel, iterations);
        break;
    case 1:
        spectral(pixel, iterations);
        break;

    default:
        break;
    }
}
