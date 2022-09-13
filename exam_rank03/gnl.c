#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    char *c = (char *)malloc(sizeof(char) * 10000), *i = c;
    while (read(fd, i, 1) > 0 && *i++ != '\n');
    return i > c ? (*i = 0, c) : (free(c), NULL);
}

#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int     fd;
    int     line;
    char    *string;

    line = 1;
    string = NULL;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        string = get_next_line(fd);
        while (string != NULL)
        {
            printf("Line %d - %s ", line, string);
            string = get_next_line(fd);
            line++;
        }
        if (!string)
            printf("Line %d - (null) EOF", line);
        close(fd);
    }
    return (0);
}
