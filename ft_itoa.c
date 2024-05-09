/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:21:34 by ecabaret          #+#    #+#             */
/*   Updated: 2024/05/09 12:47:17 by ecabaret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include "printf.h"

static int	ft_itoa_size(int n)
{
	int	temp;
	int	i;

	temp = n;
	i = 1;
	if (n == -2147483648)
	{
		i = 11;
		return (i);
	}
	while (temp <= -10 || temp >= 10)
	{
		temp = temp / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

static char	*write_itoa(int n, int len, int i)
{
	char	*dest;

	dest = malloc((len + 1) * sizeof(char));
	if (n == -2147483648)
	{
		dest[0] = '-';
		dest[1] = '2';
		n = 147483648;
		i = 2;
	}
	if (n < 0)
	{
		dest[0] = '-';
		n = -n;
		i++;
	}
	dest[len] = '\0';
	while (i < len)
	{
		len--;
		dest[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;

	len = ft_itoa_size(n);
	dest = write_itoa(n, len, 0);
	if (!dest)
		return (NULL);
	return (dest);
}

// int	main(void)
// {
// 	int	t;

// 	t = -2147483648;
// 	printf("%s \n", ft_itoa(t));
// }
//int min: -2147483648
//int max: 2147483647