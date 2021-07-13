/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:54:03 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/08 14:43:47 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (max <= min)
		return (0);
	tab = malloc(sizeof(int) * (max - min));
	if (!tab)
		return (tab);
	i = 0;
	while (i < max - min)
	{
		tab[i] = i + min;
		i++;
	}
	return (tab);
}
