/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_basic.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:34:00 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/17 23:34:02 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_BASIC_H
# define FT_PRINT_BASIC_H
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include "ft.h"
int		ft_strlen(char *str);
int		ft_print_error(t_hexdump data);
void	ft_char_to_hex(unsigned char c);
int		ft_is_printable(char c);
#endif
