#include "ansi_op.h"

/** Converts given integer <x> to string. Converted value is placed in provided <buffer>.
 * Return value: length of used buffer <buffer>. */
size_t _itostr(int x, char* buffer);

void rel_move_cursor(int row_diff, int col_diff);

void rel_move_cursor_y(int row_diff)
{
    char ansi_code[10] = "ESC[";
}

void rel_move_cursor_x(int col_diff);

void abs_reset_cursor();
void abs_move_cursor_x(int col_diff);
void abs_move_cursor_y(int row_diff);
void abs_move_cursor(size_t row, size_t col);

size_t _itostr(int x, char* buffer)
{
    size_t counter = 0;
    int curr_digit;
    int x_cpy = x;

    if(x < 0) // "adapt" x if x is negative
    {
        buffer[0] = '-';
        ++counter;
        x *= -1;
    }

    for(; x_cpy > 0; x_cpy /= 10) ++counter;

    size_t counter_cpy = counter;
    for(; x > 0; x /= 10)
    {
        curr_digit = x % 10;

        buffer[counter_cpy] = curr_digit + '0';
        --counter_cpy;
    }

    return counter;

}
