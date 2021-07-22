#ifndef FT_PARSING_BASIC_H
# define FT_PARSING_BASIC_H
# include <stdlib.h>
# include "ft_parsing_helper.h"
int		ft_count_lines(char *buffer, int size);
int		ft_size_line(char *str, int size);
char	*ft_copy_line(char *buffer, int size, int *idx);
void	ft_free_char_array(char **array);
char	**ft_split_lines(char *buffer);
#endif
