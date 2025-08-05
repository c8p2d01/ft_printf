/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 19:16:00 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-08-05 19:16:00 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	handle_x(va_list a)
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
		data->padd_char = ' ';
	if (num && data->value_length > data->precision)
		data->precision = data->value_length;
	data->width -= (data->do_sign || data->sign_positive);
	if (num && data->pointer_prefix)
		data->width -= 2;
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
		data->padd_char = ' ';
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
	return (char_padding());
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
