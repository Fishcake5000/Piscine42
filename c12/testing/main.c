#include "ft_list.h"
#include "stdio.h"
#include <unistd.h>
#include <string.h>

t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_list_reverse_fun(t_list *begin_list);

void	ft_putstr(void *str)
{
	int i;
	char *string;

	string = (char *)str;
	i = 0;
	while (string[i])
	{
		write(1, string + i, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_begins_w(void *data, void *data_ref)
{
	char *str;
	char *ref;

	str = (char *)data;
	ref = (char *)data_ref;
	if (str[0] == ref[0])
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_list *begin;

	begin = ft_list_push_strs(argc - 1, argv + 1);
	ft_list_foreach(begin, &ft_putstr);
	ft_list_sort(&begin, strcmp);
	ft_list_foreach(begin, &ft_putstr);
}