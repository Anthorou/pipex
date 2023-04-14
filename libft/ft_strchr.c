/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:27:42 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/14 14:36:12 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cherche;

	cherche = c;
	if (!s)
		return ((char *)s);
	while (*s != '\0')
	{
		if (*s == cherche)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && cherche == '\0')
		return ((char *)s);
	return (NULL);
}

// int main(void)
// {
// 	char *str = ft_strchr("teste", '\0');
// 	printf("%s\n", str);
// }
