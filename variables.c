/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 15:14:28 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-07-30 15:14:28 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	**query(void)
{
	static t_data	*data;

	return (&data);
}

int	reset_flags(void)
{
	t_data	*data;

	data = *query();
	if (data)
	{
		if (data->value_base)
			free(data->value_base);
		data->value_base = NULL;
		if (data->temp)
			free(data->temp);
		data->temp = NULL;
		data->string = NULL;
		data->c = '\r';
		reset_flags_extension();
	}
	else
		return (1);
	return (0);
}

int	reset_flags_extension(void)
{
	t_data	*data;

	data = *query();
	if (data)
	{
		data->do_sign = false;
		data->do_width = false;
		data->do_precision = false;
		data->sign_positive = false;
		data->is_negative = false;
		data->leftbound = false;
		data->padding_char = ' ';
		data->pointer_prefix = false;
		data->width = 0;
		data->precision = 0;
		data->pad = 0;
		data->p_i = 0;
		data->insert_identifier = '\0';
		data->value_length = 0;
	}
	else
		return (1);
	return (0);
}

int	ft_init(const char *format)
{
	t_data	*data;

	if (format)
	{
		*query() = malloc(sizeof(t_data));
		ft_bzero(*query(), sizeof(t_data));
		data = *query();
		data->format = (char *)format;
		data->insert = NULL;
		data->i = 0;
		data->skipped = 0;
		data->added = 0;
		data->written = 0;
		if (reset_flags())
			return (1);
		data->debug = false;
	}
	else
		return (1);
	return (0);
}

int	ft_close(int return_value)
{
	t_data	*data;

	data = *query();
	if (data)
	{
		if (data->value_base)
			free(data->value_base);
		data->value_base = NULL;
		free(data);
		*query() = NULL;
	}
	return (return_value);
}
