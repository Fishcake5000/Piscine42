/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_solv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:14:32 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/11 12:41:43 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int	ft_find_zero(int **array, int *pos, int size)
{
	int	i;
	int	j;
	int	inc;

	i = pos[0];
	inc = 1;
	if (pos[0])
		inc = -1;
	while (i < size && i >= 0)
	{
		j = pos[1];
		while (j < size && j >= 0)
		{
			if (array[i][j] == 0)
			{
				pos[0] = i;
				pos[1] = j;
				return (0);
			}
			j += inc;
		}
		i += inc;
	}
	return (1);
}

int	ft_check_count(int *tab, int clue, int size)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] == 0)
		{
			if (max == size)
				return (count == clue);
			return (clue > count && clue <= count + (size - max));
		}
		if (tab[i] > max)
		{
			max = tab[i];
			count++;
		}
		i++;
	}
	return (count == clue);
}

int	ft_check_clues(int **array, int **clues, int *pos, int size)
{
	int	vert[9];
	int	hor[9];
	int	i;
	int	lin;
	int	col;

	i = 0;
	lin = pos[0];
	col = pos[1];
	ft_reset_tab(vert, size);
	ft_reset_tab(hor, size);
	while (i < size)
	{
		vert[i] = array[i][col];
		hor[i] = array[lin][i];
		i++;
	}
	if (!ft_check_count(hor, clues[2][lin], size)
			|| !ft_check_count(vert, clues[0][col], size)
			|| !ft_check_count(ft_rev_tab(vert, size), clues[1][col], size)
			|| !ft_check_count(ft_rev_tab(hor, size), clues[3][lin], size))
		return (0);
	return (1);
}

int	ft_check_rep(int **array, int size, int *pos)
{
	int	i;
	int	col;
	int	lin;
	int	is_in_lin[10];
	int	is_in_col[10];

	i = 0;
	lin = pos[0];
	col = pos[1];
	ft_reset_tab(is_in_lin, size + 1);
	ft_reset_tab(is_in_col, size + 1);
	while (i < size)
	{
		if (is_in_col[array[i][col]] && array[i][col])
			return (0);
		if (is_in_lin[array[lin][i]] && array[lin][i])
			return (0);
		is_in_col[array[i][col]] = 1;
		is_in_lin[array[lin][i]] = 1;
		i++;
	}
	return (1);
}

int	ft_brute_solv(int **array, int **clues, int is_flip, int size)
{
	int	i;
	int	pos[2];

	pos[0] = is_flip * (size - 1);
	pos[1] = is_flip * (size - 1);
	if (ft_find_zero(array, pos, size))
		return (0);
	i = 1;
	while (i <= size)
	{
		array[pos[0]][pos[1]] = i;
		if (ft_check_rep(array, size, pos)
			&& ft_check_clues(array, clues, pos, size)
			&& !ft_brute_solv(array, clues, !is_flip, size))
			return (0);
		i++;
	}
	array[pos[0]][pos[1]] = 0;
	return (1);
}
