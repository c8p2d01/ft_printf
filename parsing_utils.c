/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 15:21:28 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-07-30 15:21:28 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_numbers(void)
{
	t_data	*data;

	data = *query();
	if (data->format[data->i + data->len] == '.')
	{
		data->precision = ft_atoi(&data->format[data->i + data->len + 1]);
		if (data->precision != 0)
			data->add += ft_log(data->precision, 10);
		if (data->format[data->i + data->len + 1] == '0')
			data->add++;
		data->do_precision = true;
	}
	if (ft_strchr(data->format[data->i + data->len], "123456789"))
	{
		data->do_width = true;
		data->width = ft_atoi(&data->format[data->i + data->len]);
		data->add = ft_log(data->width, 10);
	}
}

void	read_flags(void)
{
	t_data	*data;

	data = *query();
	data->add = 1;
	if (data->format[data->i + data->len] == ' ')
		data->do_sign = true;
	if (data->format[data->i + data->len] == '+')
		data->sign_positive = true;
	if (data->format[data->i + data->len] == '-')
		data->leftbound = true;
	if (data->format[data->i + data->len] == '#')
		data->pointer_prefix = true;
	if (data->format[data->i + data->len] == '0')
		data->padding_char = '0';
}

int	deligate_handlers(va_list a)
{
	t_data	*data;

	data = *query();
	if (data->insert_identifier == 'i' || data->insert_identifier == 'd')
		return (handle_d_i(a));
	if (data->insert_identifier == 'u')
		return (handle_u(a));
	if (data->insert_identifier == 'x')
		return (handle_big_x(a));
	if (data->insert_identifier == 'p')
		return (handle_p(a));
	if (data->insert_identifier == 'X')
		return (handle_big_x(a));
	if (data->insert_identifier == 'c')
		return (handle_c(a));
	if (data->insert_identifier == '%')
		return (handle_percent());
	if (data->insert_identifier == 's')
		return (handle_s(a));
}
