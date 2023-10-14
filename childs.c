#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

void	first_child(t_struct pipex)
{
	char *cmd;
	char **cmd_1;

	close(pipex.fd[0]);
	cmd = rute_parse(pipex.argv[2], pipex);
	cmd_1 = ft_split(pipex.argv[2], ' ');
	printf("Estoy aquii en hijo 1");
	dup2(pipex.fd_txt[0], STDIN_FILENO);
	dup2(pipex.fd[1], 1);
	close(pipex.fd[1]);
	execve(cmd, cmd_1, pipex.env);
	

}

void	second_child(t_struct pipex)
{
	char *cmd;
	char **cmd_1;

	close(pipex.fd[1]);
	cmd = rute_parse(pipex.argv[3], pipex);
	cmd_1 = ft_split(pipex.argv[3], ' ');

	printf("Estoy aqui en hijo 2");
	dup2(pipex.fd[0], 0);
	dup2(pipex.fd_txt[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	execve(cmd, cmd_1, pipex.env);

}
