/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:22:33 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 19:45:41 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*b;

	i = 0;
	a = (char)c;
	b = (char *)s;
	while (b[i] != '\0')
	{
		if (b[i] == a)
			return (&b[i]);
		i++;
	}
	if (b[i] == a)
		return (&b[i]);
	return (0);
}
/*int main(void)
{
	int	c;
	c = 'l';
	const char str[] = "¡Hola, mundo!";
	printf("%s", ft_strchr(str, c));
	int	j;
	j = 'l';
	const char str2[] = "¡Hola, mundo!";
	printf("%s", strchr(str2, j));
}*/
