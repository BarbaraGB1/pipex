#include "pipex.h"
#include <stdio.h>

void	first_child_mul(t_struct pipex, char *argv, int j)
{
	char	*cmd_rute;
	char	*cmd_name1;
	char	**cmd_name;
	int		pid;
	int		df0;
	int		df1;

	printf("estouy en el primer hijo\n");
	pid = fork();
	if (pid == -1)
		errors("pid");
	if (pid == 0)
	{
		printf("estouy en el primer hijo1\n");
		close(pipex.fd_mul[j][0]);
		cmd_rute = rute_parse(argv, &pipex);
		if (absolut_rute(argv))
		{
			cmd_name1 = search_cmd_name(argv);
			cmd_name = ft_split(cmd_name1, ' ');
		}
		else
			cmd_name = ft_split(argv, ' ');
		printf("estouy en el seguro hijo y el comando es %s\n", cmd_name[0]);
		df0 = dup2(pipex.fd_txt[0], STDIN_FILENO);
		df1 = dup2(pipex.fd_mul[j][1], 1);
		dprintf(2, "DF0F %i\n", df0);
		dprintf(2, "DF1F %i\n", df1);
		close(pipex.fd_mul[j][1]);
		close(pipex.fd_txt[0]);
		execve(cmd_rute, cmd_name, pipex.env);
		perror(cmd_name[0]);
		exit(errno);
	}
}

void	mid_child_mul(t_struct pipex, char *argv, int j)
{
	char	*cmd_rute;
	char	*cmd_name2;
	char	**cmd_name_second;
	int		pid;

	pid = fork();		
	if (pid == -1)
		errors("pid");
	if (pid == 0)
	{
		printf("estouy en el seguro hijo2\n");
		cmd_rute = rute_parse(argv, &pipex);
		dup2(pipex.fd_mul[j - 1][0], 0);
		if (absolut_rute(argv))
		{
			cmd_name2 = search_cmd_name(argv);
			cmd_name_second = ft_split(cmd_name2, ' ');
		}
		else
			cmd_name_second = ft_split(argv, ' ');
		printf("estouy en el seguro hijo2 y el comando es %s\n", cmd_name_second[0]);
		dup2(pipex.fd_mul[j][1], 1);
		close(pipex.fd_mul[j][0]);
		close(pipex.fd_mul[j][1]);
		execve(cmd_rute, cmd_name_second, pipex.env);
		perror(cmd_name_second[0]);
		exit(errno);
	}	
}

int		last_child_mul(t_struct pipex, char *argv, int j)
{
	char	*cmd_rute;
	char	*cmd_name2;
	char	**cmd_name_second;
	int		pid;

	pid = fork();
	if (pid == -1)
		errors("pid");
	if (pid == 0)
	{
	//	printf("estouy en el ultimo hijo3\n");
		close(pipex.fd_mul[j][1]);
		cmd_rute = rute_parse(argv, &pipex);
		printf("estouy en el  hijo3 y la ruta del comando es %s\n", cmd_rute);
		dup2(pipex.fd_mul[j - 1][0], 0);
		if (absolut_rute(argv))
		{
			cmd_name2 = search_cmd_name(argv);
			cmd_name_second = ft_split(cmd_name2, ' ');
		}
		else
			cmd_name_second = ft_split(argv, ' ');
		printf("estouy en el seguro hijo3 y el comando es %s\n", cmd_name_second[0]);
		dup2(pipex.fd_txt[1], STDOUT_FILENO);
		printf("Compruebo que llego a antes de la ejecucion 1");
		close(pipex.fd_mul[j][0]);
	//	close(pipex.fd_mul[j][1]);
		close(pipex.fd_txt[1]);
		printf("Compruebo que llego a antes de la ejecucion");
		execve(cmd_rute, cmd_name_second, pipex.env);
		perror(cmd_name_second[0]);
		exit(errno);
	}
	return (pid);
}
