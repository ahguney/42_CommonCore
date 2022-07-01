#include <stdlib.h>

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		i = 0;

	dup = (char *)malloc(sizeof(*s1) - 1);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
