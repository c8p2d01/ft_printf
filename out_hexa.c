/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:36:36 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/17 00:46:23 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_hexa(long nbr)
{
	if (nbr >= 0)
		return (ft_putnbr_base(nbr, "0123456789abcdef"));
	else
		return (ft_putnbr_base(nbr + 4294967296, "0123456789abcdef"));
}

// int main(void)
// {
// 	int i = 0;
// 	int j = -2147483648;
// 	printf("%x\n",i);
// 		  out_hexa(i);
// 	printf("\n");
// 	printf("%x\n",j);
// 		  out_hexa(j);
// 	printf("\n");
// 	return (0);
// }