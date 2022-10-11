#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int c = 0;
    int i = fork();
    if(i != 0)
    {
        c = 19;
        int a = fork();
        if(a != 0)
        {
        wait(NULL);
        printf("%d",16);
        }
        else if(a == 0)
        {
            printf("%d",c);
        }
           
    }
    if(i == 0)
    {
        printf("hellos");
        exit(0);
    }

}