/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:23:15 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/11 12:41:18 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include "brute_solv.h"
#include "io_functions.h"

int	main(int argc, char **argv)
{
	int	**clues;
	int	**values;
	int	size;
	int	str_size;

	if (argc != 2)
		return (ft_error());
	str_size = ft_strlen(argv[1]);
	size = (str_size + 1) / 8;
	clues = malloc(sizeof(int *) * 4);
	values = malloc(sizeof(int *) * size);
	if (!clues || !values || size < 4
		|| ft_parse(argv[1], clues, str_size, size))
		return (ft_error());
	if (ft_arr_init(values, size))
		return (ft_error());
	if (ft_brute_solv(values, clues, 0, size))
		return (ft_error());
	ft_print(values, size);
}
