/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:48:12 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/19 17:20:17 by aroussea         ###   ########.fr       */
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
	execve(cmd->path, cmd->cmds, NULL);
	perror("execve");
}

int	fork_check()
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return(pid);
}
