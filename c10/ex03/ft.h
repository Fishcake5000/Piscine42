/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:32:51 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/17 23:32:55 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
typedef struct s_hexdump
{
	char			*old_buff;
	char			*buff;
	char			*progname;
	char			*filename;
	int				file;
	int				prev_same;
	int				buff_size;
	unsigned int	count;
	int				is_c;
}	t_hexdump;
#endif
