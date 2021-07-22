/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_basic.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:55:42 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/18 17:55:43 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_BASIC_H
# define FT_FILE_BASIC_H
# include <stdlib.h>
# include "ft_helper.h"
# include "ft.h"
t_translation	ft_empty_struct(void);
char			*ft_clean_num(char *buff, int size);
char			*ft_clean_text(char *buff, int size);
#endif
