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

void	fd_txt_dir(t_struct *pipex)
{
	char	*entrada;
	char	*salida;

	entrada = pipex->argv[1];
	salida = pipex->argv[pipex->argv_count];
	pipex->fd_txt[0] = open(entrada, O_RDONLY);
	if (pipex->fd_txt[0] == -1)
		errors("open input");
	pipex->fd_txt[1] = open(salida, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_txt[0] == -1)
		errors("open output");
}

void	pipes(t_struct *pipex)
{
	fd_txt_dir(pipex);
	if (pipe(pipex->fd) == -1)
		errors("pipe");
	pipex->pid[0] = fork();
	if (pipex->pid[0] == -1)
		errors("pid");
	if (pipex->pid[0] == 0)
		first_child(*pipex, pipex->argv[2]);
	pipex->pid[1] = fork();
	if (pipex->pid[1] == -1)
		errors("pid1");
	if (pipex->pid[1] == 0)
		second_child(*pipex, pipex->argv[3]);
}

int	count_argv(char **argv, int a)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i - a);
}

int	main(int argc, char **argv, char **env)
{
	t_struct	pipex;
	pid_t		pid[2];
	int			fd_txt[2];
	int			fd[2];
	int			status;

	pipex.argv = argv;
	pipex.env = env;
	pipex.fd_txt = fd_txt;
	pipex.fd = fd;
	pipex.pid = pid;
	pipex.argv_count = count_argv(argv, 1);
	if (argc < 5)
		errors_manual("invalid number of arguments\n");
	if (argc == 5)
	{
		pipes(&pipex);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid[0], &status, 0);
		waitpid(pid[1], &status, 0);
	}
	if (argc > 5)
		multiples_pipes(&pipex);
	exit(0);
}
