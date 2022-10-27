#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>

int funct1(int b, int c)
{
    return b -c ;
    
}
int main()
{
    int pid = fork();
    int a = 8;
    int b = 10;
    int c = 55;
    int d;
    if (pid != 0)
    {
        printf("%d\n",getpid());
    
    }
     else if (pid == 0)
    {
        printf("%d\n", getpid());
    }
   

}