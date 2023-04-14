/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:21 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/15 15:41:31 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (0);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char	*new_str(int *n, int len, int *index)
{
	char	*rep;

	if (len == 0)
		rep = (char *)malloc(sizeof(char) * len + 2);
	else
		rep = (char *)malloc(sizeof(char) * len + 1);
	if (!rep)
		return (NULL);
	if (*n < 0)
	{
		rep[0] = '-';
		*index += 1;
		if (*n == -2147483648)
		{
			rep[1] = '2';
			*index += 1;
			*n = -147483648;
		}
		*n *= -1;
	}
	return (rep);
}

char	*ft_itoa(int n)
{
	int		longeur;
	int		index;
	char	*rep;

	index = 0;
	longeur = len(n);
	rep = new_str(&n, longeur, &index);
	if (!rep)
		return (NULL);
	if (longeur == 0)
	{
		rep[0] = '0';
		rep[1] = '\0';
		return (rep);
	}
	rep[longeur] = '\0';
	longeur--;
	while (longeur >= index)
	{
		rep[longeur--] = (n % 10) + 48;
		n /= 10;
	}
	return (rep);
}

// int main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// }