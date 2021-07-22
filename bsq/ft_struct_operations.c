#include <stdlib.h>
#include "ft.h"
#include <unistd.h>

t_map_data	*ft_struct_init(void)
{
	t_map_data	*new;

	new = malloc(sizeof(t_map_data));
	if (!new)
		return (NULL);
	new->map = NULL;
	return (new);
}

void	ft_free_struct(t_map_data *data)
{
	int	i;

	i = 0;
	if (data && data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	free(data);
}
