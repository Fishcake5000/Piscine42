/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 10:53:26 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/20 13:50:01 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include "ft_print.h"
#include "ft_file.h"

void	ft_parse_arg(int argc, char **argv, t_hexdump *data, char ***filelist)
{
	if (argc == 1)
	{
		*filelist = NULL;
		return ;
	}
	if (argv[1][0] == '-' && argv[1][1] == 'C' && !argv[1][2])
	{
		data->is_c = 1;
		if (argc == 2)
			*filelist = NULL;
		else
			*filelist = argv + 2;
	}
	else
		*filelist = argv + 1;
}

void	ft_hexdump(t_hexdump *data, char **filelist)
{
	while (*filelist)
	{
		ft_open_valid_file(data, &filelist);
		while (1)
		{
			if (data->file < 0 && data->count)
				break ;
			if (ft_read(data))
				break ;
			if (data->buff_size < 16)
				break ;
			ft_print(data);
			ft_reset_buff(data);
		}
		ft_close_file(*data);
		if (*filelist)
			filelist++;
	}
	ft_print_last_line(data);
}

void	ft_hexdump_stdin(t_hexdump *data)
{
	data->file = 1;
	while (1)
	{
		while (data->buff_size < 16)
		{
			if (ft_read_stdin(data) == 0)
				break ;
		}
		if (data->buff_size < 16)
			break ;
		ft_print(data);
		ft_reset_buff(data);
	}
	ft_print_last_line(data);
}

int	main(int argc, char **argv)
{
	t_hexdump	data;
	char		**filelist;

	if (ft_struct_init(&data))
		return (ft_free_struct(data));
	data.progname = basename(argv[0]);
	ft_parse_arg(argc, argv, &data, &filelist);
	if (filelist)
		ft_hexdump(&data, filelist);
	else
		ft_hexdump_stdin(&data);
	ft_free_struct(data);
	return (0);
}
