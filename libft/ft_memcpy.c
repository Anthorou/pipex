/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:23:34 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/14 14:07:16 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*u_dst;
	const unsigned char	*u_src;

	i = 0;
	u_dst = dst;
	u_src = src;
	if (!dst || !src)
		return (dst);
	while (i < n)
	{
		*u_dst = *u_src;
		u_dst++;
		u_src++;
		i++;
	}
	return (dst);
}
