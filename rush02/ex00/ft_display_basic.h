/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_basic.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:11:36 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/18 16:34:07 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_BASIC_H
# define FT_DISPLAY_BASIC_H
# include <unistd.h>
void	ft_putstr(char *str);
int		ft_count_str(char **str_arr);
int		ft_strcmp(char *str1, char *str2);
int		ft_print_dict_error(void);
#endif
