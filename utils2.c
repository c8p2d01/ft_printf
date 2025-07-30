/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 15:25:07 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-07-30 15:25:07 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c;
	size_t			i;

	c = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		c[i] = '\0';
		i++;
	}
}

void	ft_memset(void *s, char r, size_t n)
{
	unsigned char	*c;
	size_t			i;

	c = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		c[i] = r;
		i++;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	if (!dest && !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int	ft_log(unsigned long num, int base)
{
	int	digits;

	digits = 0;
	if (num <= 0)
		digits++;
	while (num)
	{
		digits++;
		num = num / base;
	}
	return (digits);
}
