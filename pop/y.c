#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
    int i = 0;
    int f = 2;  int q = 0;  int y = 2;

    i = atoi(argv[1]);

    if (argc == 2)
    {
    while (i > 0)
    {
        if (i % f == 0)
        {
            while (f >= y)
            {
                if (f % y == 0)
                {
                    printf("%d*", y);
                }
                y++;
            }
            i /= f;
        }
        f++;
    }
}
}