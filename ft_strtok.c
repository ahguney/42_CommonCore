#include <stdio.h>

char  *ft_strtok(char *str, char a)
{
    int i;
    i = 0;
    char *str1;
    int b= 0;
     while (str[i])
     {
        if (str[i] == a)
        {
            i++;            
        }
        str1[b] = str[i];
        b++;
        i++;
     }
     return (str1);
}