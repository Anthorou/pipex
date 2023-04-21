/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:48:12 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/21 17:02:24 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	pipe_check(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	dup2_check(int file, int std)
{
	if (dup2(file, std) == -1)
	{
		perror("dup");
		exit(EXIT_FAILURE);
	}
	close(file);
}

void	exec_check(t_list *cmd)
{
	if (cmd->path == NULL)
	{
		perror("Command");
		exit(EXIT_FAILURE);
	}
	execve(cmd->path, cmd->cmds, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

int	fork_check(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
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
