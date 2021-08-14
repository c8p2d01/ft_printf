# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 10:58:34 by cdahlhof          #+#    #+#              #
#    Updated: 2021/08/14 11:45:49 by cdahlhof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJ_FILES = ft_atoi.o ft_itoa.o ft_ndigit.o ft_putnbr_base.o ft_putnbr.o ft_putstr.o ft_tolower.o ft_toupper.o pf_utils.o
#SRC_FILES = ft_atoi.c ft_itoa.c ft_ndigit.c ft_putnbr_base.c ft_putnbr.c ft_putstr.c ft_tolower.c ft_toupper.c pf_utils.c
HEADER_FILES = printf.h
#CC = gcc

all: $(Name)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER_FILES)
	$(CC) -c -Wall -Werror -Wextra -o $@ $<

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re
