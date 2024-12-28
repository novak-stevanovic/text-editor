#include <stddef.h>

size_t misc_min(size_t x, size_t y)
{
    return (x < y ? x : y);
}

int misc_flatten(int min, int val, int max)
{
    if(val < min)
        return min;
    else if(val > max)
        return max;
    else
        return val;
}
