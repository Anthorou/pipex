/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:04:13 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/14 17:19:25 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	exec_cmd1(t_list *cmd, int *fd, t_files *files)
{
	int fd_in;

	fd_in = open(files->infile, O_RDONLY);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd_in);
	close(fd[1]);
	close(fd[0]);
	execve(cmd->path, cmd->cmds, NULL);
	perror("execve failed");
	exit(1);
}

static void	exec_cmd2(t_list *cmd, int *fd, t_files *files)
{
	int fd_out;

	fd_out = open(files->outfile, O_WRONLY | O_TRUNC);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(fd[0]);
	execve(cmd->path, cmd->cmds, NULL);
	perror("execve failed");
	exit(1);
}

static void	pipex(t_list *cmd, t_files *files)
{
	int	fd[2];
	int pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
		exec_cmd1(cmd, fd, files);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	pid = fork();
	if (pid == 0)
		exec_cmd2(cmd->next, fd, files);
	waitpid(pid, NULL, 0);
	close(fd[0]);
}

int	main(int argc, char **argv)
{
	t_files	*files;
	t_list	*cmd;

	if (argc > 3)
	{
		files = parsing_files(argv, argc);
		if (files == NULL)
		{
			perror("files");
			return (1);
		}	
		cmd = parsing_cmd(argv, argc);
		if (cmd == NULL)
		{
			write(2, "cmd non valide\n", 15);
			free_files(files);
			return (1);
		}
		pipex(cmd, files);
		free_files(files);
		free_list(cmd);
		return (0);
	}
	write(2, "Must have 3 args!\n", 18);
	return (1);
}
