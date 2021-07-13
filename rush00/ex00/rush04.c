/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:40:50 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/03 14:40:58 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_first_line(int x)
{
	int	i;

	i = x - 2;
	ft_putchar('A');
	while (i > 0)
	{
		ft_putchar('B');
		i--;
	}
	if (x >= 2)
		ft_putchar('C');
	ft_putchar('\n');
}

void	ft_put_middle_line(int x)
{
	int	i;

	i = x - 2;
	ft_putchar('B');
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	if (x >= 2)
		ft_putchar('B');
	ft_putchar('\n');
}

void	ft_put_last_line(int x)
{
	int	i;

	i = x - 2;
	ft_putchar('C');
	while (i > 0)
	{
		ft_putchar('B');
		i--;
	}
	if (x >= 2)
		ft_putchar('A');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = y - 2;
	if (x <= 0 || y <= 0)
		return ;
	ft_put_first_line(x);
	while (i > 0)
	{
		ft_put_middle_line(x);
		i--;
	}
	if (y >= 2)
		ft_put_last_line(x);
}
