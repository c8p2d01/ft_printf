/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _putnbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:19:21 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/16 14:05:28 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (nbr >= (long)ft_strlen(base))
		print_base(base, nbr / ft_strlen(base));
	write(1, &base[(nbr % ft_strlen(base))], 1);
}

void	ft_putnbr_base(long nbr, char *base)
{
	long	i;

	i = nbr;
	if (base_check(base) > 1)
	{
		if (i >= 0)
			print_base(base, i);
	}
}

// int main(void)
// {
// 	for (int i = 0; i < 110; i++)
// 	{
// 		ft_putnbr_base(i, "0123456789abcdef");
// 		write(1, "\n", 1);
// 	}
// }+

// int main(void)
// {
// 	int i = -2147483647;
// 	out_integer(i);
// 	printf("\n%d\n", i);
// }
