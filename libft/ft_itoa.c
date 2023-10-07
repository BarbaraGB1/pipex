/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:07:19 by bargarci          #+#    #+#             */
/*   Updated: 2023/04/17 20:02:27 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_len1(int n)
{
	int	len;
	int	number;

	len = 0;
	number = n;
	if (number <= 0)
	{
		len ++;
		number = -number;
	}
	while (number != 0)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		number;

	len = ft_len1(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	number = n;
	str[len--] = '\0';
	if (number < 0)
	{
		number = -number;
		str[0] = '-';
	}
	if (number == 0)
		str[0] = '0';
	while (number != 0)
	{
		str[len--] = (number % 10) + 48;
		number = number / 10;
	}
	return (str);
}
/*#include "stdio.h"
int main(void)
{
int num = -10;
    char *str = ft_itoa(num);

    printf("El número %d convertido a una cadena es: %s\n", num, str);
  int num2 = -1238;
    char *str2 = ft_itoa(num2);

    printf("El número %d convertido a una cadena es: %s\n", num2, str2);
   
    return 0;
}*/
