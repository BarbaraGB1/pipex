#include "libft/libft.h"
#include "pipex.h"

void	fd_txt_dir(t_struct *pipex)
{
	char *entrada;
	char *salida;
	
	entrada = pipex->argv[1];
	salida = pipex->argv[4];
	pipex->fd_txt[0] = open(entrada, O_RDONLY);
	pipex->fd_txt[1] = open(salida, O_WRONLY | O_CREAT | O_TRUNC , 0777);
}
int		absolut_rute(char *argv)
{
	if (!ft_strncmp(argv, "../", 3))
		return (1);
	else if (!ft_strncmp(argv, "./", 2))
		return (1);
	else if (!ft_strncmp(argv, "/", 1))
		return (1);
	else 
		return (0);	
}
char	*search_cmd_name(char *argv)
{
	char **do_split;
	int i;
	char *cmd;

	i = 0;
	do_split = ft_split(argv, '/');
	while (do_split[i])
		i++;
	cmd = do_split[i -1];
	free(do_split);
	return (cmd);
}
char	*rute_parse(char *argv, t_struct pipex)
{
	int		i;
	char	*check;
	char	**cmd;
	
	i = 0;
	if(absolut_rute(argv))
	{
		check = argv;
		return (check);
	}
	else 
	{
		cmd = ft_split(argv, ' ');
		while (pipex.rutes[i])
		{
			check = ft_strjoin(pipex.rutes[i], "/");
			check = ft_strjoin(check, cmd[0]);
			if (access(check, F_OK) == 0)
			{
				printf("La ruta del comando %s es %s\n", argv, check);
				return (check);
			}
			i++;
		}
	}
	return (0);
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
}
