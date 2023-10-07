/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:18:06 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 19:33:46 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	a;
	size_t			i;

	str = (unsigned char *)b;
	a = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = a;
		i++;
	}
	return (str);
}
