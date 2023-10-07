/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:29:17 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/18 15:46:13 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	lens;

	i = (size_t)start;
	j = 0;
	if (!s)
		return (0);
	lens = ft_strlen(s);
	if ((len > lens) || ((start + len) > lens))
		len = ft_strlen(s) - start;
	if (start >= lens)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
/*int main(void)
{
char	s[] = "tripouille";
unsigned int	start = 0;
size_t	len = 42000;
printf("%s", ft_substr(s, start, len));
}*/
