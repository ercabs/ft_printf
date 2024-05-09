# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecabaret <ecabaret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 13:20:00 by ecabaret          #+#    #+#              #
#    Updated: 2024/05/09 12:36:59 by ecabaret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
NAME := libftprintf.a
SRC := \
	ft_atoi.c\
	ft_itoa.c\
	ft_printchar.c\
	ft_printD.c\
	ft_printf.c\
	ft_printhex.c\
	ft_printp.c\
	ft_printstr.c\
	ft_printuni.c\
	ft_putnbr_fd.c
OBJ :=\
	ft_atoi.o\
	ft_itoa.o\
	ft_printchar.o\
	ft_printD.o\
	ft_printf.o\
	ft_printhex.o\
	ft_printp.o\
	ft_printstr.o\
	ft_printuni.o\
	ft_putnbr_fd.o
	
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libfprintf.a

re: fclean all

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -c