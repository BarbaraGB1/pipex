/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:51:33 by bargarci          #+#    #+#             */
/*   Updated: 2023/10/27 05:30:02 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"
#include <stdio.h>

int	absolut_rute(char *argv)
{
	if (!ft_strncmp(argv, "../", 3))
		return (1);
	else if (!ft_strncmp(argv, "./", 2))
		return (1);
	else if (!ft_strncmp(argv, "/", 1))
		return (1);
	else if (check_rute(argv))
	{
		if (ft_stchr(argv, '/') < 1)
			return (0);
		return (1);
	}
	else
		return (0);
}

char	*check_rute(char *check)
{
	if (access(check, F_OK) == 0)
	{
		return (check);
	}
	return (0);
}

char	*find_rutes(t_struct *pipex, char **cmd)
{
	char	*check;
	int		i;
	char	*temp;

	i = 0;
	while (pipex->rutes[i])
	{
		temp = ft_strjoin(pipex->rutes[i], "/");
		check = ft_strjoin(temp, cmd[0]);
		if (check_rute(check))
			return (check);
		free(temp);
		i++;
	}
	ft_free_pipex(pipex->rutes);
	return (0);
}

char	*rute_parse(char *argv, t_struct *pipex)
{
	char	*check;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		ft_free_pipex(cmd);
		return (0);
	}
	if (absolut_rute(cmd[0]))
	{
		if (check_rute(cmd[0]))
			return (cmd[0]);
		return (0);
	}
	if (!*pipex->env)
		return (aux_noenv(cmd[0]));
	parse(pipex);
	if (find_rutes(pipex, cmd))
	{
		check = find_rutes(pipex, cmd);
		return (check);
	}
	errors_manual("command not found: ", cmd[0]);
	return (0);
}

char	*aux_noenv(char *cmd)
{
	char	*check;

	check = ft_strjoin("./", cmd);
	return (check);
}
