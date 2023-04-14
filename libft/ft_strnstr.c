/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:33:21 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/14 16:56:02 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	i;
	unsigned char	y;
	unsigned char	x;

	i = 0;
	y = 0;
	if (needle[i] == '\0' || !haystack || !needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		x = 0;
		if (haystack[i] == needle[x])
		{
			y = i;
			while ((haystack[y] == needle[x]) && (y < len))
			{
				x++;
				y++;
				if (needle[x] == '\0')
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	printf("%s\n", ft_strnstr("AAAA", "AAAA", 4));
// }