#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

typedef struct s_pipex
{
	char	**argv;
	char	**env;
	char	**rutes;
	char	*path;
	int		*fd_txt;
	int		*fd;
} t_struct;

void	parse(t_struct *pipex);
char	*rute_parse(char *argv, t_struct pipex);
void	first_child(t_struct pipex);
void	second_child(t_struct pipex);
void	fd_txt_dir(t_struct *pipex);

#endif 
