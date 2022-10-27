#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int asal(int c, int y)
{
    int a = 0;
    a = c;
    int p = 0;
    while (c > y)
    {
        if (c % y == 0)
        {
            p++;
        }
        y++;
    }
    if (p == 0)
    {
        return (1);
    }
    else
    return (0);
}

int main(int argc,char **argv)
{
    int c  = atoi(argv[1]);
     int i = 0;
    int f = 2;  int   y = 2;
    if (argc == 2)
    {
    while (f <= c)
    {
        if (c % f == 0)
        {
            if ((asal(f, y)) == 1)
            {
                 printf("%d", f);
                 if (f != c)
                 printf("*");
                c /=f;
            }
             f -=1;
        }
        f++;
       
    }
    }
}