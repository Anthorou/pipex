/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:57:47 by aroussea          #+#    #+#             */
/*   Updated: 2023/05/01 14:50:48 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	tab = NULL;
}

t_list	*free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->cmds)
			free_tab(list->cmds);
		if (list->path)
			free(list->path);
		free(list);
		list = tmp;
	}
	list = NULL;
	return (list);
}

void	free_files(t_files *files)
{
	if (files)
		free(files);
}

void	free_all(t_pops *pops)
{
	free_files(pops->files);
	free_list(pops->cmd);
	free(pops);
}

int	end(t_pops *pops, t_list *current)
{
	int	re;

	re = 0;
	while (current)
	{
		if (current->path == NULL)
		{
			re = 1;
			break ;
		}
		current = current->next;
	}
	free_all(pops);
	return (re);
}
