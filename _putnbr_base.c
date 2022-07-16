/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _putnbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:19:21 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/17 00:58:07 by cdahlhof         ###   ########.fr       */
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

int	print_base(char *base, unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr >= (unsigned long)ft_strlen(base))
		i += print_base(base, nbr / ft_strlen(base));
	return (write(1, &base[(nbr % ft_strlen(base))], 1) + i);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	if (base_check(base) > 1)
	{
		return (print_base(base, nbr));
	}
	return (0);
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
