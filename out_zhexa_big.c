/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_zhexa_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:30:38 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/16 14:08:54 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_zhexa_big(int nbr)
{
	if (nbr >= 0)
		ft_putnbr_base(nbr, "0123456789ABCDEF");
	else
	{
		ft_putnbr_base(nbr + 4294967296, "0123456789ABCDEF");
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
