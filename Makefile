# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 10:58:34 by cdahlhof          #+#    #+#              #
#    Updated: 2021/08/16 13:46:06 by cdahlhof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJ_FILES = _putnbr_base.o _strlen.o _ndigit.o\
			out_zhexa_big.o out_char.o out_hexa.o out_integer.o out_pointer.o out_string.o out_unsigned_integer.o \
			ft_printf.o out_spread.o
#SRC_FILES = ft_putnbr_base.c _strlen.c _ndigit.c\
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
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re
