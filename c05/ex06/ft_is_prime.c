/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:36:24 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/06 13:23:57 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	i;
	unsigned int	pos_nbr;

	if (nb <= 3)
		return (nb > 1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	pos_nbr = nb;
	while (i * i <= pos_nbr)
	{
		if (pos_nbr % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
