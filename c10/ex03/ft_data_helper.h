/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_helper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:33:09 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/17 23:33:11 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_HELPER_H
# define FT_DATA_HELPER_H
# include <stdlib.h>
# include "ft_print_basic.h"
int		ft_free_struct(t_hexdump data);
int		ft_ident_buff(t_hexdump data);
void	ft_increase_count(t_hexdump *data);
void	ft_reset_buff(t_hexdump *data);
int		ft_struct_init(t_hexdump *data);
#endif
