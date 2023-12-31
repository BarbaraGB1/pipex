/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:51:50 by bargarci          #+#    #+#             */
/*   Updated: 2023/10/16 20:51:54 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "./GNL/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

typedef struct s_pipex
{
	char	**argv;
	char	**env;
	char	**rutes;
	char	*path;
	int		fd_txt[2];
	int		fd[2];
	pid_t	pid[2];
	int		argv_count;
	char	*cmd_rute;
	char	**cmd_name;
	int		argc_one;
	int		argc_mul;
}	t_struct;

void	parse(t_struct *pipex, char *cmd);
char	*rute_parse(char *argv, t_struct *pipex);
void	pipes(t_struct *pipex);
void	first_child(t_struct pipex, char *argv);
void	second_child(t_struct pipex, char *argv);
int		fd_txt_dir(t_struct *pipex);
int		absolut_rute(char *argv);
char	*search_cmd_name(char *argv);
char	*check_rute(char *check);
void	errors(char *s);
void	errors_manual(char *s, char *argv);
char	*find_rutes(t_struct *pipex, char **cmd);
int		ft_stchr(const char *s, int c);
int		count_argv(char **argv, int a);
void	multiples_pipes(t_struct *pipex);
int		build_mul_pipes(t_struct pipex);
int		**ft_free_pipex(char **str);
void	build_mul_fd(t_struct *pipex);
void	mid_child_mul(t_struct pipex, char *argv, int *fd, int *fd1);
void	first_child_mul(t_struct pipex, char *argv, int *fd);
void	last_child_mul(t_struct pipex, char *argv, int *fd1);
void	rute_cmd(t_struct *pipex, char *argv);
void	goto_middle(t_struct *pipex, int *fd_firstchild, int i, int j);
int		check_heredoc(t_struct *pipex);
void	count_argc(t_struct *pipex);
char	*aux_noenv(char *cmd);
int		check_good_argv(char *argv);

#endif 
