/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:04:13 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/18 14:58:44 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	exec_cmd(int prev, int out, t_list *cmd)
{
	if (prev > 0)
	{
		dup2(prev, STDIN_FILENO);
		close(prev);
	}
	dup2_check(out, STDOUT_FILENO);
	close(out);
	exec_check(cmd);
}

static void	pipex(t_list *cmd, t_files *files, int argc)
{
	int	fd[2];
	int	prev;
	int pid;
	int i;

	i = 0;
	prev = -1;
	dup2(files->infile, STDIN_FILENO);
	while (i < argc - 3)
	{
		if (cmd->path != NULL)
		{
			pipe_check(fd);
			close(files->infile);
			pid = fork_check(pid);
			if (i == 0 && pid == 0)
				exec_cmd(prev, fd[1], cmd);
			if (i == argc - 4 && pid == 0)
				exec_cmd(prev, files->outfile, cmd);
			waitpid(pid, NULL, 0);
			close(fd[1]);
			close(prev);
			
		}
		prev = fd[0];
		cmd = cmd->next;
		i++;
	}
	close(fd[0]);
	close(files->outfile);
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
