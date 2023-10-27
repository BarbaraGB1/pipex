/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:52:00 by bargarci          #+#    #+#             */
/*   Updated: 2023/10/16 20:52:06 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include <stdio.h>

void	first_child(t_struct pipex, char *argv)
{
	rute_cmd(&pipex, argv);
	dup2(pipex.fd_txt[0], STDIN_FILENO);
	close(pipex.fd[0]);
	dup2(pipex.fd[1], 1);
	close(pipex.fd[1]);
	if(!pipex.cmd_rute || !pipex.cmd_name)
		return (free(pipex.cmd_rute), ft_free_pipex(pipex.cmd_name), exit(errno));
	execve(pipex.cmd_rute, pipex.cmd_name, pipex.env);
	errors(pipex.cmd_name[0]);
	free(pipex.cmd_rute);
	ft_free_pipex(pipex.cmd_name);
}

void	second_child(t_struct pipex, char *argv)
{
	rute_cmd(&pipex, argv);
	dup2(pipex.fd[0], 0);
	dup2(pipex.fd_txt[1], STDOUT_FILENO);
	close(pipex.fd[1]);
	close(pipex.fd[0]);
	if(!pipex.cmd_rute || !pipex.cmd_name)
		return (free(pipex.cmd_rute), ft_free_pipex(pipex.cmd_name), exit(errno));
	execve(pipex.cmd_rute, pipex.cmd_name, pipex.env);
	errors(pipex.cmd_name[0]);
	free(pipex.cmd_rute);
	ft_free_pipex(pipex.cmd_name);
}
