#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*link;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	link = *begin_list1;
	while (link->next)
		link = link->next;
	link->next = begin_list2;
}

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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
