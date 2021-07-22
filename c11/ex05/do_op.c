/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:36:29 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/14 12:22:28 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_operations.h"

typedef int(*t_operationft)(int, int);
enum	e_operator
{
	plus,
	minus,
	times,
	divide,
	modulo,
	unknown
};

int	ft_atoi(char *nbr)
{
	int	res;
	int	i;
	int	nb_minus;

	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	nb_minus = 0;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			nb_minus++;
		i++;
	}
	res = 0;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		res *= 10;
		res += nbr[i] - '0';
		i++;
	}
	if (nb_minus % 2)
		return (res * -1);
	return (res);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		nbr *= -1;
	}
	if (nbr / 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	ft_find_operator(t_operationft *tab, char op)
{
	tab[plus] = &ft_plus;
	tab[minus] = &ft_minus;
	tab[times] = &ft_times;
	tab[divide] = &ft_divide;
	tab[modulo] = &ft_modulo;
	if (op == '+')
		return (plus);
	else if (op == '-')
		return (minus);
	else if (op == '*')
		return (times);
	else if (op == '/')
		return (divide);
	else if (op == '%')
		return (modulo);
	else
		return (unknown);
}

void	ft_do_op(int n1, int n2, char op)
{
	t_operationft	tab[5];
	enum e_operator	operator;

	operator = ft_find_operator(tab, op);
	if (n2 == 0 && operator == divide)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	if (n2 == 0 && operator == modulo)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	if (operator == unknown)
		write(1, "0", 1);
	else
		ft_putnbr(tab[operator](n1, n2));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	n1;
	int	n2;

	if (argc != 4)
		return (1);
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	if (!argv[2][0] || argv[2][1])
		write(1, "0\n", 2);
	else
		ft_do_op(n1, n2, argv[2][0]);
}
