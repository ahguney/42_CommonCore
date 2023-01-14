#include <stdio.h>
#include <stdlib.h>

int ft_strchr(char *str, char b)
{
    int f;

    f = 0;
    while (*str != '\0')
    {
        if (*str == b)
        {
            f++;
        }
        str++;
    }
    return (f);
}
char **ft_split(char *str, char a)
{
    char **split1;
    split1 = malloc(sizeof(char **)*100);
    int i;
    i = 0;
    int ab;
    ab = 0;
    int y;
    y = 0;
    int w;
    w = 0;
    while (str[i] == a)
    i++;
    while (str[i] != '\0')
    {
        if (!split1[ab])
        split1[ab] = malloc(sizeof(char *) * 1000);
        if (str[i] != a)
        {
            split1[ab][y] = str[i];
            y++;
        }
        if (str[i] == a)
        {
            while (str[i] == a)
            {
                ++i;
            }
            ab++;
            split1[ab] = NULL;
            y = 0;
        }
        else
        i++;
    }
    return (split1);
}

int main()
{
    char split[] = "     furkan        guney             adkasdakdkasdkasdkaskdaskdaskdkas      ";
    char **split1;
    split1 = ft_split(split, ' ');
    int i;
    i = 0;
  
        printf("%s\n", split1[1]);
        
}