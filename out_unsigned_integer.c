/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_unsigned_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:37:00 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/17 00:47:03 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_unsigned_integer(unsigned int nbr)
{
	return (ft_putnbr_base(nbr, "0123456789"));
}

// int main(void)
// {
// 	int i = -100000;
// 	printf("%u\n",i);
// 	out_unsigned_integer(i);
// 	printf("\n");
// 	return (0);
// }