/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:04:21 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/24 15:57:06 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_path(char *argv)
{
	char	*args[3];
	char	*rep;
	int		fd[2];
	int		pid;

	args[0] = "whereis";
	args[1] = argv;
	args[2] = NULL;
	rep = NULL;
	pipe(fd);
	pid = fork();
	if (pid < 0)
		return (NULL);
	else if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve("/usr/bin/whereis", args, NULL);
	}
	waitpid(pid, NULL, 0);
	close(fd[1]);
	rep = get_all_line(fd[0], rep);
	close(fd[0]);
	return (rep);
}

t_files	*parsing_files(char **argv, int argc)
{
	t_files	*files;

	if (access(argv[1], R_OK) == -1)
	{
		perror("files");
		return (NULL);
	}
	if (access(argv[argc - 1], F_OK) != -1
		&& access(argv[argc - 1], W_OK) == -1)
	{
		perror("files");
		return (NULL);
	}
	files = (t_files *)malloc(sizeof(t_files));
	files->infile = argv[1];
	files->outfile = argv[argc - 1];
	return (files);
}

static char	*trim_path(char *path)
{
	int		i;
	int		nb;
	char	*new;

	nb = ft_strlen(path);
	i = 0;
	new = NULL;
	if (path[nb - 1] == '\n')
	{
		new = (char *)malloc(sizeof(char) * nb);
		while (i < nb - 1)
		{
			new[i] = path[i];
			i++;
		}
		new[i] = '\0';
	}
	free(path);
	return (new);
}

static void	check_args(char **arg)
{
	int		i;
	char	tmp;

	i = 0;
	while ((*arg)[i])
	{
		if (((*arg)[i] == '\'' || (*arg)[i] == '\"')
			&& ft_strchr((*arg) + i + 1, (*arg)[i]))
		{
			tmp = (*arg)[i];
			(*arg)[i++] = ' ';
			while ((*arg)[i] != tmp)
			{
				if ((*arg)[i] == ' ')
					(*arg)[i] = '	';
				i++;
			}
			(*arg)[i] = ' ';
		}
		else if ((*arg)[i] == '	')
			(*arg)[i] = ' ';
		i++;
	}
}

t_list	*parsing_cmd(char **argv, int argc)
{
	t_list	*cmd;
	char	*path;
	char	**tmp;
	int		i;

	i = 2;
	cmd = NULL;
	while (i < argc - 1)
	{
		check_args(&argv[i]);
		tmp = ft_split(argv[i], ' ');
		path = find_path(tmp[0]);
		if (path != NULL)
			path = trim_path(path);
		ft_lstadd_back(&cmd, ft_lstnew(ft_split(argv[i], ' '), path));
		free_tab(tmp);
		i++;
	}
	return (cmd);
}
