#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "tc_display.h"
#include "tc_cursor.h"
#include "assert.h"
#include "misc.h"

void _update_display_info();
void _update_display_handler(int sig);

// ----------------------------------------------------------------------------

struct DisplayInfo
{
    struct Point2D dimensions;
};

struct DisplayInfo display_info;

void _tc_display_init()
{
    struct sigaction new_sigact;
    new_sigact.sa_handler = _update_display_handler;

    int status = sigaction(SIGWINCH, &new_sigact, NULL);

    ASSERT(status == 0, "Failure to set handler.");

    _update_display_info();
}

size_t tc_get_display_height()
{
    return display_info.dimensions.y;
}

size_t tc_get_display_width()
{
    return display_info.dimensions.x;
}

void _update_display_handler(int sig)
{
    _update_display_info();
}

void _update_display_info()
{
    struct winsize win_size;

    int status = ioctl(STDOUT_FILENO, TIOCGWINSZ, &win_size);

    ASSERT(status == 0, "Failure to get window size.");

    display_info.dimensions.y = win_size.ws_row;
    display_info.dimensions.x = win_size.ws_col;

    tc_cursor_fix_pos();
}
