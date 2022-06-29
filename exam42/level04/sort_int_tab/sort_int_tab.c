void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int j;

	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			j = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = j;
			i = -1;
		}
		i++;
	}
}
