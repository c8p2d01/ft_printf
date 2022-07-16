/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_zhexa_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:30:38 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/17 00:47:34 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_zhexa_big(int nbr)
{
	if (nbr >= 0)
		return (ft_putnbr_base(nbr, "0123456789ABCDEF"));
	else
		return (ft_putnbr_base(nbr + 4294967296, "0123456789ABCDEF"));
}
