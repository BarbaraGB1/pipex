/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:44:05 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/18 13:48:56 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while ((s[i] != '\0') && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	ft_len(char const *s, char c, int i)
{
	int	p;

	p = 0;
	while (s[i] != c && s[i] != '\0')
	{
		p++;
		i++;
	}
	return (p);
}

char	**ft_free(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free (str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	str = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!str)
		return (0);
	while (j < ft_count(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(s, i, ft_len(s, c, i));
		i += ft_len(s, c, i);
		if (!str[j])
			return (ft_free(str, j));
		j++;
	}
	str[j] = 0;
	return (str);
}
/*#include <stdio.h>
int main(void)
{
	
	char *s = " hola que tal";
	char c;
	int x;
	c = ' ';
	
x = ft_count(s, c);
	
	char **str;
	str = ft_split(s, c);
	while (*str != '\0')
	{
		printf("%s\n", *str);
		str++;
	}
}*/
