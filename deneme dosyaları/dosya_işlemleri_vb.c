#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	char *o;
	char b = 0;
	int i = read(3,o,3);
	char *a = &b;
	fgets(a,11,stdin); // dosyadan okur
	fputs("lalal",stdout); // okuduğunu ekrana basar
	printf("%s",a); 
	putchar('?'); // char yazar
	puts("oooo"); // string yazar
	if(i == -1)
	{
	perror("error"); //error: Bad file descriptor yazar if içindekini kontrol edip hatayı basar
	}
}