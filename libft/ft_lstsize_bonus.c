/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:57:52 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 20:57:59 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*nodo;
	size_t	i;

	i = 0;
	nodo = lst;
	while (nodo != '\0')
	{
		nodo = nodo->next;
		i++;
	}
	return (i);
}
