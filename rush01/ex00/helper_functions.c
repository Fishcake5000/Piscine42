void	ft_reset_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
}

int	*ft_rev_tab(int	*tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - i - 1)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
	return (tab);
}
