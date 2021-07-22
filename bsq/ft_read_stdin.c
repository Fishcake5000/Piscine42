#include "ft_parsing_basic.h"
#include "ft_struct_operations.h"
#include "ft_file_basic.h"
#include "ft_read.h"

char	*ft_load_stdin(void)
{
	char	*buffer;
	int		idx;
	int		byte_count;

	buffer = malloc(sizeof(char) * 10000000);
	byte_count = read(STDIN_FILENO, buffer, 10000000);
	idx = 0;
	idx += byte_count;
	while (byte_count)
	{
		byte_count = read(STDIN_FILENO, buffer + idx, 10000000 - idx);
		idx += byte_count;
	}
	buffer[idx] = 0;
	return (buffer);
}

t_map_data	*ft_read_from_stdin(void)
{
	t_map_data	*data;
	char		*file_content;
	char		**array;

	file_content = ft_load_stdin();
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
