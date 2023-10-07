/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:35:44 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/18 13:34:44 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src1;
	char	*dst1;

	src1 = (char *)src;
	dst1 = (char *)dst;
	i = 0;
	if (src1 == NULL && dst1 == NULL)
		return (NULL);
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}
/*#include <stdio.h>
int main(void)
{
	char dst = " ";
	const char src []= "adios";
	printf("%s", ft_memcpy(dst, src, 4));
}*/
