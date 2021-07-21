/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:33:27 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/20 13:50:13 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_print_basic.h"

int	ft_open_file(t_hexdump *data, char *new_filename)
{
	data->filename = new_filename;
	data->file = open(data->filename, O_RDONLY);
	if (data->file < 0)
		return (ft_print_error(*data));
	return (0);
}

void	ft_close_file(t_hexdump data)
{
	if (data.file > 1)
		close(data.file);
}

int	ft_read(t_hexdump *data)
{
	int	temp;

	temp = read(data->file, data->buff + data->buff_size, 16 - data->buff_size);
	if (temp < 0)
		return (ft_print_error(*data));
	data->buff_size += temp;
	return (0);
}

int	ft_read_stdin(t_hexdump *data)
{
	int	temp;

	temp = read(STDIN_FILENO, data->buff + data->buff_size,
			16 - data->buff_size);
	data->buff_size += temp;
	return (temp);
}

void	ft_open_valid_file(t_hexdump *data, char ***filelist)
{
	while (**filelist && ft_open_file(data, **filelist))
		(*filelist)++;
}
