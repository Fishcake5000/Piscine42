/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:43:13 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/13 14:18:32 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(char *file_name)
{
	int		file;
	int		byte_count;
	char	buff[50];

	file = open(file_name, O_RDONLY);
	if (file < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	byte_count = read(file, buff, 50);
	while (byte_count)
	{
		write(1, buff, byte_count);
		byte_count = read(file, buff, 50);
	}
	close(file);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_display_file(argv[1]);
	else if (argc < 2)
		write(2, "File name missing.\n", 19);
	else
		write(2, "Too many arguments.\n", 20);
}
