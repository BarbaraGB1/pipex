#include "pipex.h"

void	errors_manual(char *s)
{
	ft_putstr_fd(s, 2);
	exit(errno);
}

void	errors(char *s)
{
	perror(s);
	exit(errno);
}

int	**ft_free_pipex(int **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free (str);
	return (0);
}
