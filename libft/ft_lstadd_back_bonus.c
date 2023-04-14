/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:25:44 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/17 17:30:48 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*rep;

	if (lst)
	{
		if (*lst)
		{
			rep = ft_lstlast(*lst);
			rep->next = new;
		}
		else
			*lst = new;
	}
}
