/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:55:31 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/18 17:55:34 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_helper.h"
#include "ft.h"

t_translation	ft_empty_struct(void)
{
	t_translation	empty;

	empty.num = NULL;
	empty.translation = NULL;
	return (empty);
}

char	*ft_clean_num(char *buff, int size)
{
	int		i;
	int		j;
	char	*num;

	num = malloc(sizeof(char) * (size + 1));
	if (!num)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_is_whitespace(buff[i]))
		i++;
	if (buff[i] == '+' || buff[i] == '-')
	{
		if (buff[i] == '-')
		{
			num[j] = '-';
			j++;
		}
		i++;
	}
	while (buff[i] >= '0' && buff[i] <= '9')
		num[j++] = buff[i++];
	num[j] = 0;
	return (num);
}

char	*ft_clean_text(char *buff, int size)
{
	int		i;
	int		j;
	char	*text;

	if (size <= 0)
		return (NULL);
	text = malloc(sizeof(char) * (size + 1));
	if (!text)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size && ft_is_whitespace(buff[i]))
		i++;
	while (size && ft_is_whitespace(buff[size - 1]))
		size--;
	while (i < size)
	{
		text[j] = buff[i];
		j++;
		i++;
	}
	text[j] = 0;
	return (text);
}
