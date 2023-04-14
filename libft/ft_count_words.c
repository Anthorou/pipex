/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:16:00 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/14 11:23:38 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *str, char c)
{
	int	i;
	int	rep;

	i = 0;
	rep = 0;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c && i != 0)
			rep++;
		i++;
	}
	rep += (str[i - 1] != c);
	return (rep);
}
