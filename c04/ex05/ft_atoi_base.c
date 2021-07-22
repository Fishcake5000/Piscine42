/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:09:45 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/09 08:31:13 by marnaudy         ###   ########.fr       */
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
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] == 127)
			return (1);
		j = 1;
		while (i + j < size)
		{
			if (base[i] == base [i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_conv_base(char c, char *base)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(base);
	while (i < size && base[i] != c)
		i++;
	return (i);
}

int	ft_read_nb(char *str, char *base, int last_index, int is_negative)
{
	int	nb;
	int	multiplier;
	int	size;

	multiplier = 1;
	if (is_negative)
		multiplier = -1;
	nb = 0;
	size = ft_strlen(base);
	while (ft_conv_base(str[last_index], base) != size)
	{
		nb += ft_conv_base(str[last_index], base) * multiplier;
		last_index--;
		multiplier *= size;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb_minus;
	int	size;

	if (ft_invalid_base(base))
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	nb_minus = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			nb_minus++;
		i++;
	}
	size = ft_strlen(base);
	while (ft_conv_base(str[i], base) != size)
		i++;
	if (i)
		i--;
	return (ft_read_nb(str, base, i, nb_minus % 2));
}
