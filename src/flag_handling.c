/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 19:13:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-08-05 19:13:42 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	set_pad(unsigned long num)
{
	t_data	*data;
	int		pad;

	data = *query();
	pad = 0;
	if (num || !data->do_precision)
		pad = data->value_length;
	if (data->precision > pad)
		pad = data->precision;
	if (data->width > pad)
		pad = data->width;
	if (pad && data->precision == 0 && data->do_precision == true && \
														data->do_width == false)
		pad--;
	if (data->is_negative || data->do_sign || data->sign_positive)
		pad++;
	if (data->pointer_prefix)
		pad += 2;
	data->temp = malloc(pad + 1);
	ft_memset(data->temp, '@', pad + 1);
	data->temp[pad] = '\0';
	if ((data->do_precision && data->precision) || !data->do_precision)
		print_base_to_mem(data->temp + pad - 1, data->value_base, num);
	data->pad = pad;
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
	while (data->p_i < data->width && data->padd_char == '0')
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
	if (data->leftbound && data->p_i < data->pad)
	{
		ft_memcpy(data->temp, ft_strrchr(data->temp, '@') + 1, \
									ft_strlen(ft_strrchr(data->temp, '@') + 1));
		while (data->p_i < data->pad)
		{
			data->temp[data->p_i] = ' ';
			data->p_i++;
		}
	}
}
