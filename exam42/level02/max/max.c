int	max(int *tab, unsigned int len)
{
	int	max;

	if (!len)
		return (0);
	max = tab[--len];//without '\0'
	while (len--)//searching max from back
		if (tab[len] > max)//if it is max
			max = tab[len];//tak it from array
		return max;
}
