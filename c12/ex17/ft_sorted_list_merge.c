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

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
