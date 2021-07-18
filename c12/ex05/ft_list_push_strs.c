/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:15:40 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/18 20:44:28 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*link;
	t_list	*save;
	int		i;

	i = size - 1;
	save = 0;
	while (i >= 0)
	{
		link = ft_create_elem(strs[i]);
		link->next = save;
		save = link;
	}
	return (save);
}
