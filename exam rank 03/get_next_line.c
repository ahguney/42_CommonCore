#include "get_next_line.h"

char *ft_strdup(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    i++;
    char *buf=malloc(i + 1);
    i = 0;
    while (str[i] != '\0')
    {
        buf[i] = str[i];
        i++;
    }
    buf[i] = '\0';
    return (buf);
}

char *get_next_line(int fd)
{
    char line[1000000] = {'\0'};
    char rd[1];

    int i = 0;
    int n;

    if (rd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
    while ((n = read(fd, rd, 1)) && n > 0)
    {
        line[i++] = rd[0];
        line[i] = 0;
        if (rd[0] == '\n')
        return (ft_strdup(line));
    }
    if (!line[0])
    return (NULL);
    return (ft_strdup(line));
}

int main()
{
    int fd =open("a.txt", O_RDONLY);
    char *b =get_next_line(fd);
    while (b)
    {
        write(1, b, strlen(b));
        b = get_next_line(fd);
    }
}