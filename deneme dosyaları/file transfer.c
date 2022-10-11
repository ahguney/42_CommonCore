#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER_SIZE 1

char *get_next_line(int fd)
{
	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	int r = 0;
	int rd = 0;
	char *buf;
	buf = malloc(9999);
	r = read(fd,buf + rd,1);
	rd += r;
	while(r != 0 && buf[rd - 1] != '\n')
	{
		r = read(fd,buf + rd,1);
		rd += r;
		if(r == -1)
			return(free(buf),NULL);
	}
	buf[rd] = '\0';
	if(!buf || !*buf)
		return(free(buf),NULL);
	return(buf);
}

int main()
{
	FILE * fp;
	int a = open("a.txt",O_RDWR,0);	
	fp = fopen("b.txt","w+");
	char *c = get_next_line(a);
	while(c)
	{
		fprintf(fp,"%s",c);
		c = get_next_line(a);
	}
}

int main()
{
	int i = -1;  
	int a = open("a.txt",O_RDWR,0);
	int b = open("b.txt",O_RDWR,0);
	char *c = get_next_line(a);
	while (c)
	{
		write(b,c,strlen(c));
		c = get_next_line(a);
	}
	
}