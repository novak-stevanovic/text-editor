#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include "tc_display.h"
#include "vector.h"
#include "assert.h"
#include "tc_cursor.h"

struct termios init_opts;

struct Vector file_content;

void conf_term_opts()
{
    struct termios init_opts_cpy = init_opts;

    // cfmakeraw(&init_opts_cpy);

    init_opts_cpy.c_lflag &= ~(ICANON);
    init_opts_cpy.c_lflag &= ~(ECHO);
    init_opts_cpy.c_lflag &= ~(ISIG);
    init_opts_cpy.c_lflag &= ~(ECHONL);

    init_opts_cpy.c_iflag &= (IGNBRK);
    init_opts_cpy.c_iflag &= (BRKINT);

    // init_opts_cpy.c_iflag &= (INLCR);
    // init_opts_cpy.c_iflag &= (IGNCR);

    setvbuf(stdout, NULL, _IONBF, 0);

    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &init_opts_cpy);
}

void load_init_opts()
{
    tcgetattr(STDOUT_FILENO, &init_opts);
}

void reset_opts()
{
    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &init_opts);
}

int main(int argc, char *argv[])
{
    load_init_opts();

    conf_term_opts();

    reset_opts();

    return EXIT_SUCCESS;
}
