# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 10:58:34 by cdahlhof          #+#    #+#              #
#    Updated: 2022/07/17 00:55:35 by cdahlhof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJ_FILES = _putnbr_base.o _strlen.o\
			out_zhexa_big.o out_char.o out_hexa.o out_integer.o out_pointer.o out_string.o out_unsigned_integer.o \
			ft_printf.o out_spread.o
#SRC_FILES = _log.c ft_putnbr_base.c _strlen.c _ndigit.c\
			out_zhexa_big.c out_char.c out_hexa.c out_integer.c out_pointer.c out_string.c out_unsigned_integer.c \
			ft_printf.c out_spread.o
HEADER_FILES = ft_printf.h
CC = gcc

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

%.o: %.c $(HEADER_FILES)
	$(CC) -c -Wall -Werror -Wextra -o $@ $<

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f libftprintf.a

re: fclean all

.PHONY: all clean fclean re
