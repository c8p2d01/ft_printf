/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:31:09 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/17 00:57:43 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	indidentify(const char *str)
{
	if (str[0] == '%')
	{
		if (str[1] == 'c')
			return (1);
		else if (str[1] == 'x')
			return (2);
		else if (str[1] == 'i' || str[1] == 'd')
			return (3);
		else if (str[1] == 'p')
			return (4);
		else if (str[1] == 's')
			return (5);
		else if (str[1] == 'u')
			return (6);
		else if (str[1] == '%')
			return (7);
		else if (str[1] == 'X')
			return (8);
	}
	return (0);
}

// 0 -> normal
// 1 -> char
// 2 -> hexa
// 3 -> integer & decimal
// 4 -> pointer
// 5 -> string
// 6 -> unsigned integer
// 7 -> %
// 8 -> Big Hexa
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		n;
	int		total;

	i = -1;
	n = 0;
	total = 0;
	va_start(ap, str);
	while (str[++i] && n >= 0)
	{
		n = indidentify(&str[i]);
		if (n == 0)
		{
			write(1, str + i, 1);
			total++;
			continue ;
		}
		else
		{
			total += out_spread(n, ap);
			i++;
		}
	}
	return (total);
}

// // make && gcc -Wall -Werror -Wextra ft_printf.c libftprintf.a && ./a.out
// // "%i\t%d\t%c\t%s\t%x\t%X\t%%\t%p\n"
// // , 42, -42, 'F', "I hate my life", 42, 2147483647, NULL
// #include <stdio.h>
// int	main()
// {
// 	int out;
// 	int real;
// 	real = printf("%i\t%d\t%c\t%s\t%x\t%X\t%%\t%p\n"
// 				, 42, -42, 'F', "I hate my life", 42, 2147483647, NULL);
// 	printf("%i\n", real);
// 	out = ft_printf("%i\t%d\t%c\t%s\t%x\t%X\t%%\t%p\n"
// 					, 42, -42, 'F', "I hate my life", 42, 2147483647, NULL);
// 	printf("%i\n", out);
// 	return (0);
// }
