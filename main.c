/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:52:16 by bargarci          #+#    #+#             */
/*   Updated: 2023/10/16 20:52:20 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>

int	fd_txt_dir(t_struct *pipex)
{
	char	*entrada;
	char	*salida;

	entrada = pipex->argv[1];
	salida = pipex->argv[pipex->argv_count];
	if (check_heredoc(pipex))
	{
		pipex->fd_txt[0] = open(entrada, O_RDONLY);
		if (pipex->fd_txt[0] == -1)
			errors("open input");
		pipex->fd_txt[1] = open(salida, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->fd_txt[1] == -1)
			errors("open output");
	}
	else
	{
		pipex->fd_txt[0] = open("tempo", O_RDONLY);
		if (pipex->fd_txt[0] == -1)
			errors("open output");
		pipex->fd_txt[1] = open(salida, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (pipex->fd_txt[1] == -1)
			errors("open output");
	}
	return (0);
}

int	check_heredoc(t_struct *pipex)
{	
	char	*line;
	int		fd1;

	if (!ft_strncmp(pipex->argv[1], "here_doc", 8))
	{
		fd1 = open("tempo", O_WRONLY | O_CREAT | O_APPEND, 0644);
		while (1)
		{
			write(1, "heredoc> ", 9);
			line = get_next_line(0);
			if (line == 0 || !ft_strncmp(line, pipex->argv[2],
					ft_strlen(pipex->argv[2])))
				break ;
			else
				ft_putstr_fd(line, fd1);
		}
		free(line);
		close(fd1);
		return (0);
	}
	else
		return (1);
}

int	**ft_free_pipex(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
	return (0);
}

void	pipes(t_struct *pipex)
{	
	int	i;

	i = 2;
	if (!ft_strncmp(pipex->argv[1], "here_doc", 8))
		i = 3;
	if (pipe(pipex->fd) == -1)
		errors("pipe");
	pipex->pid[0] = fork();
	if (pipex->pid[0] == -1)
		errors("pid");
	if (pipex->pid[0] == 0)
		first_child(*pipex, pipex->argv[i]);
	i++;
	pipex->pid[1] = fork();
	if (pipex->pid[1] == -1)
		errors("pid1");
	if (pipex->pid[1] == 0)
		second_child(*pipex, pipex->argv[i]);
}

int	main(int argc, char **argv, char **env)
{
	t_struct	pipex;
	int			status;

	pipex.argv = argv;
	pipex.env = env;
	pipex.argv_count = count_argv(argv, 1);
	if (argc < 5)
		errors_manual("invalid number of arguments", "\n");
	count_argc(&pipex);
	fd_txt_dir(&pipex);
	if (argc == pipex.argc_one)
	{
		pipes(&pipex);
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		waitpid(pipex.pid[0], &status, 0);
		waitpid(pipex.pid[1], &status, 0);
	}
	if (argc >= pipex.argc_mul)
		multiples_pipes(&pipex);
	unlink("tempo");
	exit(0);
}
