#include "config.h"
#include "image.h"
#include "mandelbrot.h"
#include <stdio.h>
#include <string.h>

int main()
{
    int status = 0;

    bitmap_t image;
    FILE *pipeout;

    if (video_frames)
    {
        char *ffmpeg_string = (char *)malloc(150 * sizeof(char));
        sprintf(ffmpeg_string, "ffmpeg -y -f rawvideo -vcodec rawvideo -pix_fmt rgb24 -s %dx%d -r %d -i - -f mp4 -q:v 5 -an -vcodec mpeg4 mandelbrot.mp4", image_width, image_height, frame_rate);
        printf("CMD: %s\n", ffmpeg_string);
        pipeout = popen(ffmpeg_string, "w");
    }

    image.height = image_height;
    image.width = image_width;

    long double video_zoom = zoom;

    for (int frame_n = 0; frame_n < video_frames + save_image; frame_n++)
    {
        image.pixels = calloc(image.width * image.height, sizeof(pixel_t));

        if (!image.pixels)
        {
            return -1;
        }

        mandelbrot(&image, video_zoom, r, i, bailout, max_iterations);

        if (save_image && save_png_to_file(&image, "mandelbrot.png"))
        {
            fprintf(stderr, "Error writing file.\n");
            status = -1;
        }

        if (video_frames)
        {
            unsigned char frame[image_height][image_width][3];
            memset(&frame, 0, sizeof(frame));

            for (int x = 0; x < image.width; x++)
            {
                for (int y = 0; y < image.height; y++)
                {
                    pixel_t *pixel = pixel_at(&image, x, y);

                    frame[y][x][0] = pixel->red;
                    frame[y][x][1] = pixel->green;
                    frame[y][x][2] = pixel->blue;
                }
            }

            fwrite(frame, 1, image_height * image_width * 3, pipeout);
        }

        free(image.pixels);

        video_zoom *= zoom_multiplier;
    }

    if (video_frames)
    {
        fflush(pipeout);
        pclose(pipeout);
    }

    printf("Done!");

    return status;
}
