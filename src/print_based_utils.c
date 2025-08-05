/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_based_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 19:11:59 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-08-05 19:11:59 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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
