/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printD.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:31:13 by ecabaret          #+#    #+#             */
/*   Updated: 2024/05/09 14:41:33 by ecabaret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_print_d(int n)
{
	int	i;
	int	dest;

	dest = n;
	i = 1;
	if (dest < 0 && dest != -2147483648)
	{
		i = 2;
		dest = -dest;
	}
	else if (dest == -2147483648)
	{
		ft_putnbr_fd(n, 1);
		return (11);
	}
	while (dest > 9)
	{
		dest /= 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	return (i);
}

// int	main(void)
// {
// 	int	i;

// 	i = 102;
// 	ft_testprint_d(i);
// }
