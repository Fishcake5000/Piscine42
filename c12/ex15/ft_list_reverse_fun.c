#include "ft_list.h"

int	ft_list_size(t_list *begin)
{
	int	count;

	count = 0;
	while (begin)
	{
		count++;
		begin = begin->next;
	}
	return (count);
}

t_list	*ft_find_elem(t_list *begin, int nb)
{
	int	i;

	i = 0;
	while (i < nb && begin)
	{
		begin = begin->next;
		i++;
	}
	return (begin);
}

void	ft_swap_data(t_list *link1, t_list *link2)
{
	void	*temp;

	temp = link1->data;
	link1->data = link2->data;
	link2->data = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int	size;
	int	i;

	i = 0;
	size = ft_list_size(begin_list);
	while (i < size - 1 - 2 * i)
	{
		ft_swap_data(begin_list, ft_find_elem(begin_list, size - 1 - 2 * i));
		begin_list = begin_list->next;
		i++;
	}
}
