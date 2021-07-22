#include <stdlib.h>
#include <unistd.h>

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2)
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	if (i % 2)
		return (i);
	return (0);
}

void	ft_print(int **array, int size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = array[i][j] + '0';
			write(1, &c, 1);
			if (j < size - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			j++;
		}
		i++;
	}
}

int	ft_parse(char *str, int **clues, int str_size, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < 4 && i * size * 2 < str_size)
	{
		clues[i] = malloc(sizeof(int) * size);
		if (!clues[i])
			return (1);
		j = 0;
		while (j < size && i * size * 2 + j * 2 < str_size)
		{
			tmp = str[i * size * 2 + j * 2] - '0';
			if (tmp <= size && tmp > 0)
				clues[i][j] = tmp;
			else
				return (1);
			j++;
		}
		i++;
	}
	return (i != 4 || j != size || str[size * 8 - 1]);
}

int	ft_arr_init(int **array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		array[i] = malloc(sizeof(int) * size);
		if (!array[i])
			return (1);
		j = 0;
		while (j < size)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}
