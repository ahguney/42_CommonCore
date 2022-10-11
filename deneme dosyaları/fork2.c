#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int a = fork();
    printf("%d",a);
    if(a > 0)
     {
        int pid = fork();
        if(pid > 0)
        {
          //parent 
          printf("PARENT CHİLD");
        }
        else if(pid == 0)
        {
          printf("SAG CHİLD");
        }
     }
     else if(a == 0)
     {
      printf("%d",a);
        printf("SOL CHİLD");
    }
}