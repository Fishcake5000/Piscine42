/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:21:16 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/13 17:29:53 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_error(char *error_str, char *filename, char *prog_name)
{
	write(2, prog_name, ft_strlen(prog_name));
	write(2, ": ", 2);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, error_str, ft_strlen(error_str));
	write(2, "\n", 1);
	return (1);
}

int	ft_display_file(char *filename, char *prog_name)
{
	int		file;
	int		byte_count;
	char	buff[1];

	if (!filename[0] || (filename[0] == '-' && filename[1] == 0))
		file = STDIN_FILENO;
	else
		file = open(filename, O_RDONLY);
	if (file < 0)
		return (ft_print_error(strerror(errno), filename, prog_name));
	byte_count = read(file, buff, 1);
	while (byte_count)
	{
		if (byte_count < 0 && file != STDIN_FILENO)
			return (ft_print_error(strerror(errno), filename, prog_name));
		write(1, buff, 1);
		byte_count = read(file, buff, 1);
	}
	if (file > 1)
		close(file);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		ft_display_file("", basename(argv[0]));
	while (i < argc)
	{
		ft_display_file(argv[i], basename(argv[0]));
		i++;
	}
}
