/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:42:23 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/15 17:36:36 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_read(int fd, char *s)
{
	char	*s2;
	int		verif;

	verif = 1;
	s2 = (char *)malloc (sizeof(char) * 1024);
	if (!s2)
		return (NULL);
	while (verif != 0)
	{
		ft_memset(s2, 0, 1024);
		verif = read(fd, s2, 1024);
		if (verif < 0)
		{
			free(s);
			free(s2);
			return (NULL);
		}
		s2[1024] = '\0';
		if (verif != 0)
			s = ft_strjoin(s, s2);
	}
	free(s2);
	return (s);
}

static char	*check_line(char *start)
{
	char	*rep;
	int		i;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	i += (start[i] == '\n');
	rep = (char *)malloc(sizeof(char) * i + 1);
	if (!rep)
	{
		free(start);
		return (NULL);
	}
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		rep[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		rep[i++] = '\n';
	rep[i] = '\0';
	return (rep);
}

char	*move_start(char *start)
{
	char	*new_start;
	int		i;
	int		j;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	i += (start[i] == '\n');
	new_start = (char *)malloc(sizeof(char) * (ft_strlen(start) - i + 1));
	if (!new_start)
	{
		free(start);
		return (NULL);
	}
	j = 0;
	while (start[i + j])
	{
		new_start[j] = start[i + j];
		j++;
	}
	new_start[j] = '\0';
	free(start);
	return (new_start);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*rep;

	if (fd < 0)
		return (NULL);
	buf = get_read(fd, buf);
	if (!buf || buf[0] == '\0')
	{
		free(buf);
		return (NULL);
	}
	rep = check_line(buf);
	buf = move_start(buf);
	return (rep);
}
