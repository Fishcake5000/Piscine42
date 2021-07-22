/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:33:32 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/17 23:33:34 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H
# include <fcntl.h>
# include "ft_print_basic.h"
int		ft_open_file(t_hexdump *data, char *new_filename);
void	ft_close_file(t_hexdump data);
int		ft_read(t_hexdump *data);
int		ft_read_stdin(t_hexdump *data);
void	ft_open_valid_file(t_hexdump *data, char ***filelist);
#endif
