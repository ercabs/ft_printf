/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:40:53 by ecabaret          #+#    #+#             */
/*   Updated: 2024/05/14 11:37:57 by ecabaret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include <stddef.h>

#include <stdio.h>
#include "ft_printf.h"

int	check(va_list arg, char i)
{
	int	len;

	len = 0;
	if (i == 'c')
		len += ft_printchar(va_arg(arg, int));
	else if (i == 's')
		len += ft_printstr(va_arg(arg, char *));
	else if (i == 'p')
		len += ft_printp(va_arg(arg, unsigned long long));
	else if (i == 'd' || i == 'i')
		len += ft_print_d(va_arg(arg, int));
	else if (i == 'u')
		len += ft_printuni(va_arg(arg, unsigned int));
	else if (i == 'x' || i == 'X')
		len += ft_printhex(va_arg(arg, unsigned int), i);
	else if (i == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	if (s == NULL)
		return (-1);
	va_start (args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += check(args, s[i + 1]);
			i++;
		}
		else
			len += ft_printchar(s[i]);
		i++;
	}
	va_end (args);
	return (len);
}

int	main(void)
{
	int	test;

	test = 0;
	ft_printf("TEST INT : \n  test de int : %i \n", -10);
	printf("  vrai test : %i \n", -10);
	ft_printf("TEST CHAR : \n  test de char : %c \n", 'c');
	printf("  Vrai test %c \n", 'c');
	ft_printf("TEST STR : \n  test des str : %s \n", "coucou c'est moi");
	printf("  vrai test : %s \n ", "coucou c'est moi");
	ft_printf("TEST DECIMAL : \n  test de decimal : %d \n", 11);
	printf("  vrai test : %d \n", 11);
	ft_printf("TEST PTR : \n  test de ptr :  %p \n", &test);
	printf("  vrai test ptr : %p \n", &test);
	ft_printf("TEST UNI : \n  test de uni : %u \n", 25);
	printf("  vrai test : %u \n", 25);
	ft_printf("TEST HEXA : \n  test hexa min : %x \n", 200);
	printf("  vrai test hexa min : %x \n", 200);
	ft_printf("  test hexa MAJ : %X \n", 201);
	printf("  vrai test hexa MAJ : %X \n", 201);
	ft_printf("TEST %% : \n  test de %% \n");
	printf("  vrai test de %% \n");
}
