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
	int		*fd_txt;
	int		*fd;
	pid_t	*pid;
}	t_struct;

void	parse(t_struct *pipex);
char	*rute_parse(char *argv, t_struct *pipex);
void	pipes(t_struct *pipex);
void	first_child(t_struct pipex);
void	second_child(t_struct pipex);
void	fd_txt_dir(t_struct *pipex);
int		absolut_rute(char *argv);
char	*search_cmd_name(char *argv);
char	*check_rute(char *check);
void	errors(char *s);
void	errors_manual(char *s);
char	*find_rutes(t_struct *pipex, char **cmd);

#endif 
