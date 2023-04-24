/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:01:05 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/24 18:35:37 by aroussea         ###   ########.fr       */
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
	char	*infile;
	char	*outfile;
}	t_files;

typedef struct s_pops
{
	t_files	*files;
	t_list	*cmd;
}	t_pops;

void	free_tab(char **tab);
t_list	*free_list(t_list *list);
void	free_files(t_files *files);
void	free_all(t_pops *pops);
char	*find_path(char *argv);
t_files	*parsing_files(char **argv, int argc);
t_list	*parsing_cmd(char **argv, int argc);
void	pipe_check(int *fd, t_pops *pops);
void	dup2_check(int file, int std, t_pops *pops);
void	exec_check(t_list *current, t_pops *pops);
int		fork_check(t_pops *pops);
void	check_cmd(t_list *cmd);

#endif