#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, t_list *new, int (*cmp)())
{
	t_list	*link;

	if ((*cmp)(new->data, (*begin_list)->data) < 0)
	{
		new->next = *begin_list;
		*begin_list = new;
		return ;
	}
	link = *begin_list;
	while (link->next && (*cmp)(new->data, link->next->data) > 0)
		link = link->next;
	new->next = link->next;
	link->next = new;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*unsorted;
	t_list	*link;

	if (!*begin_list || !(*begin_list)->next)
		return ;
	unsorted = (*begin_list)->next;
	(*begin_list)->next = 0;
	while (unsorted)
	{
		link = unsorted;
		unsorted = unsorted->next;
		ft_sorted_list_insert(begin_list, link, cmp);
	}
}
