/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 04:47:26 by bargarci          #+#    #+#             */
/*   Updated: 2023/10/24 04:47:30 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	errors_manual(char *s, char *argv)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(argv, 2);
	if (ft_strncmp(argv, "\n", 2))
		write(2, "\n", 1);
	exit(errno);
}

void	errors(char *s)
{
	perror(s);
	exit(errno);
}

int	count_argv(char **argv, int a)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i - a);
}

void	count_argc(t_struct *pipex)
{
	if (!ft_strncmp(pipex->argv[1], "here_doc", 8))
	{
		pipex->argc_one = 6;
		pipex->argc_mul = 7;
	}
	else
	{
		pipex->argc_one = 5;
		pipex->argc_mul = 6;
	}
}

int	ft_stchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*b;
	int		j;

	i = 0;
	j = 0;
	a = (char)c;
	b = (char *)s;
	while (b[i] != '\0')
	{
		if (b[i] == a)
			j++;
		i++;
	}
	return (j);
}
