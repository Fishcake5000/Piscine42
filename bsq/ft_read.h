#ifndef FT_READ_H
# define FT_READ_H
# include "ft_parsing_basic.h"
# include "ft_struct_operations.h"
# include "ft_file_basic.h"
int			ft_read_first_line(t_map_data *data, char *line);
int			ft_alloc_map(t_map_data *data, char **array);
int			ft_fill_struct(t_map_data *data, char **array);
t_map_data	*ft_read_from_file(char *filename);
#endif
