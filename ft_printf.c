/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 15:21:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-07-30 15:21:42 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_padding(unsigned long num)
{
	t_data	*data;

	data = *query();
	set_pad(num);
	if ((data->do_precision && data->precision) || !data->do_precision)
		print_base_to_mem(data->temp + data->pad - 1, data->value_base, num);
	data->p_i = data->value_length;
	handle_precision();
	handle_sign();
	handle_pointy();
	handle_leftsbound();
	return (1);
}

int	trigger_insert(va_list a)
{
	t_data	*data;

	data = *query();
	data->len = 0;
	while (data->format[data->i + data->len] && \
		!ft_strchr(data->format[data->i + data->len], "discuxXp%"))
	{
		read_flags();
		read_numbers();
		data->len += data->add;
	}
	if (data->format[data->i + data->len])
		data->insert_identifier = \
			*ft_strchr(data->format[data->i + data->len], "discuxXp%");
	data->skipped = data->len + 1;
	deligate_handlers(a);
	reset_flags();
	return (0);
}

int	sprint(va_list a)
{
	t_data	*data;
	int		i;

	data = *query();
	i = 0;
	while (data->format[i])
	{
		data = *query();
		if (data->format[i] != '%')
		{
			if (ft_putchar(data->format[i]) != 1)
				return (1);
		}
		else
		{
			data->i = i + 1;
			if (trigger_insert(a))
				return (1);
			data = *query();
			i += data->skipped;
		}
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_data	*data;
	va_list	a;

	if (ft_init(format))
		return (0);
	va_start(a, format);
	data = *query();
	if (!sprint(a))
		return (ft_close(data->written));
	va_end(a);
	ft_close(data->written);
	return (data->written);
}
