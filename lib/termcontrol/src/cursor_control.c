#include <stdio.h>
#include <string.h>
#include "tc_cursor_control.h"

size_t _itostr(int x, char* buffer);

void rel_move_cursor(int row_diff, int col_diff);

void rel_move_cursor_y(int row_diff)
{
    if(row_diff == 0) return;

    // TO DO
}

void rel_move_cursor_x(int col_diff)
{
    if(col_diff == 0) return;

    // TO DO
}

void abs_reset_cursor();
void abs_move_cursor_x(int col_diff);
void abs_move_cursor_y(int row_diff);
void abs_move_cursor(size_t row, size_t col);

// ----------------------------------------------------------------

size_t _itostr(int x, char* buffer)
{
    if(x == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';

        return 1;
    }

    size_t counter = 0;

    if(x < 0) // "adapt" function if x is negative
    {
        buffer[0] = '-';
        ++counter;
        x *= -1;
    }

    int x_cpy = x;
    for(; x_cpy > 0; x_cpy /= 10) ++counter;

    size_t counter_cpy = counter;

    buffer[counter] = '\0';
    counter_cpy--;

    int curr_digit;
    for(; x > 0; x /= 10)
    {
        curr_digit = x % 10;

        buffer[counter_cpy] = curr_digit + '0';
        --counter_cpy;
    }

    return counter;
}
