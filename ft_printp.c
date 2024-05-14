/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:57:21 by ecabaret          #+#    #+#             */
/*   Updated: 2024/05/14 11:36:59 by ecabaret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <inttypes.h>

int	ft_lenp(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_printchar((num + '0'));
		else
			ft_printchar((num - 10 + 'a'));
	}
}

int	ft_printp(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		len += write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		len += write(1, "0x", 2);
		ft_put_ptr(ptr);
		len += ft_lenp(ptr);
	}
	return (len);
}

// int	main(void)
// {
// 	int	n;

// 	n = 200;
// 	ft_printp(n);
// 	return (0);
// }
