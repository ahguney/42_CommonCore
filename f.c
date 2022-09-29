#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char **split(char *str)
{
    int i = 0;
    char **split1;
    split1 = malloc(sizeof(char*) * 1000);
    int a = 0;
    int j = 0;
    i=0;
    while (str[i] == ' ' || str[i] == '\t')
    {
        i++;
    }
    while (str[i] != '\0')
    {
        split1[a] = malloc(sizeof(char *) * 1000);
        while (str[i] == ' ' || str[i] == '\t')
        {
            i++;
        }
        j = 0;
        while (str[i] != '\0' && str[i] > 32)
        {
            split1[a][j] = str[i];
            i++;
            j++;
        }
        split1[a][j] = '\0';
        a++;
    }
    split1[a] = 0;
    return (split1);
}


int		main(int ac, char **av)
{
	int i;
	char **tab;

    i = 1;
    if (ac == 2)
    {
        tab = split(av[1]);
        while (tab[i] != 0)
        {
            ft_putstr(tab[i]);
            write(1, " ", 1);
            i++;
        }
        ft_putstr(tab[0]);
    }
    else if (av[1][0] == '\0' || ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    
}