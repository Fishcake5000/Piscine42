/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:45:46 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/06 14:29:51 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_solution(int *sol)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = sol[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_is_valid(int *pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = i + 1;
		while (i + j < 10)
		{
			if (pos[i + j] == pos[i] + j || pos[i + j] == pos[i] - j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_find_next_solution(int *tab)
{
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		tab[i] = 0;
		i++;
	}
	i = 0;
	while (ft_find_next_solution(tab))
	{
		ft_print_solution(tab);
		i++;
	}
	return (i);
}

int	main(void)
{
	ft_ten_queens_puzzle();
}
