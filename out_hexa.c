/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:36:36 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/16 14:08:21 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_hexa(int nbr)
{
	if (nbr >= 0)
		ft_putnbr_base(nbr, "0123456789abcdef");
	else
	{
		ft_putnbr_base(nbr + 4294967296, "0123456789abcdef");
	}
	if (nbr >= 0 && nbr < 16)
		return (1);
	if (nbr > 0 && nbr < 256)
		return (2);
	if (nbr > 0 && nbr < 4096)
		return (3);
	if (nbr > 0 && nbr < 65536)
		return (4);
	if (nbr > 0 && nbr < 1048576)
		return (5);
	if (nbr > 0 && nbr < 16777216)
		return (6);
	if (nbr > 0 && nbr < 268435456)
		return (7);
	return (8);
}

	// if (nbr < 16 || (nbr < 0 && nbr > -16))
	// 	return (1);
	// if (nbr < 256 || (nbr < 0 && nbr > -256))
	// 	return (2);
	// if (nbr < 4096 || (nbr < 0 && nbr > -4096))
	// 	return (3);
	// if (nbr < 65536 || (nbr < 0 && nbr > -65536))
	// 	return (4);
	// if (nbr < 1048576 || (nbr < 0 && nbr > -1048576))
	// 	return (5);
	// if (nbr < 16777216 || (nbr < 0 && nbr > -16777216))
	// 	return (6);
	// if (nbr < 268435456 || (nbr < 0 && nbr > -268435456))

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