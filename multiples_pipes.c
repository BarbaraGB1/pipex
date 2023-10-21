#include "pipex.h"
#include <stdio.h>

int		multiples_pipes(t_struct *pipex)
{
	build_mul_fd(pipex);
	int	i;
	int j;
	pid_t child;

	i = 2;
	j = 0;
	if (pipe(pipex->fd_mul[j]) == -1)
		errors("pipe");
	first_child_mul(*pipex, pipex->argv[i], j);
	i++;
	printf("esto es el numero de argv en el hijo first: %i\n estoy es el numero de fd: %i\n", i, j);
	while (i < (pipex->argv_count + 2))
	{
		j++;
		if (pipe(pipex->fd_mul[j]) == -1)
			errors("pipe");
		mid_child_mul(*pipex, pipex->argv[i], j);
		i++;
		printf("esto es el numero de argv: %i\n estoy es el numero de fd: %i\n", i, j);
	}
	child = last_child_mul(*pipex, pipex->argv[i], j);
	return (child);
}

int	build_mul_pipes(t_struct pipex)
{
	int	i;

	i = 0;
	while (pipex.fd_mul[i])
	{
		if (pipe(pipex.fd_mul[i]) == -1)
			return (0);
		i++;
	}
	return (0);
}

void	build_mul_fd(t_struct *pipex)
{
	int	**fd_mul;
	int	i;

	i = 0;
	pipex->argv_count = count_argv(pipex->argv, 4);
	fd_mul = malloc(sizeof(int *) * (pipex->argv_count + 1));
	if (!fd_mul)
		return ;
	while (i < pipex->argv_count)
	{
		fd_mul[i] = malloc(sizeof(int) * 2);
		if (!fd_mul[i])
			ft_free_pipex(fd_mul, i);
		i++;
	}
	fd_mul[i] = 0;
	pipex->fd_mul = fd_mul;
}

void	wait_child_pid(pid_t child)
{
	int status;
	int pid;
	int	exit_status;

	pid = 1;
	while (pid != -1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == child)
		{
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
		}
	}
	exit(exit_status);
}
