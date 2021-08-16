/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ndigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:44:31 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/15 20:58:51 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	_ndigit(size_t n)
{
	size_t	i;
	size_t	p;

	p = 1;
	i = 10;
	while (i > 0)
	{
		if ((n % i) == n)
			return (p);
		i *= 10;
		p++;
	}
	return (p);
}