/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:19:21 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/18 11:30:58 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_translate.h"

int	ft_print_arg_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_check_num(char **num)
{
	int	i;

	i = 0;
	while (((**num == '0') && *(*num + 1)) || ft_is_whitespace(**num))
		(*num)++;
	if ((*num)[i] == '+')
		(*num)++;
	while ((*num)[i] >= '0' && (*num)[i] <= '9')
		i++;
	return ((*num)[i] != '\0');
}

int	ft_parse_arg(int argc, char **argv, char **num, char **filename)
{
	if (argc == 2)
	{
		*filename = "numbers.dict";
		if (ft_check_num(argv + 1))
			return (1);
		*num = argv[1];
	}
	else
	{
		*filename = argv[1];
		if (ft_check_num(argv + 2))
			return (1);
		*num = argv[2];
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*num;
	char	*filename;

	if (argc < 2 || argc > 3 || ft_parse_arg(argc, argv, &num, &filename))
		return (ft_print_arg_error());
	if (translate(num, filename))
		return (1);
	return (0);
}
