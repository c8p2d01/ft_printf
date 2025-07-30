/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 15:25:13 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-07-30 15:25:13 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num * sign);
}

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
	int	i;

	i = 0;
	while (i < n)
	{
		if (!ft_putchar(c))
			return (0);
		i++;
	}
	return (1);
}

int	print_base(char *base, unsigned long nbr)
{
	int	i;
	int	error;
	int	baselen;

	i = 0;
	baselen = ft_strlen(base);
	if (!baselen)
		base = "0123456789";
	if (nbr >= (unsigned long)ft_strlen(base))
	{
		error = print_base(base, nbr / ft_strlen(base));
		if (error < 0)
			return (-1);
		i += error;
	}
	error = ft_putchar(base[(nbr % ft_strlen(base))]);
	if (error < 0)
		return (-1);
	return (error + i);
}

/**
 * ALERT this function is highly unsstable and relies
 * on the memory to be allocated and iterates starting in the end
 */
void	print_base_to_mem(char *dest, char *base, unsigned long nbr)
{
	int	i;
	int	baselen;

	i = 0;
	baselen = ft_strlen(base);
	if (!baselen)
		base = "0123456789";
	if (nbr >= (unsigned long)ft_strlen(base))
	{
		print_base_to_mem(dest - 1, base, nbr / ft_strlen(base));
	}
	*dest = base[(nbr % ft_strlen(base))];
}
