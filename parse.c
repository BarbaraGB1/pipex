/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:51:33 by bargarci          #+#    #+#             */
/*   Updated: 2023/10/16 20:51:38 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>

int	absolut_rute(char *argv)
{
	printf("estoy en ruta absoluta\n");
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

char	*search_cmd_name(char *argv)
{
	char	**do_split;
	int		i;
	char	*cmd;

	i = 0;
	do_split = ft_split(argv, '/');
	while (do_split[i])
		i++;
	cmd = do_split[i - 1];
	return (cmd);
}

char	*check_rute(char *check)
{
	if (access(check, F_OK) == 0)
	{
		return (check);
	}
	return (0);
}

char	*rute_parse(char *argv, t_struct *pipex)
{
	char	*check;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	printf("en rute_parse el resultado del split es: %s\n", cmd[0]);
	if (absolut_rute(cmd[0]))
	{
		if (check_rute(cmd[0]))
			return (cmd[0]);
		return (0);
	}
	if (!*pipex->env)
	{
		check = ft_strjoin("./", cmd[0]);
		return (check);
	}
	parse(pipex);
	if (find_rutes(pipex, cmd))
	{
		printf("estoy en ruta comando: %s\n", cmd[0]);
		check = find_rutes(pipex, cmd);
		return (check);
	}
	errors_manual("command not found\n");
	return (0);
}

void	parse(t_struct *pipex)
{
	int		i;

	i = 0;
	while (pipex->env[i])
	{
		if (!ft_strncmp(pipex->env[i], "PATH=", 5))
		{
			pipex->path = pipex->env[i];
			break ;
		}
		i++;
	}
	pipex->rutes = ft_split(pipex->path + 5, ':');
}
