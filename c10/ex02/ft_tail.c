/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:35:18 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/15 21:09:30 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_display.h"
#include "ft_helper.h"

int	ft_parse_arg(int *start, char **argv)
{
	int	num;

	if (argv[1][0] != '-' && argv[1][1] != 'c')
		return (-2);
	if (argv[1][2])
	{
		num = ft_atoi(argv[1] + 2);
		*start = 2;
	}
	else
	{
		num = ft_atoi(argv[2]);
		*start = 3;
	}
	return (num);
}

void	ft_put_buffer(char *buff, int size, int buff_index, int full_buff)
{
	int	i;

	i = buff_index;
	while (i < size && full_buff)
	{
		write(1, buff + i, 1);
		i++;
	}
	i = 0;
	while (i < buff_index)
	{
		write(1, buff + i, 1);
		i++;
	}
}

int	ft_display_stdin(int size)
{
	int		byte_count;
	char	*buff;
	int		buff_index;
	int		full_buff;

	buff = malloc(sizeof(char) * size);
	if (!buff)
		return (1);
	buff_index = 0;
	byte_count = read(STDIN_FILENO, buff, size);
	full_buff = 0;
	buff_index = (buff_index + byte_count) % size;
	while (byte_count > 0)
	{
		byte_count = read(STDIN_FILENO, buff + buff_index, size - buff_index);
		if (buff_index + byte_count >= size)
			full_buff = 1;
		buff_index = (buff_index + byte_count) % size;
	}
	ft_put_buffer(buff, size, buff_index, full_buff);
	free(buff);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	nb;
	int	is_multi;
	int	start;
	int	have_printed;

	nb = ft_parse_arg(&start, argv);
	i = start;
	have_printed = 0;
	if (nb == -1)
		return (ft_print_offset_error(i - 1, argv, basename(argv[0])));
	is_multi = start < argc - 1;
	if (start == argc && nb)
		ft_display_stdin(nb);
	while (i < argc && nb)
	{
		if (!ft_display_file(argv[i], basename(argv[0]), nb,
				is_multi + have_printed))
			have_printed = 1;
		i++;
	}
	return (0);
}
