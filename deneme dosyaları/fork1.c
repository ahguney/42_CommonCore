#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void  make_child(int h)
{
    if(h == 0)
        return;
    int pid = fork();
    if(pid > 0)
    {
        int pid2 = fork();
        if(pid2 > 0)
        {
            // parent
            wait(NULL);
            printf("p = %d c1 =%d c2 =%d\n",getpid(),pid,pid2);
            fflush(stdout);
        }
        else if (pid2 == 0)
        {
            // sol child
            make_child(--h);
        }
    }
    else if (pid == 0)
    {
        // sağ child
        make_child(--h);
    }
}
int main()
{
  make_child(3);
}