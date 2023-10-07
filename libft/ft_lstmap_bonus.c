/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:53:23 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 20:56:59 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iter;
	t_list	*new_node;
	t_list	*map;
	void	*content;

	iter = lst;
	if (!iter || !f || !del)
		return (0);
	map = NULL;
	while (iter)
	{
		content = f(iter->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&map, del);
			return (0);
		}
		ft_lstadd_back(&map, new_node);
		iter = iter->next;
	}
	return (map);
}
