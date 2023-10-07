/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:50:30 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 20:50:49 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nodotemp;

	if (!new)
		return ;
	nodotemp = *lst;
	if (!nodotemp)
		*lst = new;
	else
	{
		while (nodotemp->next != '\0')
			nodotemp = nodotemp->next;
		nodotemp->next = new;
	}
}
