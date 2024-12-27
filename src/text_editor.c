#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include "tc_erase.h"
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
    vec_init(&file_content, 10, 10, sizeof(struct Vector));
    struct Vector v1;
    vec_init(&v1, 30, 30, sizeof(char));
    vec_append(&file_content, &v1);

    load_init_opts();

    conf_term_opts();

    FILE *f = fopen("/home/novak/Desktop/text_editor.c", "r");

    char c1;
    while((c1 = getc(f)) != EOF)
    {
        if(c1 == '\n')
        {
            struct Vector v1;
            vec_init(&v1, 30, 30, sizeof(char));
            vec_append(&file_content, &v1);
        }
        else
        {
            struct Vector* last_line_vec = (struct Vector*)vec_at(&file_content, file_content.count - 1);
            vec_append(last_line_vec, &c1);
        }
    }

    // printf("\n\nFILE CONTENT:");
    // int i, j;
    // for(i = 0; i < file_content.count; i++)
    // {
    //     struct Vector* curr_vec = ((struct Vector*)vec_at(&file_content, i));
    //     for(j = 0; j < curr_vec->count; j++)
    //     {
    //         printf("%c", vec_at(curr_vec, j));
    //     }
    // }
    //
    char c;
    char mode = 'n';
    while(1)
    {
        read(STDIN_FILENO, &c, 1);

        if(mode == 'n')
        {
            if(c == 'q')
                break;
            else if(c == 'i')
                mode = 'i';
            else if(c == 'j')
                tc_rel_move_cursor_y(1);
            else if(c == 'k')
                tc_rel_move_cursor_y(-1);
            else if(c == 'h')
                tc_rel_move_cursor_x(-1);
            else if(c == 'l')
                tc_rel_move_cursor_x(1);
            else if(c == 'x')
                tc_erase();
            else if(c == 'c')
                tc_erase_line();
            else if(c == 'v')
                tc_erase_screen();
            else if(c == 'b')
                tc_erase_line_cursor_to_end();
        }
        else
        {
            if(c == 127)
            {
                tc_rel_move_cursor_x(-1);
                tc_erase();
            }
            else if(c == 27)
                mode = 'n';
            else
                printf("%c", c);
        }

    }

    reset_opts();

    return EXIT_SUCCESS;
}
