/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:51:41 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 20:51:46 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nodo;
	t_list	*a;

	if (!lst || !del)
		return ;
	nodo = *lst;
	while (nodo)
	{
		del(nodo->content);
		a = nodo->next;
		free(nodo);
		nodo = a;
	}
	*lst = NULL;
}
