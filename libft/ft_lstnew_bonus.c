/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:46:08 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/05 16:44:15 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char **content, char *path)
{
	t_list	*rep;

	rep = (t_list *)malloc(sizeof(t_list));
	if (!rep)
		return (NULL);
	rep->cmds = content;
	rep->path = path;
	rep->next = NULL;
	return (rep);
}
