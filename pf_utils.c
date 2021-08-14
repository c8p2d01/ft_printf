/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:31:09 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/14 13:29:58 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	indcheck(const char *str)
{
	if (str && str[1])
		if (str[0] == '%' && (str[1] == 'c' || str[1] == 's' ||
			str[1] == 'p' || str[1] == 'd' || str[1] == 'i' || str[1] == 'u' ||
			str[1] == 'x' || str[1] == '%'))
			return (1);
	return (0);
}

int	indidentify(const char *str)
{
	if (indcheck(str) == 0)
		return (0);
	if (str[0] == '\0' || str[0] != '%' || str[1] == '\0')
		return (0);
	if (str[1] == 'c')
		return (1);
	else if (str[1] == 's')
		return (2);
	else if (str[1] == 'p')
		return (3);
	else if (str[1] == 'd')
		return (4);
	else if (str[1] == 'i')
		return (5);
	else if (str[1] == 'u')
		return (6);
	else if (str[1] == 'x')
		return (7);
	else if (str[1] == '%')
		return (8);
	return (-1);
}

// int	express(int n, ...)
// {
// 	if (n == 1)
// 		write(1, (char *)elem, 1);
// 	else if (n == 2)
// 		ft_putstr_fd((char *)elem, ft_strlen((char *)elem));
// 	else if (n == 3)
// 		write(1, "to be continued", 15);
// 	else if (n == 4)
// 		write(1, "to be continued", 15);
// 	else if (n == 5)
// 		ft_putnbr_fd((int)elem, 1);
// 	else if (n == 6)
// 		write(1, "to be continued", 15);
// 	else if (n == 7)
// 		write(1, "to be continued", 15);
// 	else if (n == 8)
// 		write(1, 37, 1);
// 	return (0);
// }

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;

	i = -1;
	while (str[++i])
	{
		n = indidentify(&str[i]);
		if (!n)
		{
			write(1, str + i, 1);
			continue ;
		}
		if (n == 1)
			write(1, , 1);
	else if (n == 2)
		ft_putstr_fd((char *)elem, ft_strlen((char *)elem));
	else if (n == 3)
		write(1, "to be continued", 15);
	else if (n == 4)
		write(1, "to be continued", 15);
	else if (n == 5)
		ft_putnbr_fd((int)elem, 1);
	else if (n == 6)
		write(1, "to be continued", 15);
	else if (n == 7)
		write(1, "to be continued", 15);
	else if (n == 8)
		write(1, 37, 1);
	}
	return (0);
}

#include <stdio.h>
int	main()
{
	printf("%%%%\n%i\t%s\n", "why have you foresaken me?!", 42);
	return (0);
}