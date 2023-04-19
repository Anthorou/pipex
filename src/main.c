/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:04:13 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/19 17:21:19 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	exec_first_cmd(char *in_file, int *fd, t_list *cmd)
{
	int	in_fd;
	int	pid;
	
	pipe_check(fd);
	pid = fork_check();
	in_fd = open(in_file, O_RDONLY);
	if (pid == 0)
	{
		close(fd[0]);
		dup2_check(in_fd, STDIN_FILENO);
		dup2_check(fd[1], STDOUT_FILENO);
		exec_check(cmd);
	}
	close(fd[1]);
	close(in_fd);
	waitpid(pid, NULL, 0);
}

static void	exec_cmd(int *fd, t_list *cmd, int nb)
{
	int	prev;
	int	pid;
	int	i;
	
	i = 0;
	while(i < nb)
	{
		prev = fd[0];
		pipe_check(fd);
		pid = fork_check();
		if (pid == 0)
		{
			close(fd[0]);
			dup2_check(prev, STDIN_FILENO);
			dup2_check(fd[1], STDOUT_FILENO);
			exec_check(cmd);
		}
		close(prev);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		i++;
		cmd = cmd->next;
	}
}

static void	exec_last_cmd(int fd, char *out_file, t_list *cmd)
{
	int	pid;
	int	fd_out;

	fd_out = open(out_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	pid = fork_check();
	if (pid == 0)
	{
		dup2_check(fd, STDIN_FILENO);
		dup2_check(fd_out, STDOUT_FILENO);
		exec_check(cmd);
	}
	close(fd_out);
	close(fd);
}

static void	pipex(t_list *cmd, t_files *files, int argc)
{
	int	fd[2];
	
	exec_first_cmd(files->infile, fd, cmd);
	exec_cmd(fd, cmd->next, argc - 5);
	exec_last_cmd(fd[0], files->outfile, ft_lstlast(cmd));
}

int	main(int argc, char **argv)
{
	t_files	*files;
	t_list	*cmd;
	t_list	*current;

	if (argc > 4)
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
		current = cmd;
		pipex(current, files, argc);
		free_files(files);
		free_list(cmd);
		return (0);
	}
	write(2, "Must have 4 args!\n", 18);
	return (1);
}
