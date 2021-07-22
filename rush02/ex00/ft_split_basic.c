/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:01:21 by aberger           #+#    #+#             */
/*   Updated: 2021/07/18 18:01:22 by aberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_helper.h"

int	ft_num_size_max(char *num)
{
	int	size;

	size = ft_strlen(num);
	return (size + size * 2 / 3);
}

char	*ft_add_zero(char c, int num_zero)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (num_zero + 2));
	if (!str)
		return (NULL);
	str[0] = c;
	i = 1;
	while (i <= num_zero)
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_create_str(char c1, char c2)
{
	char	*str;

	str = malloc(sizeof(char) * 3);
	if (!str)
		return (NULL);
	str[0] = c1;
	str[1] = c2;
	str[2] = 0;
	return (str);
}

void	ft_free_split_num(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
