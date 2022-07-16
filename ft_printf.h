/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 20:28:03 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/17 00:50:30 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// write a given integer represented in a different clean base
int		ft_putnbr_base(unsigned long nbr, char *base);
// return the length of an char array
size_t	ft_strlen(const char *str);

// write a given character
int		out_char(char c);
// write a given hexadecimal integer
int		out_hexa(long nbr);
// write a given decimal integer
int		out_integer(long i);
// write a given adress
int		out_pointer(unsigned long i);
// write a given string
int		out_string(char *s);
// write a given unsigned integer
int		out_unsigned_integer(unsigned int nbr);
// write a given hexadecimal integer (Big characters)
int		out_zhexa_big(int nbr);
// deligate the argument given to its proper output function
int		out_spread(int n, va_list ap);

//check if there is an indicator flag at the current position
int		indcheck(const char *str);
//check if and what kind of indicator (flag) is at the current position
int		indidentify(const char *str);
//main function call
int		ft_printf(const char *str, ...);
#endif