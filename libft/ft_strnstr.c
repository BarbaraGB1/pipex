/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:05:03 by bargarci          #+#    #+#             */
/*   Updated: 2023/03/17 17:42:21 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	p;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		p = 0;
		while (haystack[i + p] == needle[p] && (i + p) < len)
		{
			if (needle[p + 1] == '\0')
				return ((char *)&haystack[i]);
			p++;
		}
		i++;
	}
	return (0);
}
