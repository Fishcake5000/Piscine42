/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:13:57 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/15 16:14:00 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPER_H
# define FT_HELPER_H
int		ft_strlen(char *str);
int		ft_atoi(char *nbr);
char	**ft_init_buff(int size);
void	ft_swap_buff(char **buff);
void	ft_free_close(char **buff, int file);
#endif
