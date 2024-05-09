/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:10:14 by ecabaret          #+#    #+#             */
/*   Updated: 2024/05/08 13:51:14 by ecabaret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "printf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	n;

	i = 0;
	n = 1;
	nb = 0;
	while ((str[i] && str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] -48);
		i++;
	}
	nb = nb * n;
	return (nb);
}
// int	main(void)
// {
// 	char *c = "+-1245";
// 	printf("result : %d \n", ft_atoi(c));
// }
