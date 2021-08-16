/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 20:48:11 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/16 13:48:01 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_pointer(void *i)
{
	write(1, "0x", 2);
	if ((long)i != 0)
		ft_putnbr_base((long)i, "0123456789abcdef");
	else
		write(1, "0", 1);
	if ((long)i != 0)
		return (14);
	return (3);
}
