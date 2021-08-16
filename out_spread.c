/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_spread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 20:45:53 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/16 13:47:20 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_spread(int n, va_list ap)
{
	if (n == 1)
		return (out_char((char)va_arg(ap, int)));
	else if (n == 2)
		return (out_hexa(va_arg(ap, int)));
	else if (n == 3)
		return (out_integer(va_arg(ap, int)));
	else if (n == 4)
		return (out_pointer(va_arg(ap, void *)));
	else if (n == 5)
		return (out_string(va_arg(ap, char *)));
	else if (n == 6)
		return (out_unsigned_integer(va_arg(ap, unsigned int)));
	else if (n == 7)
		return (out_char('%'));
	else if (n == 8)
		return (out_zhexa_big(va_arg(ap, int)));
	return (-2147483648);
}
