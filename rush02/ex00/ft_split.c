/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:55:58 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/18 17:56:01 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split_basic.h"
#include "ft.h"

void	ft_add_mod2(char **array, int *arr_idx, int i, char *num)
{
	if (num[i] != '0')
	{
		array[*arr_idx] = ft_add_zero(num[i], 0);
		(*arr_idx)++;
		array[*arr_idx] = ft_add_zero('1', 2);
		(*arr_idx)++;
	}
}

void	ft_add_mod1(char **array, int *arr_idx, int i, char *num)
{
	if (num[i] != '0')
	{
		if (num[i] != '1')
		{
			array[*arr_idx] = ft_add_zero(num[i], 1);
			(*arr_idx)++;
		}
		else
		{
			array[*arr_idx] = ft_create_str(num[i], num[i + 1]);
			(*arr_idx)++;
			num[i + 1] = '0';
		}
	}
}

void	ft_add_mod0(char **array, int *arr_idx, int i, char *num)
{
	int	size;

	size = ft_strlen(num);
	if (size - 1 - i > 0)
	{
		if (num[i] != '0')
		{
			array[*arr_idx] = ft_add_zero(num[i], 0);
			(*arr_idx)++;
		}
		if (num[i] != '0' || num[i - 1] != '0' || num[i - 2] != '0')
		{
			array[*arr_idx] = ft_add_zero('1', size - 1 - i);
			(*arr_idx)++;
		}
	}
	else if (num[i] != '0' || ((i == 0) && num[i + 1] == 0))
	{
		array[*arr_idx] = ft_add_zero(num[i], 0);
		(*arr_idx)++;
	}
}

char	**ft_check_split_num(char **num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!(num)[i])
		{
			ft_free_split_num(num, size);
			return (NULL);
		}
		i++;
	}
	return (num);
}

char	**ft_split(char *num)
{
	char	**array;
	int		i;
	int		size;
	int		arr_idx;

	size = ft_strlen(num);
	array = malloc(sizeof(char *) * (ft_num_size_max(num) + 1));
	if (!array)
		return (NULL);
	i = 0;
	arr_idx = 0;
	while (num[i])
	{
		if ((size - 1 - i) % 3 == 2)
			ft_add_mod2(array, &arr_idx, i, num);
		else if ((size - 1 - i) % 3 == 1)
			ft_add_mod1(array, &arr_idx, i, num);
		else
			ft_add_mod0(array, &arr_idx, i, num);
		i++;
	}
	array[arr_idx] = NULL;
	array = ft_check_split_num(array, arr_idx);
	return (array);
}
