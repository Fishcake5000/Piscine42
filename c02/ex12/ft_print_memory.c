/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:44:26 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/06 17:11:02 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_ptr_to_str(char *str, void *ptr)
{
	int						i;
	unsigned long long int	nbr;

	nbr = (unsigned long long int)ptr;
	str[16] = 0;
	i = 15;
	while (i >= 0)
	{
		if (nbr % 16 > 9)
			str[i] = nbr % 16 - 10 + 'a';
		else
			str[i] = nbr % 16 + '0';
		i--;
		nbr /= 16;
	}
}

void	ft_char_to_hex(char *str, char chr)
{
	unsigned char	us_chr;
	char			*base;

	base = "0123456789abcdef";
	us_chr = chr;
	str[0] = base[us_chr / 16];
	str[1] = base[us_chr % 16];
	str[2] = ' ';
	str[3] = 0;
}

void	ft_print_str(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] < 32 || str[i] == 127)
			write(1, ".", 1);
		else
			write(1, str + i, 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char				str[20];
	unsigned int		i;

	ft_ptr_to_str(str, addr);
	write(1, str, 16);
	write(1, ": ", 2);
	i = 0;
	while (i < 16 && i < size)
	{
		ft_char_to_hex(str, *(char *)(addr + i));
		write(1, str, 2 + i % 2);
		i++;
	}
	while (i < 16)
	{
		write(1, "   ", 2 + i % 2);
		i++;
	}
	if (size < 16)
		i = size;
	ft_print_str(addr, i);
	write(1, "\n", 1);
	if (size > 16)
		ft_print_memory(addr + 16, size - 16);
	return (addr);
}

int	main(void)
{
	ft_print_memory("Bonjour, je m'appelle Maxime, cet exercice a ete tres drole", 100);
}
