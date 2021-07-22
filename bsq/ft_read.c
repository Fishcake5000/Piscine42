#include "ft_parsing_basic.h"
#include "ft_struct_operations.h"
#include "ft_file_basic.h"

int	ft_read_first_line(t_map_data *data, char *line)
{
	int	size;

	data->nb_lines = ft_atoi(line);
	size = ft_strlen(line);
	if (line[size - 1] != '\n' || size < 5 || data->nb_lines <= 0)
		return (1);
	data->empty = line[size - 4];
	data->obstacle = line[size - 3];
	data->full = line[size - 2];
	if (ft_is_not_print(data->empty, data->obstacle, data->full)
		|| data->empty == data->full || data->full == data->obstacle
		|| data->empty == data->obstacle)
		return (1);
	return (0);
}

int	ft_alloc_map(t_map_data *data, char **array)
{
	int	i;

	if (!array[0] || ft_read_first_line(data, array[0]) || !array[1])
		return (1);
	data->nb_cols = ft_strlen(array[1]) - 1;
	data->map = malloc(sizeof(int *) * (data->nb_lines + 1));
	if (!data->map)
		return (1);
	i = 0;
	while (i < data->nb_lines && array[i + 1])
	{
		data->map[i] = malloc(sizeof(int) * data->nb_cols);
		if (!(data->map[i]))
			return (1);
		i++;
	}
	data->map[i] = NULL;
	if (array[i + 1] || i != data->nb_lines)
		return (1);
	return (0);
}

int	ft_fill_struct(t_map_data *data, char **array)
{
	int	i;
	int	j;

	if (ft_alloc_map(data, array))
		return (1);
	i = 0;
	while (i < data->nb_lines && array[i + 1])
	{
		j = 0;
		while (j < data->nb_cols)
		{
			if (array[i + 1][j] == data->obstacle)
				data->map[i][j] = 0;
			else if (array[i + 1][j] == data->empty)
				data->map[i][j] = 1;
			else
				return (1);
			j++;
		}
		if (array[i + 1][j] && array[i + 1][j] != '\n')
			return (1);
		i++;
	}
	return (0);
}

t_map_data	*ft_read_from_file(char *filename)
{
	t_map_data	*data;
	char		*file_content;
	char		**array;

	file_content = ft_load_file(filename);
	if (!file_content)
		return (NULL);
	array = ft_split_lines(file_content);
	free(file_content);
	if (!array)
		return (NULL);
	data = ft_struct_init();
	if (!data || ft_fill_struct(data, array))
	{
		ft_free_char_array(array);
		ft_free_struct(data);
		return (NULL);
	}
	ft_free_char_array(array);
	return (data);
}
