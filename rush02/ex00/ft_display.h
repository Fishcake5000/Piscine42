/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:55:13 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/18 17:55:15 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H
# include <stdlib.h>
# include "ft.h"
# include "ft_display_basic.h"
char	*find_in_dict(char *s, t_translation *dictarr);
char	**translation(char **num, t_translation *dictarr);
int		affichage(char **num, t_translation *dictarr);
#endif
