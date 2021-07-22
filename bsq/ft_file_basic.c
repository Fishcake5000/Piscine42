#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_file_size(char *filename)
{
	int		size;
	int		fd;
	int		byte_count;
	char	buff[1];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = 0;
	byte_count = read(fd, buff, 1);
	size += byte_count;
	while (byte_count)
	{
		if (byte_count < 0)
			return (-1);
		byte_count = read(fd, buff, 1);
		size += byte_count;
	}
	close(fd);
	return (size);
}

char	*ft_load_file(char *filename)
{
	int		size;
	int		fd;
	char	*buffer;

	size = ft_file_size(filename);
	if (size <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (read(fd, buffer, size) < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[size] = 0;
	close(fd);
	return (buffer);
}
