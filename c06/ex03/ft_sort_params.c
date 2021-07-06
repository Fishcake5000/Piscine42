/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:07:58 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/06 15:30:53 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_param(char *param)
{
	int	i;

	i = 0;
	while (param[i])
	{
		write(1, param + i, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i])
		i++;
	return (str1[i] > str2[i]);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = argc;
	while (i > 1)
	{
		j = 1;
		while (j + 1 < argc)
		{
			if (ft_strcmp(argv[j], argv[j + 1]))
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
	while (i < argc)
	{
		ft_print_param(argv[i]);
		i++;
	}
}
