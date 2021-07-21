/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:13:23 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/15 21:10:09 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "ft_helper.h"

void	ft_display_header(char *filename, int new_line)
{
	if (new_line == 2)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	write(1, filename, ft_strlen(filename));
	write(1, " <==\n", 5);
}

void	ft_display_buff(char **buff, int new_size, int size, int multi_loop)
{
	if (multi_loop)
		write(1, buff[0] + new_size, size - new_size);
	write(1, buff[1], new_size);
}

int	ft_print_error(char *filename, char *prog_name, char **buff, int file)
{
	write(2, prog_name, ft_strlen(prog_name));
	write(2, ": ", 2);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	ft_free_close(buff, file);
	return (1);
}

int	ft_print_offset_error(int i, char **argv, char *prog_name)
{
	char	*str;

	str = argv[i] + (i % 2) * 2;
	write(2, prog_name, ft_strlen(prog_name));
	write(2, ": ", 2);
	write(2, "illegal offset -- ", 18);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}

int	ft_display_file(char *filename, char *prog_name, int size, int header)
{
	int		file;
	int		byte_count;
	char	**buff;
	int		multi_loop;

	buff = ft_init_buff(size);
	file = open(filename, O_RDONLY);
	if (!buff || !buff[0] || !buff[1] || file < 0)
		return (ft_print_error(filename, prog_name, buff, file));
	byte_count = read(file, buff[1], size);
	multi_loop = 0;
	while (byte_count == size || byte_count < 0)
	{
		if (byte_count < 0)
			return (ft_print_error(filename, prog_name, buff, file));
		ft_swap_buff(buff);
		byte_count = read(file, buff[1], size);
		multi_loop = 1;
	}
	if (header)
		ft_display_header(filename, header);
	ft_display_buff(buff, byte_count, size, multi_loop);
	ft_free_close(buff, file);
	return (0);
}
