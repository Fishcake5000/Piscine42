/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:27:50 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/09 14:09:08 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str);
int	ft_invalid_base(char *base);
int	ft_char_to_int(char c, char *base);
int	ft_len_in_base(int nbr, char *base);

int	ft_atoi_base(char *nbr, char *base, int size)
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
	while (ft_char_to_int(nbr[i], base) >= 0)
	{
		res *= size;
		res += ft_char_to_int(nbr[i], base);
		i++;
	}
	if (nb_minus % 2)
		return (res * -1);
	return (res);
}

void	ft_int_to_str(int nbr, char *base, char *dest)
{
	int				base_size;
	int				dest_size;
	int				i;
	unsigned int	pos_nbr;

	base_size = ft_strlen(base);
	dest_size = ft_len_in_base(nbr, base);
	dest[dest_size] = 0;
	i = dest_size - 1;
	pos_nbr = nbr;
	if (nbr < 0)
	{
		dest[0] = '-';
		pos_nbr = nbr * -1;
	}
	if (pos_nbr == 0)
		dest[0] = base[0];
	while (pos_nbr)
	{
		dest[i] = base[pos_nbr % base_size];
		pos_nbr /= base_size;
		i--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*str;

	if (ft_invalid_base(base_from) || ft_invalid_base(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from, ft_strlen(base_from));
	str = malloc(sizeof(char) * (ft_len_in_base(num, base_to) + 1));
	ft_int_to_str(num, base_to, str);
	return (str);
}
