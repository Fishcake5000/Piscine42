/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:33:55 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/17 23:33:57 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_error(t_hexdump data)
{
	char	*error;

	error = strerror(errno);
	write(2, data.progname, ft_strlen(data.progname));
	write(2, ": ", 2);
	write(2, data.filename, ft_strlen(data.filename));
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	return (1);
}

void	ft_char_to_hex(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, base + (c / 16), 1);
	write(1, base + (c % 16), 1);
}

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}
