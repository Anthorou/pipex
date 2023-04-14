/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:51:38 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/14 14:30:46 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*u_dst;
	char	*u_src;

	u_dst = (char *)dst;
	u_src = (char *)src;
	i = 0;
	if (!dst || !src)
		return (dst);
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len-- > 0)
			u_dst[len] = u_src[len];
	}
	else
	{
		while (i < len)
		{
			u_dst[i] = u_src[i];
			i++;
		}
	}
	return (dst);
}
