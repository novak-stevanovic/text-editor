#ifndef _CURSOR_CONTROL
#define _CURSOR_CONTROL

#include <stddef.h>

// Cursor Controls
#define _MOVE_CURSOR_HOME "\e[H"
#define _MOVE_CURSOR_LINE_COL(x, y) "\e[" #x ";" #y "H"
#define _MOVE_CURSOR_UP(x) "\e[" #x "A"
#define _MOVE_CURSOR_DOWN(x) "\e[" #x "B"
#define _MOVE_CURSOR_RIGHT(x) "\e[" #x "C"
#define _MOVE_CURSOR_LEFT(x) "\e[" #x "D"
#define _MOVE_CURSOR_COLUMN(x) "\e[" #x "G"
#define _GET_CURSOR_POSITION "\e[6n"

void rel_move_cursor(int row_diff, int col_diff);
void rel_move_cursor_y(int row_diff);
void rel_move_cursor_x(int col_diff);

void abs_reset_cursor();
void abs_move_cursor_x(int col_diff);
void abs_move_cursor_y(int row_diff);
void abs_move_cursor(size_t row, size_t col);

#endif


