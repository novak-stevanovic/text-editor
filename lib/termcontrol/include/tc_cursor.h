#ifndef _CURSOR_CONTROL
#define _CURSOR_CONTROL

#include <stddef.h>

// Cursor Controls
#define _MOVE_CURSOR_HOME_CODE "\e[H"
#define _MOVE_CURSOR_LINE_COL_CODE "\e[%ld;%ldH"
#define _MOVE_CURSOR_UP_CODE "\e[%dA"
#define _MOVE_CURSOR_DOWN_CODE "\e[%dB"
#define _MOVE_CURSOR_RIGHT_CODE "\e[%dC"
#define _MOVE_CURSOR_LEFT_CODE "\e[%dD"
#define _MOVE_CURSOR_COLUMN_CODE "\e[%dG"
#define _GET_CURSOR_POSITION_CODE "\e[6n"

struct Cursor;
extern struct Cursor cursor;

void _tc_cursor_init();

size_t tc_get_cursor_x();
size_t tc_get_cursor_y();
void tc_update_cursor_pos();
void tc_set_cursor_pos(int x, int y);

void tc_rel_move_cursor(int row_diff, int col_diff);
void tc_rel_move_cursor_y(int row_diff);
void tc_rel_move_cursor_x(int col_diff);

void tc_abs_reset_cursor();
void tc_abs_move_cursor_x(size_t col);
void tc_abs_move_cursor_y(size_t row);
void tc_abs_move_cursor(size_t row, size_t col);

#endif


