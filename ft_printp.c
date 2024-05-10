/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:57:21 by ecabaret          #+#    #+#             */
/*   Updated: 2024/05/09 14:41:50 by ecabaret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>

static int	ft_size_of_ptr(unsigned long long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

static int	ft_write_ptr(uintptr_t ptr)
{
	unsigned long long		i;
	unsigned long long		n;
	char					*dest;
	char					*base_hexa;

	i = 0;
	n = (unsigned long long)ptr;
	dest = malloc(sizeof(char) * (ft_size_of_ptr(n) + 1));
	base_hexa = "0123456789abcdef";
	while (n > 0)
	{
		dest[i] = base_hexa[n % 16];
		n /= 16;
		i ++;
	}
	dest[i] = '\0';
	n = i;
	while (i > 0)
	{
		i --;
		ft_printchar(dest[i]);
	}
	free(dest);
	return ((int)n + 2);
}

int	ft_printp(void *ptr)
{
	uintptr_t	n;

	n = (uintptr_t)ptr;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		return (ft_write_ptr(n));
	}
}

// int	main(void)
// {
// 	int	n;

// 	n = 200;
// 	ft_printp(n);
// 	return (0);
// }
