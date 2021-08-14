/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:36:09 by clems             #+#    #+#             */
/*   Updated: 2021/08/14 10:59:34 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// count the number of digits in the given number
size_t	ft_ndigit(size_t n)
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
