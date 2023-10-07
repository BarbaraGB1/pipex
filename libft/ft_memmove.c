/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:07:02 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 19:40:14 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;

	i = 0;
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	if (src == dst || len == 0)
		return (dst);
	if (dst > src)
	{
		while (len-- > 0)
		{
			dst1[len] = src1[len];
		}
	}
	else
	{
		while (i < len)
		{
		dst1[i] = src1[i];
		i++;
		}
	}
	return (dst);
}
/*#include <stdio.h>
int main(void)
{
	char dst[] = "hola1";
	const char src[] = "hola2";
//	size_t len = 3;
	printf("%s",ft_memmove(dst, src, 8));
}*/
