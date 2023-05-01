/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:04:21 by aroussea          #+#    #+#             */
/*   Updated: 2023/05/01 14:40:12 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*check_path(char *path, char *cmd)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * ft_strlen(path) + ft_strlen(cmd));
	ft_strlcpy(buf, path, ft_strlen(path) + 1);
	ft_strlcat(buf, "/", ft_strlen(buf) + 2);
	ft_strlcat(buf, cmd, ft_strlen(buf) + ft_strlen(cmd) + 1);
	if (access(buf, F_OK) == 0)
		return (buf);
	free(buf);
	return (NULL);
}

char	*find_path(char *cmd, char **env)
{
	char	*path;
	char	**all_path;

	while (*env != NULL)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env + 5;
			break ;
		}
		env++;
	}
	all_path = ft_split(path, ':');
	path = NULL;
	while (path == NULL && *all_path != NULL)
		path = check_path(*all_path++, cmd);
	return (path);
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

t_list	*parsing_cmd(char **argv, int argc, char **env)
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
		path = find_path(tmp[0], env);
		ft_lstadd_back(&cmd, ft_lstnew(ft_split(argv[i], ' '), path));
		free_tab(tmp);
		i++;
	}
	return (cmd);
}
