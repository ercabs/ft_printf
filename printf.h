/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:59:17 by ecabaret          #+#    #+#             */
/*   Updated: 2024/05/09 12:35:36 by ecabaret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

//array to int
int		ft_atoi(const char *str);
//int to array
char	*ft_itoa(int n);
//print char
int		ft_printchar(char c);
//print decimal
int		ft_print_d(int num);
//fonct princ
int		ft_printf(const char *s, ...);
//print hexa
int		ft_printhex(unsigned int num, const char format);
//print hexa MAJ
void	ft_printhexmaj(int n);
//print string
int		ft_printstr(char *s);
//print unsigned int
int		ft_printuni(unsigned int num);
//print ptr
int		ft_printp(void *num);
//putnbr
void	ft_putnbr_fd(int n, int fd);

#endif