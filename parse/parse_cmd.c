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

char	*search_cmd_name(char *argv)
{
	char	**do_split;
	int		i;
	char	*cmd;

	i = 0;
	do_split = ft_split(argv, '/');
	if(!do_split)
		return (0);
	while (do_split[i])
		i++;
	cmd = do_split[i - 1];
	return (cmd);
}

void	rute_cmd(t_struct *pipex, char *argv)
{
	char	*cmd;

	if(!check_good_argv(argv))
		errors_manual("Command not found: ", argv);
	pipex->cmd_rute = rute_parse(argv, pipex);
	if (absolut_rute(argv))
	{
		cmd = search_cmd_name(argv);
		pipex->cmd_name = ft_split(cmd, ' ');
		if (!pipex->cmd_name)
			return ;
	}
	else
	{
		pipex->cmd_name = ft_split(argv, ' ');
		if (!pipex->cmd_name)
			return ;
	}
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
	if (!pipex->rutes)
		return ;
}

int	check_good_argv(char *argv)
{
	if (!ft_isalpha(argv[0]))
		return (0);
	return (1);
}
