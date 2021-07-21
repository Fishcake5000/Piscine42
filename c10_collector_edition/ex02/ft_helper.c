/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:13:49 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/15 16:13:53 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *nbr)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		res *= 10;
		res += nbr[i] - '0';
		i++;
	}
	if (nbr[i])
		return (-1);
	else
		return (res);
}

char	**ft_init_buff(int size)
{
	int		i;
	char	**buff;

	i = 0;
	buff = malloc(sizeof(char *) * 2);
	if (!buff)
		return (buff);
	buff[0] = malloc(sizeof(char) * size);
	buff[1] = malloc(sizeof(char) * size);
	while (i < size)
	{
		buff[0][i] = 0;
		buff[1][i] = 0;
		i++;
	}
	return (buff);
}

void	ft_swap_buff(char **buff)
{
	char	*temp;

	temp = buff[0];
	buff[0] = buff[1];
	buff[1] = temp;
}

void	ft_free_close(char **buff, int file)
{
	if (!buff)
	{
		free(buff[0]);
		free(buff[1]);
	}
	free(buff);
	if (file > 1)
		close(file);
}
