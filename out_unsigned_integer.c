/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_unsigned_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:37:00 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/15 20:59:27 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_unsigned_integer(unsigned int nbr)
{
	if (nbr >= 0)
		ft_putnbr_base(nbr, "0123456789");
	else
		ft_putnbr_base((4294967296 + nbr), "0123456789");
	if (nbr >= 0)
		return (_ndigit(nbr));
	return (_ndigit(4294967296 + nbr));
}

// int main(void)
// {
// 	int i = -100000;
// 	printf("%u\n",i);
// 	out_unsigned_integer(i);
// 	printf("\n");
// 	return (0);
// }