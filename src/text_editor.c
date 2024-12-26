#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include "vector.h"
#include "assert.h"
#include "tc_cursor_control.h"

size_t _itostr(int x, char* buffer);

struct termios init_opts;

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

    init_opts_cpy.c_iflag &= (INLCR);
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
    struct Vector v1;
    vec_at(&v1, 0);

    load_init_opts();

    conf_term_opts();

    char c;
    while(1)
    {
        read(STDIN_FILENO, &c, 1);

        if(c == 'q')
            break;
        else if(c == 'x')
            rel_move_cursor_y(1);
        else
            printf("%c", c);

    }

    reset_opts();

    return EXIT_SUCCESS;
}
