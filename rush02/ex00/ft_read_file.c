/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:37:21 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/18 09:47:36 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft.h"
#include "ft_file_basic.h"

int	ft_file_size(char *filename)
{
	int		size;
	int		buff_size;
	int		file_d;
	char	buff[100];

	size = 0;
	file_d = open(filename, O_RDONLY);
	if (file_d < 0)
		return (-1);
	buff_size = read(file_d, buff, 100);
	size += buff_size;
	while (buff_size == 100 || buff_size < 0)
	{
		if (buff_size < 0)
		{
			close(file_d);
			return (-1);
		}
		buff_size = read(file_d, buff, 100);
		size += buff_size;
	}
	close(file_d);
	return (size);
}

char	*ft_load_file(char *filename)
{
	int		size;
	int		file_d;
	char	*buff;
	int		buff_size;

	size = ft_file_size(filename);
	if (size <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (size + 1));
	if (!buff)
		return (NULL);
	file_d = open(filename, O_RDONLY);
	buff_size = read(file_d, buff, size);
	close(file_d);
	if (buff_size < 0)
	{
		free(buff);
		return (NULL);
	}
	buff[size] = 0;
	return (buff);
}

int	ft_count_lines(char *buff)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] != '\n')
		{
			count++;
			while (buff[i] && buff[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return (count);
}

t_translation	ft_read_line(char *buff, int *index)
{
	int				i;
	t_translation	res;

	while (buff[*index] == '\n')
		(*index)++;
	i = 0;
	while (buff[*index + i] != ':' && buff[*index + i])
	{
		if (buff[*index + i] == '\n')
			return (ft_empty_struct());
		i++;
	}
	res.num = ft_clean_num(buff + *index, i);
	(*index) += i;
	if (buff[*index])
		(*index)++;
	i = 0;
	while (buff[*index + i] != '\n' && buff[*index + i])
		i++;
	res.translation = ft_clean_text(buff + *index, i);
	(*index) += i;
	return (res);
}

t_translation	*ft_parse_file(char *filename)
{
	int				i;
	int				nb_entries;
	int				buff_index;
	char			*buff;
	t_translation	*tran_arr;

	buff = ft_load_file(filename);
	if (!buff)
		return (NULL);
	nb_entries = ft_count_lines(buff);
	tran_arr = malloc(sizeof(t_translation) * (nb_entries + 1));
	i = -1;
	buff_index = 0;
	if (!tran_arr)
		return (NULL);
	while (++i < nb_entries && buff[buff_index])
	{
		tran_arr[i] = ft_read_line(buff, &buff_index);
		if (!(tran_arr[i].num || tran_arr[i].translation || !(i++)))
			break ;
	}
	tran_arr[i] = ft_empty_struct();
	free(buff);
	return (tran_arr);
}
