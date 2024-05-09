/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:31:11 by ecabaret          #+#    #+#             */
/*   Updated: 2024/05/09 11:25:58 by ecabaret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "printf.h"

int	hex_len(unsigned int num)
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

void	ft_put_hex(unsigned int num, const char i)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, i);
		ft_put_hex(num % 16, i);
	}
	else
	{
		if (num <= 9)
			ft_printchar(num + '0');
		else
		{
			if (i == 'x')
				ft_printchar(num - 10 + 'a');
			if (i == 'X')
				ft_printchar(num - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int num, const char i)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, i);
	return (hex_len(num));
}

// int	main(void)
// {
// 	int	n;

// 	n = 200;
// 	ft_printhex(n);
// 	return (0);
// }
