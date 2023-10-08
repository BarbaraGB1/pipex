#include <stdio.h>
#include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>

char parse(char **argv, char **env)
{
	int i;
	char *path;
	char **rutes;
	char *check;
	char *good_one;

	i = 0;
	good_one = NULL;
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
		check = ft_strjoin(check, argv[2]);
		if (access(check, F_OK) == 0)
		{
			printf("La ruta del comando %s es %s", argv[i], check);
			good_one = check;
		}
		i++;
	}
	return (*good_one);
}
int main (int argc, char **argv, char **env)
{
	int fd;


	if (argc < 5)
		printf("argumentos insuficientes\n");
	parse(argv , env);
	fd = open("archivo.txt", O_WRONLY | O_TRUNC | O_CREAT , 0777);
	write(fd, "HOLA", 4);
	
	return (0);

}
