/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:25:13 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/16 11:37:13 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_integer(long i)
{
	if (i >= 0)
	{
		ft_putnbr_base((long)i, "0123456789");
		return (_ndigit((long)i));
	}
	else
	{
		write(1, "-", 1);
		i *= -1;
		ft_putnbr_base((long)i, "0123456789");
		return (1 + _ndigit((long)i));
	}
}
