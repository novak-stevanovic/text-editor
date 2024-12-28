#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "tc_display.h"
#include "assert.h"

void _set_win_size();
void _update_display_handler(int sig);

// ----------------------------------------------------------------------------

struct DisplayInfo
{
    size_t height, width;
};

struct DisplayInfo display_info;

void _tc_display_init()
{
    struct sigaction new_sigact;
    new_sigact.sa_handler = _update_display_handler;

    int status = sigaction(SIGWINCH, &new_sigact, NULL);

    ASSERT(status == 0, "Failure to set handler.");

    _set_win_size();
}

size_t tc_get_display_height()
{
    return display_info.height;
}

size_t tc_get_display_width()
{
    return display_info.width;
}

void _update_display_handler(int sig)
{
    _set_win_size();
}

void _set_win_size()
{
    struct winsize win_size;

    int status = ioctl(STDOUT_FILENO, TIOCGWINSZ, &win_size);

    ASSERT(status == 0, "Failure to get window size.");

    display_info.height = win_size.ws_row;
    display_info.width = win_size.ws_col;
}
