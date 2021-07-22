/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:33:03 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/17 23:33:06 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_print_basic.h"

int	ft_free_struct(t_hexdump data)
{
	free(data.old_buff);
	free(data.buff);
	return (1);
}

int	ft_ident_buff(t_hexdump data)
{
	int	i;

	i = 0;
	while (i < 16 && data.buff[i] == data.old_buff[i])
		i++;
	return (i == 16);
}

void	ft_increase_count(t_hexdump *data)
{
	data->count += data->buff_size;
}

void	ft_reset_buff(t_hexdump *data)
{
	char	*temp;

	data->prev_same = ft_ident_buff(*data);
	temp = data->old_buff;
	data->old_buff = data->buff;
	data->buff = temp;
	data->buff_size = 0;
}

int	ft_struct_init(t_hexdump *data)
{
	int	i;

	data->old_buff = malloc(16);
	data->buff = malloc(16);
	if (!data->old_buff || !data->buff)
		return (ft_print_error(*data));
	i = 0;
	while (i < 16)
	{
		data->old_buff[i] = 0;
		i++;
	}
	data->is_c = 0;
	data->file = 0;
	data->prev_same = 0;
	data->buff_size = 0;
	data->count = 0;
	return (0);
}
