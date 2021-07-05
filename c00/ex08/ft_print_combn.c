/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 07:33:00 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/01 09:31:47 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar(array[i] + '0');
		i++;
	}
}

void	ft_increment_array(int *array, int size)
{
	int	index;

	index = size - 1;
	array[index]++;
	while (array[index] > (10 - size + index) && index > 0)
	{
		index--;
		array[index]++;
	}
	while (index < size - 1)
	{
		array[index + 1] = array[index] + 1;
		index++;
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	array[10];

	if (n < 1 || n > 9)
		return ;
	i = 0;
	while (i < n)
	{
		array[i] = i;
		i++;
	}
	ft_print_array(array, n);
	ft_increment_array(array, n);
	while (array[n - 1] < 10)
	{
		write(1, ", ", 2);
		ft_print_array(array, n);
		ft_increment_array(array, n);
	}
}
