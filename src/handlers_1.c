/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 19:14:43 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-08-05 19:14:43 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	handle_padding(unsigned long num)
{
	t_data	*data;
	int		i;

	data = *query();
	set_pad(num);
	data->p_i = data->value_length;
	handle_precision();
	handle_sign();
	i = data->p_i;
	handle_pointy();
	handle_leftsbound();
	i = 0;
	while (data->temp && data->temp[i])
	{
		if (data->temp[i] == '@')
			data->temp[i] = ' ';
		if (!ft_putchar(data->temp[i]))
			return (0);
		i++;
	}
	return (1);
}

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
		data->padd_char = ' ';
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
		data->padd_char = ' ';
	return (handle_padding(num));
}

int	handle_percent(void)
{
	t_data	*data;

	data = *query();
	data->value_length = 1;
	data->do_precision = false;
	data->c = '%';
	data->width--;
	return (char_padding());
}
