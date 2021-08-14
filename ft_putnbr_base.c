/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:02:28 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/14 13:00:38 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** basic strategy here:
**
** check wheather the base input is valid
**  - it has only usable characters
**  - it has no character twice
**  - it is not empty
**
** while the numberlength is not one
** iterate rcusivly trying to print (one less digit)
** print current digit as position in base string "base[(nbr % 10)]"
**
** done
*/

#include "printf.h"

int	base_check(char *str)
{
	int	i;
	int	c;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ('a' > str[i] && str[i] > 'z')
			if ('A' > str[i] && str[i] > 'Z')
				if ('0' > str[i] && str[i] > 'Z')
					return (0);
		c = i + 1;
		while (str[c])
		{
			if (str[i] == str[c])
				return (0);
			c++;
		}
		i++;
	}
	return (i);
}

void	print_base(char *base, long nbr)
{
	if (nbr > ft_strlen(base))
		print_base(base, nbr / ft_strlen(base));
	write(1, &base[(nbr % ft_strlen(base))], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	i;

	i = nbr;
	if (base_check(base) > 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			i *= -1;
		}
		print_base(base, i);
	}
}
