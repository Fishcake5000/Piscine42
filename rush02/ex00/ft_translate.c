/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:36:35 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/17 19:56:38 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_file.h"
#include "ft_split.h"
#include "ft_display.h"

void	ft_free_everything(char **num, t_translation *dict)
{
	int	i;

	i = 0;
	if (num)
	{
		while (num[i])
		{
			free(num[i]);
			i++;
		}
	}
	i = 0;
	if (dict)
	{
		while (dict[i].num || dict[i].translation)
		{
			free(dict[i].num);
			free(dict[i].translation);
			i++;
		}
	}
	free(num);
	free(dict);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	translate(char *nb, char *filename)
{
	t_translation	*dict;
	char			**split;

	split = ft_split(nb);
	dict = ft_parse_file(filename);
	if (!split)
	{
		ft_free_everything(split, dict);
		return (ft_error());
	}
	if (!dict)
	{
		ft_free_everything(split, dict);
		return (ft_print_dict_error());
	}
	if (affichage(split, dict))
	{
		ft_free_everything(split, dict);
		return (1);
	}
	ft_free_everything(split, dict);
	return (0);
}
