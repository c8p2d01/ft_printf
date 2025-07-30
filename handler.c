/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 15:24:48 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-07-30 15:24:48 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_d_i(va_list a)
{
	t_data	*data;
	long	val;
	int		num;

	data = *query();
	val = va_arg(a, int);
	num = val;
	if (val < 0)
	{
		data->is_negative = true;
		num = -val;
	}
	data->value_base = ft_strdup("0123456789");
	data->value_length = ft_log((unsigned int)num, 10);
	if (num && data->value_length > data->precision)
		data->precision = data->value_length;
	if (data->do_precision)
		data->padding_char = ' ';
	data->width -= (data->do_sign || data->sign_positive || data->is_negative);
	return (handle_padding((unsigned int)num));
}

int	handle_u(va_list a)
{
	t_data			*data;
	unsigned int	num;

	data = *query();
	num = va_arg(a, int);
	data->value_base = ft_strdup("0123456789");
	data->value_length = ft_log(num, 10);
	data->width -= (data->do_sign || data->sign_positive);
	if (num && data->value_length > data->precision)
		data->precision = data->value_length;
	if (data->do_precision)
		data->padding_char = ' ';
	return (handle_padding(num));
}

int	handle_big_x(va_list a)
{
	t_data			*data;
	unsigned int	num;

	data = *query();
	num = va_arg(a, int);
	if (!num)
		data->pointer_prefix = false;
	data->value_base = ft_strdup("0123456789abcdef");
	data->value_length = ft_log(num, 16);
	if (data->do_precision)
		data->padding_char = ' ';
	if (num && data->value_length > data->precision)
		data->precision = data->value_length;
	data->width -= (data->do_sign || data->sign_positive);
	if (num && data->pointer_prefix)
		data->width -= 2;
	return (handle_padding(num));
}

int	handle_p(va_list a)
{
	t_data			*data;
	unsigned long	num;

	data = *query();
	num = va_arg(a, unsigned long);
	data->do_width = false;
	data->width -= 2;
	data->pointer_prefix = true;
	data->value_base = ft_strdup("0123456789abcdef");
	data->value_length = ft_log(num, 16);
	if (data->value_length > data->precision)
		data->precision = data->value_length;
	data->width -= (data->do_sign || data->sign_positive);
	return (handle_padding(num));
}

int	handle_big_x(va_list a)
{
	t_data			*data;
	unsigned int	num;

	data = *query();
	num = va_arg(a, int);
	if (!num)
		data->pointer_prefix = false;
	data->value_base = ft_strdup("0123456789ABCDEF");
	data->value_length = ft_log(num, 16);
	if (data->do_precision)
		data->padding_char = ' ';
	if (num && data->value_length > data->precision)
		data->precision = data->value_length;
	data->width -= (data->do_sign || data->sign_positive);
	if (num && data->pointer_prefix)
		data->width -= 2;
	return (handle_padding(num));
}
