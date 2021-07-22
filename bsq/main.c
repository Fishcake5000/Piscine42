#include <unistd.h>
#include "solve.h"
#include "ft_struct_operations.h"
#include "ft_read.h"
#include "ft_read_stdin.h"
#include "ft_display.h"

void	ft_map_error(void)
{
	write(1, "map error\n", 10);
}

void	ft_solve_file(char *filename)
{
	t_map_data	*data;

	data = ft_read_from_file(filename);
	if (!data)
		return (ft_map_error());
	init_largest(data);
	solve(data);
	ft_display(data);
	ft_free_struct(data);
}

void	ft_solve_stdin(void)
{
	t_map_data	*data;

	data = ft_read_from_stdin();
	if (!data)
		return (ft_map_error());
	init_largest(data);
	solve(data);
	ft_display(data);
	ft_free_struct(data);
}

int	main(int argc, char **argv)
{
	char	**filelist;
	int		i;

	filelist = argv + 1;
	i = 0;
	if (!filelist[i])
		ft_solve_stdin();
	while (filelist[i])
	{
		ft_solve_file(filelist[i]);
		if (i < argc - 2)
			write(1, "\n", 2);
		i++;
	}
}
