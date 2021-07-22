#include <stdlib.h>
#include "ft_parsing_helper.h"

int	ft_count_lines(char *buffer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	ft_size_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_copy_line(char *buffer, int *idx)
{
	char	*str;
	int		line_size;
	int		i;

	line_size = ft_size_line(buffer + *idx);
	str = malloc(sizeof(char) * (line_size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < line_size)
	{
		str[i] = buffer[*idx + i];
		i++;
	}
	*idx += i;
	str[i] = 0;
	return (str);
}

void	ft_free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split_lines(char *buffer)
{
	int		i;
	int		nb_lines;
	int		arr_idx;
	char	**array;

	i = 0;
	arr_idx = 0;
	nb_lines = ft_count_lines(buffer);
	array = malloc(sizeof(char *) * (nb_lines + 1));
	if (!array)
		return (NULL);
	while (buffer[i] && arr_idx < nb_lines)
	{
		array[arr_idx] = ft_copy_line(buffer, &i);
		if (!array[arr_idx])
		{
			ft_free_char_array(array);
			return (NULL);
		}
		arr_idx++;
	}
	array[arr_idx] = NULL;
	return (array);
}
