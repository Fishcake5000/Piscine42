#include <unistd.h>
#include "ft.h"

int	ft_is_full(t_map_data data, int lin, int col)
{
	int	is_full;

	is_full = lin > data.largest.lin - data.largest.value;
	is_full = is_full && lin <= data.largest.lin;
	is_full = is_full && col > data.largest.col - data.largest.value;
	is_full = is_full && col <= data.largest.col;
	return (is_full);
}

void	ft_display(t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_lines)
	{
		j = 0;
		while (j < data->nb_cols)
		{
			if (data->map[i][j] == 0)
				write(1, &data->obstacle, 1);
			else if (ft_is_full(*data, i, j))
				write(1, &data->full, 1);
			else
				write(1, &data->empty, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
