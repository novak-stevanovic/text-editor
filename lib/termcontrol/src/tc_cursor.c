#include <stdio.h>
#include <string.h>
#include "tc_cursor.h"

void tc_rel_move_cursor(int row_diff, int col_diff)
{
    tc_rel_move_cursor_y(row_diff);
    tc_rel_move_cursor_x(col_diff);
}

void tc_rel_move_cursor_y(int row_diff)
{
    if(row_diff == 0) return;

    size_t code_len = 15;
    char code[code_len];

    if(row_diff > 0)
        snprintf(code, code_len, _MOVE_CURSOR_DOWN_CODE, row_diff);
    else
        snprintf(code, code_len, _MOVE_CURSOR_UP_CODE, -row_diff);

    fprintf(stdout, "%s", code);
}

void tc_rel_move_cursor_x(int col_diff)
{
    if(col_diff == 0) return;

    size_t code_len = 15;
    char code[code_len];

    if(col_diff > 0)
        snprintf(code, code_len, _MOVE_CURSOR_RIGHT_CODE, col_diff);
    else
        snprintf(code, code_len, _MOVE_CURSOR_LEFT_CODE, -col_diff);

    fprintf(stdout, "%s", code);
}

void tc_abs_reset_cursor()
{
    fprintf(stdout, _MOVE_CURSOR_HOME_CODE);
}

void tc_abs_move_cursor_x(int col)
{
    if(col == 0) return;

    size_t code_len = 15;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_COLUMN_CODE, col);

    fprintf(stdout, "%s", code);
}

void tc_abs_move_cursor_y(int row_diff)
{
    // TO DO
}

void tc_abs_move_cursor(size_t row, size_t col)
{
    if((row == 0) && (col == 0)) return;

    size_t code_len = 15;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_LINE_COL_CODE, row, col);

    fprintf(stdout, "%s", code);
}
