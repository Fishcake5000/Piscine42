#ifndef IO_FUNCTIONS_H
# define IO_FUNCTIONS_H
# include <stdlib.h>
# include <unistd.h>
int		ft_error(void);
int		ft_strlen(char *str);
void	ft_print(int **array, int size);
int		ft_parse(char *str, int **clues, int str_size, int size);
int		ft_arr_init(int **array, int size);
#endif