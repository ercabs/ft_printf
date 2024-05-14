/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:59:17 by ecabaret          #+#    #+#             */
/*   Updated: 2024/05/14 11:16:57 by ecabaret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//print char
int		ft_printchar(char c);
//print decimal
int		ft_print_d(int num);
//fonct princ
int		ft_printf(const char *s, ...);
//print hexa
int		ft_printhex(unsigned int num, const char format);
//print string
int		ft_printstr(char *s);
//print unsigned int
int		ft_printuni(unsigned int num);
//print ptr
int		ft_printp(unsigned long long ptr);
//putnbr
void	ft_putnbr_fd(int n, int fd);

#endif