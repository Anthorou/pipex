/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:46:04 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/15 15:58:32 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rep;
	int		i;

	rep = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!rep)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		rep[i] = (*f)(i, s[i]);
		i++;
	}
	rep[i] = '\0';
	return (rep);
}
