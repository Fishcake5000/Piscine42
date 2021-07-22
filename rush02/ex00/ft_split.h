/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:56:04 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/18 17:57:00 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H
# include "ft_split_basic.h"
# include "ft.h"
void	ft_add_mod2(char **array, int *arr_idx, int i, char *num);
void	ft_add_mod1(char **array, int *arr_idx, int i, char *num);
void	ft_add_mod0(char **array, int *arr_idx, int i, char *num);
char	**ft_check_split_num(char **num, int size);
char	**ft_split(char *num);
#endif
