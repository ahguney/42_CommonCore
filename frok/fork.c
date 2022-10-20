#include <signal.h>
# include <stdio.h>
# include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
void af(int pid1, int pid2)
{
    char dosya[20];
    sprintf(dosya, "%d", pid1);
    char dosya2[20];
    sprintf(dosya2, "%d", pid2);
    FILE *p = fopen(dosya, "w");
    FILE *fp1 = fopen(dosya2, "w");
    fprintf(p, "%d", 100);
    fprintf(fp1, "%d", 101);
    fclose(p);
    fclose (fp1);
}

int main()
{
    int pid = fork();
    int pid2;
    if (pid > 0)
    {
        pid2 = fork();
        af(pid, pid2);
    }
    
    
}