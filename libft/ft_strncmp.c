/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:02:48 by bargarci          #+#    #+#             */
/*   Updated: 2023/03/21 20:41:55 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && (i < n -1) && str1[i])
		i++;
	return (str1[i] - str2[i]);
}
/*#include<stdio.h>
#include<string.h>
int	main(void)
{   char s1[] = "ahste";
	char s2[] = "qwert";
	unsigned int	n;

	n = 3;

	printf("%d",ft_strncmp(s1, s2, n));
	printf("%d",strncmp(s1, s2, n));
}*/
