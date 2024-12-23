#include "ansi_op.h"
#include <stdio.h>
#include <string.h>

void _form_ansi_code_basic(char* ansi_code, int parameter, char suffix);

/* Converts given integer <x> to string. Converted value is placed in provided <buffer>. 
 * Return value: length of new string */
size_t _itostr(int x, char* buffer);

void rel_move_cursor(int row_diff, int col_diff);

void rel_move_cursor_y(int row_diff)
{
    if(row_diff == 0) return;

    char ansi_code[15] = "\e[";

    char suffix = (row_diff > 0 ? 'A' : 'B');
    
    _form_ansi_code_basic(ansi_code, row_diff, suffix);

    printf("%s", ansi_code);

}

void rel_move_cursor_x(int col_diff);

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

void _form_ansi_code_basic(char* ansi_code, int parameter, char suffix)
{
    char itostr_buf[10];
    size_t itostr_buf_len = _itostr(parameter, itostr_buf);

    strncat(ansi_code, itostr_buf, itostr_buf_len);

    size_t ansi_code_len = strlen(ansi_code);

    ansi_code[ansi_code_len] = suffix;
    ansi_code[ansi_code_len + 1] = '\0';
}
