/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 15:25:27 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-07-30 15:25:27 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_pad(unsigned long num)
{
	t_data	*data;

	data = *query();
	if (num || !data->do_precision)
		data->pad = data->value_length;
	if (data->precision > data->pad)
		data->pad = data->precision;
	if (data->width > data->pad)
		data->pad = data->width;
	if (data->pad && data->precision == 0 && data->do_precision == true && \
												data->do_width == false)
		data->pad--;
	if (data->is_negative || data->do_sign || data->sign_positive)
		data->pad++;
	if (data->pointer_prefix)
		data->pad += 2;
	data->temp = malloc(data->pad + 1);
	ft_memset(data->temp, '@', data->pad + 1);
	data->temp[data->pad] = '\0';
}

void	handle_precision(void)
{
	t_data	*data;

	data = *query();
	while (data->p_i < data->precision)
	{
		*ft_strrchr(data->temp, '@') = '0';
		data->p_i++;
	}
	while (data->p_i < data->width && data->padding_char == '0')
	{
		*ft_strrchr(data->temp, '@') = '0';
		data->p_i++;
	}
}

void	handle_sign(void)
{
	t_data	*data;

	data = *query();
	if (data->is_negative && !data->pointer_prefix)
	{
		*ft_strrchr(data->temp, '@') = '-';
		data->p_i++;
	}
	else if (data->sign_positive && !data->pointer_prefix)
	{
		*ft_strrchr(data->temp, '@') = '+';
		data->p_i++;
	}
	else if (data->do_sign && !data->pointer_prefix)
	{
		*ft_strrchr(data->temp, '@') = ' ';
		data->p_i++;
	}
}

void	handle_pointy(void)
{
	t_data	*data;

	data = *query();
	if (data->pointer_prefix && ft_strchr(data->insert_identifier, "pxX"))
	{
		if (data->insert_identifier == 'X')
			*ft_strrchr(data->temp, '@') = 'X';
		else
			*ft_strrchr(data->temp, '@') = 'x';
		data->p_i++;
		*ft_strrchr(data->temp, '@') = '0';
		data->p_i++;
	}
}

void	handle_leftsbound(void)
{
	t_data	*data;

	data = *query();
	data->p_i = 0;
	while (data->temp && data->temp[data->p_i])
	{
		if (data->temp[data->p_i] == '@')
			data->temp[data->p_i] = ' ';
		if (!ft_putchar(data->temp[data->p_i]))
			return (0);
		data->p_i++;
	}
}
