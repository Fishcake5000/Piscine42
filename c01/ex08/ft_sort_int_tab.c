/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:02:15 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/01 14:57:34 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	index_smallest;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		index_smallest = j;
		while (j < size)
		{
			if (tab[j] < tab[index_smallest])
				index_smallest = j;
			j++;
		}
		temp = tab[i];
		tab[i] = tab[index_smallest];
		tab[index_smallest] = temp;
		i++;
	}
}
