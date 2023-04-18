/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:01:05 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/18 14:38:39 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_file
{
	int	infile;
	int	outfile;
}	t_files;

void	free_tab(char **tab);
t_list	*free_list(t_list *list);
void	free_files(t_files *files);
char	*find_path(char *argv);
t_files	*parsing_files(char **argv, int argc);
t_list	*parsing_cmd(char **argv, int argc);
void	pipe_check(int *fd);
int		files_check(char *file, int i);
void	dup2_check(int file, int std);
void	exec_check(t_list *cmd);
int		fork_check(int pid);

#endif