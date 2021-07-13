/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:42:09 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/13 11:47:13 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

int	ft_is_in_set(char c, char *charset)
{
	int	i;
	int	set_size;

	i = 0;
	set_size = ft_strlen(charset);
	while (i < set_size)
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_str(char *str, char *sep)
{
	int	i;
	int	nb_str;

	i = 0;
	nb_str = 0;
	while (str[i])
	{
		if (!ft_is_in_set(str[i], sep))
		{
			nb_str++;
			while (!ft_is_in_set(str[i], sep) && str[i])
				i++;
		}
		else
			i++;
	}
	return (nb_str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		arr_index;
	char	**array;

	array = malloc(sizeof(char *) * (ft_count_str(str, charset) + 1));
	i = 0;
	arr_index = 0;
	while (str[i])
	{
		if (!ft_is_in_set(str[i], charset))
		{
			j = 1;
			while (!ft_is_in_set(str[i + j], charset) && str[i + j])
				j++;
			array[arr_index] = malloc(sizeof(char) * (j + 1));
			ft_strlcpy(array[arr_index], str + i, j);
			arr_index++;
			i += j - 1;
		}
		i++;
	}
	array[arr_index] = 0;
	return (array);
}
