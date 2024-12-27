#ifndef _TC_ERASE_H
#define _TC_ERASE_H

// #define _ERASE_SCREEN_CODE "\e[J"
#define _ERASE_CURSOR_TO_END_SCREEN_CODE "\e[0J"
#define _ERASE_BEGINNING_TO_CURSOR_SCREEN_CODE "\e[1J"
#define _ERASE_ENTIRE_SCREEN_CODE "\e[2J"
#define _ERASE_CURSOR_TO_END_LINE_CODE "\e[0K"
#define _ERASE_START_TO_CURSOR_LINE_CODE "\e[1K"
#define _ERASE_ENTIRE_LINE_CODE "\e[2K"

void tc_erase();

void tc_erase_screen();

void tc_erase_line();
void tc_erase_line_start_to_cursor();
void tc_erase_line_cursor_to_end();

#endif
