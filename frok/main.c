#include "get_next_line.h"
int main()
{
	int fd = open("f.txt", O_RDONLY);
	char *b = get_next_line(fd);
	
	while (b)
	{
		printf("%s", b);	
		b = get_next_line(fd);
	}
}