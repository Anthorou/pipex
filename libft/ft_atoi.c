/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:57:35 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/16 13:49:35 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		c;
	long	rep;

	rep = 0;
	c = 1;
	i = 0;
	if (!str)
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			c *= -1;
	if (str[i] < 48 || str[i] > 57)
		return (0);
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
	{
		rep *= 10;
		rep += str[i] - 48;
		i++;
	}
	return (rep * c);
}
