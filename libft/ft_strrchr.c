/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:06 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/14 14:16:27 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		x;
	char	*ptr;
	char	cherche;

	cherche = c;
	if (cherche == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&s[i]);
	}
	x = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cherche)
		{
			ptr = (char *)&s[i];
			x++;
		}
		i++;
	}
	if (x > 0)
		return (ptr);
	return (NULL);
}

// int main(void)
// {
// 	char *str = ft_strrchr("bonjour", 's');
// 	printf("%s\n", str);
// }
