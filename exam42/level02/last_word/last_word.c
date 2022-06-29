#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i] != '\0')
            i++;//go till the end
        i--;//remove '\0'
        while (av[1][i] == ' ' || av[1][i] == '\t')
        {
            av[1][i] = '\0';
            i--;
        }
        while ((av[1][i] != ' ' || av[1][i] != '\t') && av[1][i] > 32)//check if it is unprintable
            i--;
        while ((av[1][i] != ' ' || av[1][i] != '\t') && av[1][i + 1] != '\0')//write till '\0'
            write (1, &av[1][++i],1);
    }
    write (1, "\n", 1);
    return (0);
}

