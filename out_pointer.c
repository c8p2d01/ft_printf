/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 20:48:11 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/17 00:53:16 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_pointer(unsigned long i)
{
	write(1, "0x", 2);
	return (ft_putnbr_base(i, "0123456789abcdef") + 2);
}

// // goal : numbers up to 18446744073709551615 and from -9223372036854775808
// #include <stdio.h>
// int main()
// {
// 	int r, m;
// 	unsigned long p = 18446744073709551615;
// 	m = out_pointer(p);
// 	printf("\n%i\n", m);
// 	r = printf("%p", p);
// 	printf("\n%i\n", r);
// }