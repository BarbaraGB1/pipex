/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:36:39 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 19:46:05 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	a;

	str = (char *)s;
	a = (char)c;
	i = ft_strlen(str);
	if (str[i] == a)
		return (&str[i]);
	i--;
	while (i >= 0)
	{
		if (str[i] == a)
			return (&str[i]);
		i--;
	}
	return (0);
}
/*int main(void)
{
	int c;
	c = 'l';
	const char str[]= "Hola lola";
	printf("%s", ft_strrchr(str, c));
	printf("%s", strrchr(str, c));
}*/
