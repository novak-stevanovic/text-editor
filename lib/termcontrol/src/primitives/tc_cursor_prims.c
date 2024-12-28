#include "primitives/tc_cursor_prims.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void prim_move_cursor_home()
{
    write(STDOUT_FILENO, _MOVE_CURSOR_HOME_CODE, strlen(_MOVE_CURSOR_HOME_CODE));
}

void prim_move_cursor_to_line_col(size_t line, size_t col)
{
    size_t code_len = 15;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_LINE_COL_CODE, line, col);
    write(STDOUT_FILENO, code, strlen(code));
}

void prim_move_cursor_up(size_t row_diff)
{
    size_t code_len = 15;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_UP_CODE, (int)row_diff);
    write(STDOUT_FILENO, code, strlen(code));
}

void prim_move_cursor_down(size_t row_diff)
{
    size_t code_len = 15;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_DOWN_CODE, (int)row_diff);
    write(STDOUT_FILENO, code, strlen(code));
}

void prim_move_cursor_right(size_t col_diff)
{
    size_t code_len = 15;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_RIGHT_CODE, (int)col_diff);
    write(STDOUT_FILENO, code, strlen(code));
}

void prim_move_cursor_left(size_t col_diff)
{
    size_t code_len = 15;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_LEFT_CODE, (int)col_diff);
    write(STDOUT_FILENO, code, strlen(code));
}

void prim_move_cursor_to_col(size_t col)
{
    size_t code_len = 15;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_TO_COLUMN_CODE, (int)col);
    write(STDOUT_FILENO, code, strlen(code));
}
