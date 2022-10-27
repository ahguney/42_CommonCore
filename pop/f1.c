#include <stdio.h>
int main()
{
    char **argv;
    char *argv1;
    argv = &argv1;
    argv[0] = "fprkan";
    (argv)++;
    printf("%c", **argv);
}