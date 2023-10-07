/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:23:39 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/18 13:39:58 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;
	char	*src1;

	src1 = (char *)src;
	x = ft_strlen(src1);
	i = 0;
	if (dstsize != 0)
	{
		while (src1[i] != '\0' && i < dstsize -1)
		{
				dst[i] = src1[i];
				i++;
		}
		dst[i] = '\0';
	}
	return (x);
}
