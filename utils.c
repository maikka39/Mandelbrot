#include "utils.h"

long double map(long double n, long double start1, long double stop1, long double start2, long double stop2)
{
    long double out = (n - start1) / (stop1 - start1) * (stop2 - start2) + start2;

    if (out > stop2)
        out = stop2;

    return out;
}
