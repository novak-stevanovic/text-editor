#ifndef _ANSI_OP
#define _ANSI_OP

#include <stddef.h>

void rel_move_cursor(int row_diff, int col_diff);
void rel_move_cursor_y(int row_diff);
void rel_move_cursor_x(int col_diff);

void abs_reset_cursor();
void abs_move_cursor_x(int col_diff);
void abs_move_cursor_y(int row_diff);
void abs_move_cursor(size_t row, size_t col);

#endif


