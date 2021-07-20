/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:32:12 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/19 12:06:30 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_remove(t_list *link, void (*free_fct)(void *))
{
	t_list	*save;

	save = link->next;
	(*free_fct)(link->data);
	free(link);
	return (save);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void *))
{
	t_list	*link;

	while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
		*begin_list = ft_remove(*begin_list, free_fct);
	link = *begin_list;
	while (link && link->next)
	{
		if ((*cmp)(link->next->data, data_ref) == 0)
			link->next = ft_remove(link->next, free_fct);
		else
			link = link->next;
	}
}
