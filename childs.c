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
	char	*cmd_rute;
	char	*cmd_name1;
	char	**cmd_name;

	close(pipex.fd[0]);
	cmd_rute = rute_parse(argv, &pipex);
	if (absolut_rute(argv))
	{
		cmd_name1 = search_cmd_name(argv);
		cmd_name = ft_split(cmd_name1, ' ');
	}
	else
		cmd_name = ft_split(argv, ' ');
	dup2(pipex.fd_txt[0], STDIN_FILENO);
	dup2(pipex.fd[1], 1);
	close(pipex.fd[1]);
	execve(cmd_rute, cmd_name, pipex.env);
	perror(cmd_name[0]);
	exit(errno);
}

void	second_child(t_struct pipex, char *argv)
{
	char	*cmd_rute;
	char	*cmd_name2;
	char	**cmd_name_second;

	close(pipex.fd[1]);
	cmd_rute = rute_parse(argv, &pipex);
	dup2(pipex.fd[0], 0);
	if (absolut_rute(argv))
	{
		cmd_name2 = search_cmd_name(argv);
		cmd_name_second = ft_split(cmd_name2, ' ');
	}
	else
		cmd_name_second = ft_split(argv, ' ');
	dup2(pipex.fd_txt[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	execve(cmd_rute, cmd_name_second, pipex.env);
	perror(cmd_name_second[0]);
	exit(errno);
}

char	*find_rutes(t_struct *pipex, char **cmd)
{
	char	*check;
	int		i;

	i = 0;
	while (pipex->rutes[i])
	{
		check = ft_strjoin(pipex->rutes[i], "/");
		check = ft_strjoin(check, cmd[0]);
		if (check_rute(check))
			return (check);
		i++;
	}
	return (0);
}

int	ft_stchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*b;
	int		j;

	i = 0;
	j = 0;
	a = (char)c;
	b = (char *)s;
	while (b[i] != '\0')
	{
		if (b[i] == a)
			j++;
		i++;
	}
	return (j);
}
