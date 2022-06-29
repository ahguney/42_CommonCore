int	is_power_of_2(unsigned int n)
{
	int	i = 1;

	while (i <= n)
	{
		if (i == n)
			return (1);
		i *= 2;//-> ^2, i *= 3; -> ^3
	}
	return (0);
}
