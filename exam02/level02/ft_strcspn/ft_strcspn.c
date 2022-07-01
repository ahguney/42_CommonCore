size_t ft_strcspn(const char *s1, const char *s2)
{
	int	i = 0;
	int	j = 0;

	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return (i);
			j++;
		}
		i++;
	}
	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}
