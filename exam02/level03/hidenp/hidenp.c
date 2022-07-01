#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;

	if (ac == 3)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] == av[2][j])
				i++;
			if (av[2][j] == '\0')
			{
				write(1, "0\n", 2);
				return(0);
			}
			j++;
		}
		write(1, "1", 1);
	}
	write (1, "\n", 1);
	return (0);
}