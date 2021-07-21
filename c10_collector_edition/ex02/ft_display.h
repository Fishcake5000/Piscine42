/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:13:39 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/15 21:05:02 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H
void	ft_display_header(char *filename, int is_multi);
void	ft_display_buff(char **buff, int new_size, int size);
int		ft_print_error(char *filename, char *prog_name, char **buff, int file);
int		ft_print_offset_error(int i, char **argv, char *prog_name);
int		ft_display_file(char *filename, char *prog_name, int size, int header);
#endif
