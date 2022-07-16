/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:25:13 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/17 00:51:39 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_integer(long i)
{
	if (i >= 0)
	{
		return (ft_putnbr_base((long)i, "0123456789"));
	}
	write(1, "-", 1);
	i *= -1;
	return (1 + ft_putnbr_base((long)i, "0123456789"));
}
