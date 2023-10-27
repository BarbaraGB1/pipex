/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 05:29:40 by bargarci          #+#    #+#             */
/*   Updated: 2023/10/27 05:29:50 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"
#include <stdlib.h>

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

void	rute_cmd(t_struct *pipex, char *argv)
{
	char	*cmd;

	if (!check_good_argv(argv))
		errors_manual("Command not found: ", argv);
	pipex->cmd_rute = rute_parse(argv, pipex);
	if (absolut_rute(argv))
	{
		cmd = search_cmd_name(argv);
		if (!cmd)
			return(free(cmd));
		pipex->cmd_name = ft_split(cmd, ' ');
	}
	else
		pipex->cmd_name = ft_split(argv, ' ');
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
	if (pipex->rutes)
	{
		ft_free_pipex(pipex->rutes);
		exit(EXIT_FAILURE);
	}
}

int	check_good_argv(char *argv)
{
	if (argv[0] == ' ')
		return (0);
	return (1);
}
