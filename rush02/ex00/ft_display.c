/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:36:03 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/17 20:07:00 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "ft_display_basic.h"

char	*find_in_dict(char *s, t_translation *dictarr)
{
	int	i;

	i = 0;
	while (dictarr[i].num)
	{
		if (ft_strcmp(s, dictarr[i].num) == 0)
			return (dictarr[i].translation);
		i++;
	}
	return (NULL);
}

char	**translation(char **num, t_translation *dictarr)
{
	int		i;
	int		size;
	char	*text;
	char	**translated;

	size = ft_count_str(num);
	translated = malloc(sizeof(char *) * (size + 1));
	if (!translated)
		return (NULL);
	i = 0;
	while (i < size)
	{
		text = find_in_dict(num[i], dictarr);
		if (text == NULL)
		{
			free(translated);
			return (NULL);
		}
		translated[i] = text;
		i++;
	}
	translated[i] = NULL;
	return (translated);
}

int	affichage(char **num, t_translation *dictarr)
{
	int		i;
	char	**translated;
	int		size;

	i = 0;
	translated = translation(num, dictarr);
	if (!translated)
		return (ft_print_dict_error());
	size = ft_count_str(translated);
	while (i < size)
	{
		ft_putstr(translated[i]);
		if (i + 1 != size)
			ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
	free(translated);
	return (0);
}
