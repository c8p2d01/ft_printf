/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 15:24:55 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-07-30 15:24:55 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(va_list a)
{
	t_data	*data;
	char	c;

	data = *query();
	c = va_arg(a, int);
	data->value_length = 1;
	data->do_precision = false;
	data->c = c;
	data->width--;
	return (char_padding((unsigned int)c));
}

int	handle_percent(void)
{
	t_data	*data;
	char	c;

	data = *query();
	data->value_length = 1;
	data->do_precision = false;
	data->c = '%';
	data->width--;
	return (char_padding((unsigned int)c));
}

int	handle_s(va_list a)
{
	t_data	*data;
	char	*s;

	data = *query();
	s = va_arg(a, char *);
	if (!s)
	{
		data->value_base = ft_strdup("(null)");
		s = data->value_base;
	}
	data->value_length = ft_strlen(s);
	data->string = s;
	if (data->precision > data->value_length && s)
		data->precision = data->value_length;
	if (!s && !data->do_precision)
		data->precision = 6;
	return (string_padding());
}
