/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 15:22:47 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-07-30 15:22:47 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vfprintf(FILE *f, const char *format, va_list a)
{
	t_data	*data;

	if (ft_init(format))
		return (0);
	data = *query();
	data->debug = true;
	data->f = f;
	if (!sprint(a))
		return (ft_close(data->written));
	return (data->written);
}

void	compare(char *fmt, ...)
{
	va_list	va;
	FILE	*ori;
	FILE	*me;
	int		returns;

	if (!fmt)
	{
		ori = fopen("/Users/cdahlhof/Documents/ft_printf/ori.txt", "w+");
		me = fopen("/Users/cdahlhof/Documents/ft_printf/me.txt", "w+");
		fclose(ori);
		fclose(me);
		return ;
	}
	ori = fopen("/Users/cdahlhof/Documents/ft_printf/ori.txt", "a+");
	va_start(va, fmt);
	returns = vfprintf(ori, fmt, va);
	fprintf(ori, "\nreturn value = %i\n\n", returns);
	va_end(va);
	fclose(ori);
	me = fopen("/Users/cdahlhof/Documents/ft_printf/me.txt", "a+");
	va_start(va, fmt);
	returns = ft_vfprintf(me, fmt, va);
	fprintf(me, "\nreturn value = %i\n\n", returns);
	va_end(va);
	fclose(me);
}

// int main(void)
// {
//	 compare(NULL);
//	 compare("Hello World\n");
// 	}
