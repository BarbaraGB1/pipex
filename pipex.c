#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *parse(char **argv, char **env)
{
	int i;
	char *path;
	char **rutes;
	char *check;

	i = 0;
	rutes = NULL;
	check = NULL;
	path = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			path = env[i];
			break ;
		}
		i++;
	}
	rutes = ft_split(path + 5, ':');
	i = 0;
	while(rutes[i])
	{
		check = ft_strjoin(rutes[i], "/");
		check = ft_strjoin(check, *argv);
		if (access(check, F_OK) == 0)
		{
			printf("La ruta del comando %s es %s\n", argv[i], check);
			break ;
		}
		i++;
	}
	return (check);
}
int main (int argc, char **argv, char **env)
{
	int fd1[2];
	int fd2[2];
	int fd;
	char *rute; 
	int status;
	int	i;

	i = 0;
	if (argc < 3)
		printf("argumentos insuficientes\n");
	if(pipe(fd1) == -1)
		return (1);
	if(pipe(fd2) == -1)
		return (1);
	int pid = fork();
	waitpid(pid, &status, 0);
	printf("pid : %i\n", pid);
	if (pid == -1)
		printf("lo que sea\n");
	if (pid == 0)
	{
		printf("hola");	
		close(fd1[1]);
		close(fd2[0]);
		fd = open("entrada.txt", O_RDONLY, 0777);
		dup2(fd, 0);
		dup2(fd2[1], 1);
		rute = parse(&argv[2] , env);
		printf("lo que hay en el interior de rute es hijo : %s\n", rute);
		close(fd1[0]);
		close(fd2[1]);
		execve(rute, &argv[2], env);

	}
	else 
	{
		close(fd1[1]);
		close(fd2[0]);
		rute = parse(&argv[3] , env);
		printf("lo que hay en el interior de rute es : %s\n", rute);
		fd2[1] = open("archivo.txt", O_WRONLY | O_TRUNC | O_CREAT , 0777);
		dup2(fd2[1], STDOUT_FILENO);
		close(fd2[1]);
		close(fd1[0]);
		execve(rute, &argv[3], env);

		
	}
//	fd1 = open("entrada.txt", O_RDONLY, 0777);
/*	while (rute[i]) 
	{
		ft_putchar_fd(rute[i], fd2);
		i++;
	}*/
	
	return (0);

}
