/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_basic.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:01:29 by aberger           #+#    #+#             */
/*   Updated: 2021/07/18 18:01:32 by aberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_BASIC_H
# define FT_SPLIT_BASIC_H
# include <stdlib.h>
# include "ft_helper.h"
int		ft_num_size_max(char *num);
char	*ft_add_zero(char c, int num_zero);
char	*ft_create_str(char c1, char c2);
void	ft_free_split_num(char **array, int size);
#endif
