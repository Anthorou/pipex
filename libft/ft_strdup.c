/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:20:53 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/14 17:24:52 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*rep;
	char	*check;

	i = 0;
	if (!s1)
		return ((char *)s1);
	while (s1[i] != '\0')
		i++;
	check = ((rep = (char *)malloc(1 * (i + 1))));
	if (!check)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		rep[i] = s1[i];
		i++;
	}
	rep[i] = '\0';
	return (rep);
}
