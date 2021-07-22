/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:01:06 by aberger           #+#    #+#             */
/*   Updated: 2021/07/18 18:01:08 by aberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_FILE_H
# define FT_READ_FILE_H
# include <unistd.h>
# include <fcntl.h>
# include "ft.h"
# include "ft_file_basic.h"
int				ft_file_size(char *filename);
char			*ft_load_file(char *filename);
int				ft_count_lines(char *buff);
t_translation	ft_read_line(char *buff, int *index);
t_translation	*ft_parse_file(char *filename);
#endif
