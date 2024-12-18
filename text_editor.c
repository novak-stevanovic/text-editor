#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

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
    FILE* f;
    f = fopen("test.txt", "w");
    struct termios init_opts;
    tcgetattr(STDOUT_FILENO, &init_opts);

    conf_term_opts(init_opts);

    fclose(f);
    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &init_opts);
    printf("Settings reverted.\n");
    return EXIT_SUCCESS;
}
