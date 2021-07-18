/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:09:50 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/18 20:14:38 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*link;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	link = *begin_list;
	while (link->next)
		link = link->next;
	link->next = ft_create_elem(data);
}
