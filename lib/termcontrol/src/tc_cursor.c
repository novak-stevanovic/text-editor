#include <stdio.h>
#include <string.h>
#include "tc_cursor.h"
#include "tc_display.h"

size_t _min(size_t x, size_t y);
size_t _flatten(int min, int suggested, int max);

// ------------------------------------------------------------------------------------

struct Cursor
{
    size_t x;
    size_t y;
};

struct Cursor cursor;

void _tc_cursor_init()
{
    tc_abs_reset_cursor();    
}

size_t tc_get_cursor_x()
{
    return cursor.x;
}

size_t tc_get_cursor_y()
{
    return cursor.y;
}

void tc_set_cursor_pos(int x, int y)
{
    size_t display_width = tc_get_display_width();
    size_t display_height = tc_get_display_height();

    cursor.x = _flatten(0, x, display_width - 1);
    cursor.y = _flatten(0, y, display_height - 1);
}

void tc_update_cursor_pos()
{
    size_t display_width = tc_get_display_width();
    size_t display_height = tc_get_display_height();

    cursor.x = _flatten(0, cursor.x, display_width - 1);
    cursor.y = _flatten(0, cursor.y, display_height - 1);
}

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

    tc_set_cursor_pos(cursor.x, cursor.y + row_diff);
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

    tc_set_cursor_pos(cursor.x + col_diff, cursor.y);
}

void tc_abs_reset_cursor()
{
    fprintf(stdout, _MOVE_CURSOR_HOME_CODE);
    tc_set_cursor_pos(0, 0);
}

void tc_abs_move_cursor_x(size_t col)
{
    if(col == 0) return;

    size_t code_len = 15;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_COLUMN_CODE, (int)col);

    fprintf(stdout, "%s", code);
    tc_set_cursor_pos(col, cursor.y);
}

void tc_abs_move_cursor_y(size_t row)
{
    tc_abs_move_cursor(row, cursor.x);
}

void tc_abs_move_cursor(size_t row, size_t col)
{
    if((row == 0) && (col == 0)) return;

    size_t code_len = 15;
    char code[code_len];

    snprintf(code, code_len, _MOVE_CURSOR_LINE_COL_CODE, row, col);

    fprintf(stdout, "%s", code);
    tc_set_cursor_pos(col, row);
}

size_t _min(size_t x, size_t y)
{
    return (x < y ? x : y);
}

size_t _flatten(int min, int val, int max)
{
    if(val < min)
        return min;
    else if(val > max)
        return max;
    else
        return val;
}
