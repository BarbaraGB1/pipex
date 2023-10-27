/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiples_childs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 04:47:41 by bargarci          #+#    #+#             */
/*   Updated: 2023/10/24 04:47:51 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "GNL/get_next_line.h"
#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <sys/fcntl.h>

void	first_child_mul(t_struct pipex, char *argv, int *fd)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		errors("pid");
	if (pid == 0)
	{
		rute_cmd(&pipex, argv);
		close(fd[0]);
		dup2(pipex.fd_txt[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(pipex.fd_txt[0]);
		close(fd[1]);
		if (!pipex.cmd_rute || !pipex.cmd_name)
			return (free(pipex.cmd_rute),
				ft_free_pipex(pipex.cmd_name), exit(errno));
		execve(pipex.cmd_rute, pipex.cmd_name, pipex.env);
		free(pipex.cmd_rute);
		ft_free_pipex(pipex.cmd_name);
		errors(pipex.cmd_name[0]);
	}
}

void	mid_child_mul(t_struct pipex, char *argv, int *fd, int*fd1)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		errors("pid");
	if (pid == 0)
	{
		rute_cmd(&pipex, argv);
		close(fd1[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd1[1], STDOUT_FILENO);
		close(fd[1]);
		if (!pipex.cmd_rute || !pipex.cmd_name)
			return (free(pipex.cmd_rute),
				ft_free_pipex(pipex.cmd_name), exit(errno));
		execve(pipex.cmd_rute, pipex.cmd_name, pipex.env);
		errors(pipex.cmd_name[0]);
		free(pipex.cmd_rute);
		ft_free_pipex(pipex.cmd_name);
	}	
	close(fd[0]);
	close(fd1[1]);
}

void	last_child_mul(t_struct pipex, char *argv, int *fd)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		errors("pid");
	if (pid == 0)
	{
		rute_cmd(&pipex, argv);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(pipex.fd_txt[1], STDOUT_FILENO);
		close(pipex.fd_txt[1]);
		if (!pipex.cmd_rute || !pipex.cmd_name)
			return (free(pipex.cmd_rute),
				ft_free_pipex(pipex.cmd_name), exit(errno));
		execve(pipex.cmd_rute, pipex.cmd_name, pipex.env);
		errors(pipex.cmd_name[0]);
		free(pipex.cmd_rute);
		ft_free_pipex(pipex.cmd_name);
	}
	waitpid(pid, NULL, 0);
}
