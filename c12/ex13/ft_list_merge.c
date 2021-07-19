/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:08:13 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/19 12:13:45 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
