/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:35:46 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/09 08:18:28 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_rev_str(char *str, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size - 1 - i)
	{
		temp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = temp;
		i++;
	}
	return (str);
}

int	ft_invalid_base(char *base)
{
	int	i;
	int	j;
	int	size;

	size = ft_strlen(base);
	if (size < 2)
		return (1);
	i = 0;
	while (i < size)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == 127 || base[i] < 32)
			return (1);
		j = 1;
		while (i + j < size)
		{
			if (base[i + j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				size;
	int				i;
	char			str[50];
	unsigned int	to_print;

	if (ft_invalid_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		to_print = -1 * nbr;
	}
	else
		to_print = nbr;
	size = ft_strlen(base);
	i = 0;
	while (to_print)
	{
		str[i] = base[to_print % size];
		i++;
		to_print /= size;
	}
	ft_rev_str(str, i);
	str[i] = 0;
	write(1, str, i);
}
