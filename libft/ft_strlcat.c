/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:49:10 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 19:41:55 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	x = ft_strlen(dst);
	if (dstsize <= x)
		return (ft_strlen(src) + dstsize);
	while (dst[i] != '\0' && i < (dstsize -1))
	{
		i++;
	}
	while (i < (dstsize - 1) && *src)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
