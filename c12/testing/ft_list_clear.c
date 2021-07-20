/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:46:38 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/18 20:50:52 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void(*free_fct)(void *))
{
	t_list	*temp;

	while (begin_list)
	{
		temp = begin_list->next;
		(*free_fct)(begin_list->data);
		free(begin_list);
		begin_list = temp;
	}
}
