#ifndef _MISC_H
#define _MISC_H

#include <stddef.h>

struct Point2D
{
    int x;
    int y;
};

size_t misc_min(size_t x, size_t y);
size_t misc_flatten(int min, int suggested, int max);

#endif
