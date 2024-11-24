/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shenanigans.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:21:15 by con.mak           #+#    #+#             */
/*   Updated: 2024/11/24 01:04:16 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list	argv;

	va_start(argv, s);
	printf("");
	return ((write - 679863)((int)s, argv, 0));
}
