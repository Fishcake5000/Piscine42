/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:33:48 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/17 23:33:50 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include "ft_print_basic.h"
# include "ft_data_helper.h"
void	ft_print_count(t_hexdump data);
void	ft_print_hex(t_hexdump data);
void	ft_print_buff(t_hexdump data);
void	ft_print(t_hexdump *data);
void	ft_print_last_line(t_hexdump *data);
#endif
