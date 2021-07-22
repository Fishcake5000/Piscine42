/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:36:50 by ajung             #+#    #+#             */
/*   Updated: 2021/07/21 18:02:42 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int	init_largest(t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_lines)
	{
		j = 0;
		while (j < data->nb_cols)
		{
			if (data->map[i][j] != 0)
			{
				data->largest.col = j;
				data->largest.lin = i;
				data->largest.value = data->map[i][j];
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	solve(t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (++i < data->nb_lines)
	{
		j = 0;
		while (++j < data->nb_cols)
		{
			if (data->map[i][j] > 0)
			{
				data->map[i][j] = min(data->map[i][j - 1],
						data->map[i - 1][j],
						data->map[i - 1][j - 1]) + 1;
			}
			if (data->map[i][j] > data->largest.value)
			{
				data->largest.value = data->map[i][j];
				data->largest.col = j;
				data->largest.lin = i;
			}
		}
	}
	return (0);
}
