#include "pipex.h"
#include <sys/wait.h>

int main (int argc, char **argv, char **env)
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

	if (argc < 5)
		printf("argumentos insuficientes\n");
	parse(&pipex);
	fd_txt_dir(&pipex);
	if(pipe(fd) == -1)
		perror("pipe1");
	pid[0] = fork();
	if (pid[0] == -1)
	{
		perror("pid");
		exit(errno);
	}
	if (pid[0] == 0 )
		first_child(pipex);
	pid[1] = fork();

	if (pid[1] == -1)
	{
		perror("pid1");
		exit(errno);
	}
	if (pid[1] == 0 )
		second_child(pipex);
	waitpid(pid[0], &status, 0);
	exit(1);
//		waitpid(pid[1], &status, 0);
	return (0);

}
