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

void tc_rel_move_cursor(int row_diff, int col_diff);
void tc_rel_move_cursor_y(int row_diff);
void tc_rel_move_cursor_x(int col_diff);

void tc_abs_reset_cursor();
void tc_abs_move_cursor_x(int col_diff);
void tc_abs_move_cursor_y(int row_diff);
void tc_bs_move_cursor(size_t row, size_t col);

#endif


