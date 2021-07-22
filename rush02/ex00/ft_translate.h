/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:33:44 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/18 16:33:48 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRANSLATE_H
# define FT_TRANSLATE_H
# include "ft_read_file.h"
# include "ft_split.h"
# include "ft_display.h"
void	ft_free_everything(char **num, char **dict);
int		ft_error(void);
int		translate(char *nb, char *filename);
#endif
