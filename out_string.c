/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:31:38 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/17 00:57:36 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_string(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (write(1, s, ft_strlen(s)));
}
