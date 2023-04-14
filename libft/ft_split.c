/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:45:02 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/12 14:10:00 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	string_count(char *str, char charset)
{
	int	i;
	int	rep;

	i = 0;
	rep = 0;
	while (str[i] != '\0')
	{
		while ((str[i] != '\0') && (check_sep(str[i], charset)))
			i++;
		if (str[i] != '\0')
			rep++;
		while ((str[i] != '\0') && (!check_sep(str[i], charset)))
			i++;
	}
	return (rep);
}

static char	*making_string(char *str, char charset)
{
	int		i;
	int		x;
	char	*string;

	i = 0;
	x = 0;
	while ((check_sep(str[i], charset) != 1) && (str[i] != '\0'))
		i++;
	string = (char *)malloc((sizeof(char) * i) + 1);
	if (!string)
		return (0);
	while (x < i)
	{
		string[x] = str[x];
		x++;
	}
	string[x] = '\0';
	return (string);
}

static void	*ft_free(char **rep, int i)
{
	int	j;

	j = 0;
	if (rep)
	{
		while (j < i)
		{
			if (rep[j])
				free(rep[j]);
			j++;
		}
		free(rep);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**rep;
	int		i;

	rep = (char **)malloc(sizeof(char *) * (string_count((char *)s, c) + 1));
	if (!rep)
		return (NULL);
	if (!s)
		return (rep);
	i = 0;
	while (*s != '\0')
	{
		while ((*s != '\0') && (check_sep(*s, c)))
			s++;
		if (*s != '\0')
		{
			rep[i] = making_string((char *)s, c);
			if (rep[i] == 0)
				return (ft_free(rep, i));
			i++;
		}
		while ((*s != '\0') && (!check_sep(*s, c)))
			s++;
	}
	rep[i] = NULL;
	return (rep);
}

// int main(void)
// {
// 	int i = 0;
// 	char **tabstr = ft_split("hello!", ' ');
// 	while (tabstr[i] != NULL)
//     {
//         printf("%s\n", tabstr[i]);
//         i++;
//     }
// }