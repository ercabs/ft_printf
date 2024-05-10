/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:27:27 by ecabaret          #+#    #+#             */
/*   Updated: 2024/05/10 12:35:57 by ecabaret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static int	len_uni(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

int	ft_printuni(unsigned int n)
{
	int				i;
	int				x;
	char			*base;
	char			*dest;

	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	x = len_uni(n);
	i = 0;
	dest = malloc(sizeof(char) * (x + 1));
	base = "0123456789";
	while (n > 0)
	{
		dest[i] = base[n % 10];
		n /= 10;
		i ++;
	}
	dest[i] = '\0';
	while (i-- > 0)
		ft_printchar(dest[i]);
	free(dest);
	return (x);
}
