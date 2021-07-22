/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:33:44 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/17 23:33:46 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_basic.h"
#include "ft_data_helper.h"

void	ft_print_count(t_hexdump data)
{
	char			*base;
	char			str[7];
	int				i;
	unsigned int	nb;

	base = "0123456789abcdef";
	if (data.is_c)
		write(1, base + ((data.count / 268435456) % 16), 1);
	i = 6;
	nb = data.count;
	while (i >= 0)
	{
		str[i] = base[nb % 16];
		nb /= 16;
		i--;
	}
	write(1, str, 7);
}

void	ft_print_hex(t_hexdump data)
{
	int	i;

	i = 0;
	while (i < data.buff_size)
	{
		write(1, " ", 1);
		if (i % 8 == 0 && data.is_c)
			write(1, " ", 1);
		ft_char_to_hex(data.buff[i]);
		i++;
	}
	while (i < 16)
	{
		write(1, "   ", 3);
		if (i % 8 == 0 && data.is_c)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_buff(t_hexdump data)
{
	int	i;

	if (!data.is_c)
		return ;
	write(1, "  |", 3);
	i = 0;
	while (i < data.buff_size)
	{
		if (ft_is_printable(data.buff[i]))
			write(1, data.buff + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
}

void	ft_print(t_hexdump *data)
{
	if (ft_ident_buff(*data) && data->prev_same)
	{
		ft_increase_count(data);
		return ;
	}
	if (ft_ident_buff(*data))
		write(1, "*", 1);
	else
	{
		ft_print_count(*data);
		if (data->buff_size)
		{
			ft_print_hex(*data);
			ft_print_buff(*data);
		}
	}
	write(1, "\n", 1);
	ft_increase_count(data);
}

void	ft_print_last_line(t_hexdump *data)
{
	if (data->buff_size)
		ft_print(data);
	if (data->count)
	{
		ft_print_count(*data);
		write(1, "\n", 1);
	}
}
