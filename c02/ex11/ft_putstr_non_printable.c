/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:18:36 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/05 19:50:34 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_hex(unsigned char *dest, unsigned char chr)
{
	char	*base;

	base = "0123456789abcdef";
	dest[0] = '\\';
	dest[1] = base[chr / 16];
	dest[2] = base[chr % 16];
	dest[3] = 0;
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	chr;
	unsigned char	hex[4];

	i = 0;
	while (str[i])
	{
		chr = str[i];
		if (chr < 32 || chr >= 127)
		{
			ft_hex(hex, chr);
			write(1, hex, 3);
		}
		else
			write(1, &chr, 1);
		i++;
	}
}
