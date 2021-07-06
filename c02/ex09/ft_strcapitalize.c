/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:00:52 by marnaudy          #+#    #+#             */
/*   Updated: 2021/07/04 14:44:20 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alphanum(char c)
{
	int	is_alpha;

	is_alpha = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
	return (is_alpha || (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	if (str[0] == 0)
		return (str);
	i = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && !ft_is_alphanum(str[i - 1]))
			str[i] -= 32;
		if (str[i] >= 'A' && str[i] <= 'Z' && ft_is_alphanum(str[i - 1]))
			str[i] += 32;
		i++;
	}
	return (str);
}
