/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:04:13 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/24 16:03:01 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	exec_first_cmd(t_pops *pops, int *fd, t_list *current)
{
	int	in_fd;
	int	pid;

	in_fd = open(pops->files->infile, O_RDONLY);
	pipe_check(fd, pops);
	pid = fork_check(pops);
	if (pid == 0)
	{
		close(fd[0]);
		dup2_check(in_fd, STDIN_FILENO, pops);
		dup2_check(fd[1], STDOUT_FILENO, pops);
		exec_check(current, pops);
	}
	close(fd[1]);
	close(in_fd);
	waitpid(pid, NULL, 0);
}

static void	exec_cmd(int *fd, t_list *current, t_pops *pops, int nb)
{
	int	prev;
	int	pid;
	int	i;

	i = 0;
	while (i < nb)
	{
		prev = fd[0];
		pipe_check(fd, pops);
		pid = fork_check(pops);
		if (pid == 0)
		{
			close(fd[0]);
			dup2_check(prev, STDIN_FILENO, pops);
			dup2_check(fd[1], STDOUT_FILENO, pops);
			exec_check(current, pops);
		}
		close(prev);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		i++;
		current = current->next;
	}
}

static void	exec_last_cmd(int fd, t_pops *pops, t_list *current)
{
	int	pid;
	int	fd_out;

	fd_out = open(pops->files->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	pid = fork_check(pops);
	if (pid == 0)
	{
		dup2_check(fd, STDIN_FILENO, pops);
		dup2_check(fd_out, STDOUT_FILENO, pops);
		exec_check(current, pops);
	}
	close(fd_out);
	close(fd);
}

static void	pipex(t_list *current, int argc, t_pops *pops)
{
	int	fd[2];

	exec_first_cmd(pops, fd, current);
	exec_cmd(fd, current->next, pops, argc - 5);
	exec_last_cmd(fd[0], pops, ft_lstlast(current));
}

int	main(int argc, char **argv)
{
	t_pops	*pops;
	t_list	*current;

	if (argc > 4)
	{
		pops = (t_pops *)malloc(sizeof(t_pops));
		pops->files = parsing_files(argv, argc);
		if (pops->files == NULL)
			return (1);
		pops->cmd = parsing_cmd(argv, argc);
		current = pops->cmd;
		check_cmd(current);
		current = pops->cmd;
		pipex(current, argc, pops);
		free_all(pops);
		return (0);
	}
	write(2, "Must have 4 args!\n", 18);
	return (1);
}
