/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 19:12:37 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-08-05 19:12:37 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	string_padding_continuance(void)
{
	t_data	*data;
	int		i;

	data = *query();
	i = 0;
	while (data->string && data->string[i] && \
			(data->precision > i || !data->do_precision))
	{
		if (!ft_putchar(data->string[i]))
			return (0);
		i++;
	}
	if (data->leftbound && (data->width > i))
	{
		if (!repeat_char(' ', data->width - i))
			return (0);
	}
	return (1);
}

int	string_padding(void)
{
	t_data	*data;

	data = *query();
	if (!data->leftbound)
	{
		if (data->do_precision && (data->width > data->precision))
		{
			if (!repeat_char(data->padd_char, data->width - data->precision))
				return (0);
		}
		else if (!data->do_precision && (data->width > data->value_length))
		{
			if (!repeat_char(data->padd_char, data->width - data->value_length))
				return (0);
		}
	}
	string_padding_continuance();
	return (1);
}

int	char_padding_extension(void)
{
	t_data	*data;

	data = *query();
	if (data->is_negative)
		ft_putchar('-');
	else if (data->insert_identifier == 'c' || data->insert_identifier == '%')
		ft_putchar(data->c);
	if (data->leftbound && data->do_width && (data->width > data->precision))
	{
		if (!repeat_char(' ', data->width - data->precision))
			return (0);
	}
	return (1);
}

int	char_padding(void)
{
	t_data	*data;

	data = *query();
	if (!data->leftbound && data->do_width && (data->width > data->precision))
	{
		if (data->padd_char == '0' && data->is_negative)
		{
			ft_putchar('-');
			data->is_negative = false;
		}
		if (!repeat_char(data->padd_char, data->width - data->precision))
			return (0);
	}
	if (data->do_precision && data->precision > data->value_length)
	{
		if (data->is_negative)
		{
			ft_putchar('-');
			data->is_negative = false;
		}
		if (!repeat_char('0', data->precision - data->value_length))
			return (0);
	}
	char_padding_extension();
	return (1);
}
