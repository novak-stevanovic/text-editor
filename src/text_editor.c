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
    // struct Vector* v1 = vec_init(1, 100, sizeof(int));
    // print_vector(v1);
    //
    // int status;
    //
    // int n1 = 10;
    // status = vec_append(v1, &n1);
    // ASSERT(status == 0, "Failure to append.");
    // print_vector(v1);
    //
    // int n2 = 15;
    // status = vec_append(v1, &n2);
    // ASSERT(status == 0, "Failure to append.");
    // print_vector(v1);
    //
    // status = vec_remove(v1, 0);
    // ASSERT(status == 0, "Failure to remove.");
    // print_vector(v1);

    return EXIT_SUCCESS;
}
