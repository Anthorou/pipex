/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:32:04 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/14 16:31:09 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	i;
	char			*ptr;
	unsigned char	cherche;

	ptr = (char *)s;
	cherche = c;
	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if ((unsigned char)ptr[i] == cherche)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char *str = ft_memchr("0x7ffee734a7c0", '\347', 40);
// 	printf("%s\n", str);
// }
