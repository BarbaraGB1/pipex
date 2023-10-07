/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:55:15 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 19:55:40 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_first(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_second(char const *s1, char const *set)
{
	size_t	j;

	j = ft_strlen(s1);
	while (j > 0)
	{
		if (ft_strchr(set, s1[j]) == 0)
			return (j + 1);
		j--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	finish;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = ft_first(s1, set);
	finish = ft_second(s1, set);
	if (start >= finish)
		return (ft_strdup(""));
	else
	{
		return (ft_substr(s1, start, (finish - start)));
	}
}
/*#include <stdio.h>
int main(void)
{
	char const *s1 = "//AAhola//AA";
	char const *set = "/A";

	printf("%s",ft_strtrim(s1, set));
}*/
