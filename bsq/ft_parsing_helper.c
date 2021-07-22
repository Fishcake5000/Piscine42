int	ft_is_not_print(char c1, char c2, char c3)
{
	int	is_not_print;

	is_not_print = (c1 < 32 || c1 > 126);
	is_not_print += (c2 < 32 || c2 > 126);
	is_not_print += (c3 < 32 || c3 > 126);
	return (is_not_print);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	size;

	i = 0;
	res = 0;
	size = ft_strlen(str) - 4;
	while (i < size && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (i == size && size)
		return (res);
	return (0);
}
