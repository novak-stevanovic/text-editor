#include "tc_erase.h"
#include <stdio.h>

void tc_erase()
{
    printf("%c", ' ');
}

void tc_erase_screen()
{
    printf("%s", _ERASE_ENTIRE_SCREEN_CODE);
}

void tc_erase_line()
{
    printf("%s", _ERASE_ENTIRE_LINE_CODE);
}

void tc_erase_line_start_to_cursor()
{
    printf("%s", _ERASE_START_TO_CURSOR_LINE_CODE);
}

void tc_erase_line_cursor_to_end()
{
    printf("%s", _ERASE_CURSOR_TO_END_LINE_CODE);
}
