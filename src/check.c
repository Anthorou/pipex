/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:48:12 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/24 15:24:05 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	pipe_check(int *fd, t_pops *pops)
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		free_all(pops);
		exit(EXIT_FAILURE);
	}
}

void	dup2_check(int file, int std, t_pops *pops)
{
	if (dup2(file, std) == -1)
	{
		perror("dup");
		free_all(pops);
		exit(EXIT_FAILURE);
	}
	close(file);
}

void	exec_check(t_list *current, t_pops *pops)
{
	if (current->path == NULL)
	{
		perror("Command");
		free_all(pops);
		exit(EXIT_FAILURE);
	}
	execve(current->path, current->cmds, NULL);
	perror("execve");
	free_all(pops);
	exit(EXIT_FAILURE);
}

int	fork_check(t_pops *pops)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		free_all(pops);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	check_cmd(t_list *cmd)
{
	int	i;
	int	j;

	while (cmd)
	{
		i = 0;
		while (cmd->cmds[i])
		{
			j = 0;
			while (cmd->cmds[i][j] != '\0')
			{
				if (cmd->cmds[i][j] == '	')
					cmd->cmds[i][j] = ' ';
				j++;
			}
			i++;
		}
		cmd = cmd->next;
	}
}
