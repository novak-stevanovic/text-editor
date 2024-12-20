#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "vector.h"
#include "assert.h"

void conf_term_opts(struct termios init_opts)
{
    init_opts.c_lflag &= ~(ICANON);
    // init_opts.c_iflag &= (IGNBRK);
    init_opts.c_lflag &= ~(ECHO);

    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &init_opts);
}

void show_file_content(FILE *f)
{
}

void print_vector(struct Vector* v)
{
    for (size_t i = 0; i < v->count; i++) {
        printf("%d, %p | ", *((int*)vec_at(v, i)), vec_at(v, i));
    }
    putchar('\n');
}

int main(int argc, char *argv[])
{
    // FILE* f;
    // f = fopen("test.txt", "w");
    // struct termios init_opts;
    // tcgetattr(STDOUT_FILENO, &init_opts);
    //
    // conf_term_opts(init_opts);
    //
    // fclose(f);
    // tcsetattr(STDOUT_FILENO, TCSAFLUSH, &init_opts);
    // printf("Settings reverted.\n");
    struct Vector* v1 = vec_init(100, sizeof(int));
    return EXIT_SUCCESS;
}
