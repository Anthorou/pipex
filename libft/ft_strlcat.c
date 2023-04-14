/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:02:16 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/14 16:30:08 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	slength;
	size_t	dlength;

	j = 0;
	i = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	if (!dst || !src)
		return (0);
	while (dst[j] != '\0')
		j++;
	dlength = j;
	slength = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dlength)
		return (slength + dstsize);
	while (src[i] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlength + slength);
}

// #include <string.h>

// int main(void)
// {
// 	char *dest = (char *)malloc(sizeof(*dest) * 15);
// 	dest = memset(dest, 'C', 5);
// 	// char dest[0xF00] = "there is no stars in the sky";
// 	// char src[] = "123";
// 	printf("%zu\n", ft_strlcat(dest, "AAAAAAAAA", -1));
// 	printf("%s\n", dest);
// 	printf("\n");
// 	// char dest2[0xF00] = "there is no stars in the sky";
// 	// char src2[] = "123";
// 	// char *dest2 = (char *)malloc(sizeof(*dest) * 15);
// 	// dest2 = memset(dest, 'r', 14);
// 	// printf("%zu\n", strlcat(dest2, "lorem ipsum dolor sit amet", -1));
// 	// printf("%s\n", dest2);
// }
