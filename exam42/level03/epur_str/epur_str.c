#include <unistd.h>

int		main(int argc, char const *argv[])
{
	int		i;
	int		j;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i += 1;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				j = 1;
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				if (j)
					write(1, " ", 1);
				j = 0;
				write(1, &argv[1][i], 1);
			}
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}