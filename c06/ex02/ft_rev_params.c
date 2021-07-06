/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:00:29 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/06 15:06:35 by marnaudy         ###   ########.fr       */
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

int	main(int argc, char**argv)
{
	int	i;

	i = argc - 1;
	while (i)
	{
		ft_print_param(argv[i]);
		i--;
	}
}
