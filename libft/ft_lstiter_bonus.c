/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:52:36 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 20:52:42 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*nodo;

	nodo = lst;
	if (!nodo || !f)
		return ;
	while (nodo)
	{
		f(nodo->content);
		nodo = nodo->next;
	}
}
