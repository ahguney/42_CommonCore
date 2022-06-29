#include <unistd.h>

int		space(char c)
{
	return (c == ' ' || c == '\t');
}

void	rostring(char *s)
{
	int		i = 0;
	int		j = 0;

	while (s[i])
	{
		// skip beggining whitespaces
		while (space(s[i]))
			i++;
		if (s[i] && !space(s[i]))
		{
			// if it's the beggining
			if (j == 0)
				// keep the length of first word for later
				while (s[i] && !space(s[i++]))
					j++;
			else
			{
				// for other words, just write it to stdout (+ one whitespace)
				while (s[i] && !space(s[i]) && write(1, &s[i++], 1));
				write(1, " ", 1);
			}
		}
	}
	i = 0; // write first word
	while (space(s[i]))
		i++;
	while (j--)
		write(1, &s[i++], 1);
}

int		main(int ac, char **av)
{
	if (ac > 1 && *av[1])
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
