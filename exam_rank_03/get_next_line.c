#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	*buf;
	char	c;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	i = 0;
	rd = read(fd, &c, 1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (rd > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break ;
		rd = read(fd, &c, 1);
	}
	if ((rd < 0) && (i == 0))
		return (free(buf), NULL);
	buf[i] = '\0';
	return (buf);
}

int main()
{
	int i = 0;
	int a = open("a.txt",O_RDWR,0);
	char *b = get_next_line(a); 
	while(get_next_line(a))
	{
		printf("%s",get_next_line(a));
	}
}