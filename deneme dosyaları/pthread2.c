#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

void *th1(void *a)
{
	int x;
    x = (int)a;
    a--;
    printf("a = %d",(int)a);
}

void *th2(void *b)
{
	int x;
    x = (int)b;
    b++;
    printf("b = %d",(int)b);
}

int	main()
{
	pthread_t t1,t2;

    int x = 100;

	pthread_create(&t1,NULL,th1,(void *)x);
	pthread_create(&t2,NULL,th2,(void *)x);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}