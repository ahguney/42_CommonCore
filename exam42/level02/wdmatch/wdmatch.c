#include <unistd.h>

void	wdmatch(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] != '\0')
	{
		while (*s2 != s1[i] && *s2 != '\0')
			++s2;
		if (*s2 == '\0')
			return ;
		++i;
		++s2;
	}
	write(1, s1, i);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
