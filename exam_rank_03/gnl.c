#include "get_next_line.h"

char *get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	int r = 0;
	int rd = 0;
	char *buf;
	buf = malloc(99999);
	r = read(fd, buf + rd, 1);
	rd += r;
	while (r != 0 && buf[rd - 1] != '\n')
	{
		r = read(fd, buf + rd, 1);
		rd += r;
		if (r == -1)
		{
			free(buf);
			return NULL;
		}
	}
	buf[rd] = '\0';
	if (!buf || !*buf)
	{
		free(buf);
		return NULL;
	}
	return (buf);
}

int main()
{
	int i = 0;
	int a = open("a.txt",O_RDWR,0);
	char *b = get_next_line(a); 
	while(i<10)
	{
		printf("%s",get_next_line(a));
		i++;
	}
}
