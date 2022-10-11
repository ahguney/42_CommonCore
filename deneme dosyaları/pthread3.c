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
    pthread_exit(a);
}

void *th2(void *b)
{
	int x;
    x = (int)b;
    b++;
    pthread_exit(b);
}

int	main()
{
	pthread_t t1,t2;

    int x = 100;

	pthread_create(&t1,NULL,th1,(void *)x);
	pthread_create(&t2,NULL,th2,(void *)x);

    void *thread1;
    void *thread2;
	pthread_join(t1,&thread1);
	pthread_join(t2,&thread2);

    printf("a = %d b = %d",thread1,thread2);
}