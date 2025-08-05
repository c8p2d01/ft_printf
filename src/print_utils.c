/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 19:10:38 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-08-05 19:10:38 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putchar(char c)
{
	t_data	*data;

	data = *query();
	if (data->debug)
	{
		if (fwrite(&c, 1, 1, data->f) != 1)
			return (0);
	}
	else
	{
		if (write(1, &c, 1) != 1)
			return (0);
	}
	data->written++;
	return (1);
}

int	repeat_char(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!ft_putchar(c))
			return (0);
		i++;
	}
	return (1);
}

int	ft_putstr_null(void)
{
	t_data	*data;

	data = *query();
	if ((data->precision > 0 || !data->do_precision) && !ft_putchar('('))
		return (0);
	if ((data->precision > 1 || !data->do_precision) && !ft_putchar('n'))
		return (0);
	if ((data->precision > 2 || !data->do_precision) && !ft_putchar('u'))
		return (0);
	if ((data->precision > 3 || !data->do_precision) && !ft_putchar('l'))
		return (0);
	if ((data->precision > 4 || !data->do_precision) && !ft_putchar('l'))
		return (0);
	if ((data->precision > 5 || !data->do_precision) && !ft_putchar(')'))
		return (0);
	return (1);
}

int	ft_putstr_case(char *s)
{
	int		i;
	t_data	*data;

	data = *query();
	if (!s)
		ft_putstr_null();
	i = 0;
	while (s && s[i] && (data->precision > i || !data->do_precision))
	{
		if (!ft_putchar(s[i]))
			return (0);
		i++;
	}
	return (1);
}
