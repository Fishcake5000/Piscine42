#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*link;
	t_list	*new;

	new = ft_create_elem(data);
	if (!*begin_list)
	{
		*begin_list = new;
		return ;
	}
	if ((*cmp)(data, (*begin_list)->data) < 0)
	{
		new->next = *begin_list;
		*begin_list = new;
		return ;
	}
	link = *begin_list;
	while (link->next && (*cmp)(data, link->next->data) > 0)
		link = link->next;
	new->next = link->next;
	link->next = new;
}
