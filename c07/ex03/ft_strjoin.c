/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:22:54 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/11 15:54:38 by marnaudy         ###   ########.fr       */
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

void	ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = src[i];
}

int	ft_count_chars(int size, char **strs, char *sep)
{
	int	nb_char;
	int	i;

	nb_char = 0;
	i = 0;
	while (i < size)
	{
		nb_char += ft_strlen(strs[i]);
		i++;
	}
	if (size > 0)
		nb_char += (size - 1) * ft_strlen(sep);
	return (nb_char);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		nb_char;
	char	*str;

	nb_char = ft_count_chars(size, strs, sep);
	str = malloc(sizeof(char) * (nb_char + 1));
	if (!str)
		return (NULL);
	str[0] = 0;
	if (size <= 0)
		return (str);
	ft_strcat(str, strs[0]);
	i = 1;
	while (i < size)
	{
		ft_strcat(str, sep);
		ft_strcat(str, strs[i]);
		i++;
	}
	return (str);
}
