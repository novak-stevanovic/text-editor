#include "primitives/tc_erase_prims.h"
#include <stddef.h>
#include <string.h>
#include <unistd.h>

void tc_erase_screen()
{
    write(STDOUT_FILENO, _ERASE_ENTIRE_SCREEN_CODE, strlen(_ERASE_ENTIRE_SCREEN_CODE));
}

void tc_erase_line()
{
    write(STDOUT_FILENO, _ERASE_ENTIRE_LINE_CODE, strlen(_ERASE_ENTIRE_LINE_CODE));
}

void tc_erase_line_start_to_cursor()
{
    write(STDOUT_FILENO, _ERASE_START_TO_CURSOR_LINE_CODE, strlen(_ERASE_START_TO_CURSOR_LINE_CODE));
}

void tc_erase_line_cursor_to_end()
{
    write(STDOUT_FILENO, _ERASE_CURSOR_TO_END_LINE_CODE, strlen(_ERASE_CURSOR_TO_END_LINE_CODE));
}
