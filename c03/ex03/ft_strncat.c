/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:57:02 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/04 12:47:27 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (dest[len])
		len++;
	i = 0;
	while (src[i] && i < nb)
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[len + i] = 0;
	return (dest);
}
