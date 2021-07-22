/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:33:28 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/05 14:50:54 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_read_nb(char *str, int last_index, int is_negative)
{
	int	nb;
	int	multiplier;

	multiplier = 1;
	if (is_negative)
		multiplier *= -1;
	nb = 0;
	while (str[last_index] >= '0' && str[last_index] <= '9')
	{
		nb += (str[last_index] - '0') * multiplier;
		last_index--;
		multiplier *= 10;
	}
	return (nb);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb_minus;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	nb_minus = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nb_minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	return (ft_read_nb(str, i, nb_minus % 2));
}
