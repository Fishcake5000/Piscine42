/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:35:27 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/14 13:48:37 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_order(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (1);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	is_ascending;
	int	comp;

	if (length <= 2)
		return (1);
	i = 0;
	is_ascending = ft_find_order(tab, length, f);
	while (i < length - 1)
	{
		comp = (*f)(tab[i], tab[i + 1]);
		if (comp < 0 != is_ascending && comp)
			return (0);
		i++;
	}
	return (1);
}
