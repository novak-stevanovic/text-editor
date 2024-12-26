#include <stdio.h>
#include <string.h>
#include "tc_cursor_control.h"

void rel_move_cursor(int row_diff, int col_diff)
{
    rel_move_cursor_y(row_diff);
    rel_move_cursor_x(col_diff);
}

void rel_move_cursor_y(int row_diff)
{
    if(row_diff == 0) return;

    size_t code_len = 10;
    char code[code_len];
    if(row_diff > 0)
        snprintf(code, code_len, _MOVE_CURSOR_DOWN_CODE, row_diff);
    else
        snprintf(code, code_len, _MOVE_CURSOR_UP_CODE, -row_diff);

    fprintf(stdout, "%s", code);
}

void rel_move_cursor_x(int col_diff)
{
    if(col_diff == 0) return;

    size_t code_len = 10;
    char code[code_len];

    if(col_diff > 0)
        snprintf(code, code_len, _MOVE_CURSOR_RIGHT_CODE, col_diff);
    else
        snprintf(code, code_len, _MOVE_CURSOR_LEFT_CODE, -col_diff);

    fprintf(stdout, "%s", code);
}

void abs_reset_cursor()
{
    fprintf(stdout, _MOVE_CURSOR_HOME_CODE);
}

void abs_move_cursor_x(int col)
{
    if(col == 0) return;

    size_t code_len = 10;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_COLUMN_CODE, col);

    fprintf(stdout, "%s", code);
}

void abs_move_cursor_y(int row_diff)
{
    // TO DO
}

void abs_move_cursor(size_t row, size_t col)
{
    if((row == 0) && (col == 0)) return;

    size_t code_len = 10;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_LINE_COL_CODE, row, col);

    fprintf(stdout, "%s", code);
}
