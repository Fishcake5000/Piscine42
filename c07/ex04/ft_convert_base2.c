/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:11:46 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/09 13:17:18 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (1);
		j = 1;
		while (i + j < size)
		{
			if (base[i] == base[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_char_to_int(char c, char *base)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(base);
	while (i < size)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_len_in_base(int nbr, char *base)
{
	int				nb_char;
	int				size;
	unsigned int	pos_nbr;

	size = ft_strlen(base);
	pos_nbr = nbr;
	nb_char = 1;
	if (nbr < 0)
	{
		pos_nbr = nbr * -1;
		nb_char++;
	}
	pos_nbr /= size;
	while (pos_nbr)
	{
		pos_nbr /= size;
		nb_char++;
	}
	return (nb_char);
}
