#ifndef FT_FILE_BASIC_H
# define FT_FILE_BASIC_H
# include <fcntl.h>
# include <unistd.h>
int		ft_file_size(char *filename);
char	*ft_load_file(char *filename);
#endif
