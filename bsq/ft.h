#ifndef FT_H
# define FT_H
typedef struct s_pos
{
	int	col;
	int	lin;
	int	value;
}	t_pos;
typedef struct s_map_data
{
	int		**map;
	char	empty;
	char	full;
	char	obstacle;
	int		nb_lines;
	int		nb_cols;
	t_pos	largest;
}	t_map_data;
#endif
