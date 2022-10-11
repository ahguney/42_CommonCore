#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

void *th1()
{
	printf("hello");
}

void *th2()
{
	sleep(1);
	printf("Merhaba");
}

int	main()
{
	pthread_t t1,t2;

	pthread_create(&t1,NULL,th1,NULL);
	pthread_create(&t2,NULL,th2,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}


