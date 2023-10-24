/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiples_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 04:47:59 by bargarci          #+#    #+#             */
/*   Updated: 2023/10/24 04:48:06 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include <stdio.h>

void	multiples_pipes(t_struct *pipex)
{
	int	i;
	int	fd_firstchild[2];

	i = 2;
	fd_txt_dir(pipex);
	if (pipe(fd_firstchild) == -1)
		errors("pipe");
	first_child_mul(*pipex, pipex->argv[i], fd_firstchild);
	close(fd_firstchild[1]);
	i++;
	goto_middle(pipex, fd_firstchild, i);
	close(fd_firstchild[0]);
}

void	goto_middle(t_struct *pipex, int *fd_firstchild, int i)
{
	int	fd_secondchild[2];
	int	fd_2[2];

	while (i < (pipex->argv_count - 1))
	{
		if (pipe(fd_secondchild) == -1)
			errors("pipe");
		if (i == 3)
			mid_child_mul(*pipex, pipex->argv[i],
				fd_firstchild, fd_secondchild);
		else
			mid_child_mul(*pipex, pipex->argv[i], fd_2, fd_secondchild);
		fd_2[0] = fd_secondchild[0];
		fd_2[1] = fd_secondchild[1];
		i++;
	}
	last_child_mul(*pipex, pipex->argv[i], fd_secondchild);
}
