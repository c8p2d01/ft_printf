/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _strlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:06:39 by alatrach          #+#    #+#             */
/*   Updated: 2021/08/15 20:58:59 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// return the length of an char array
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i = i + 1;
	return (i);
}
//#include <stdio.h>
//int main()
//{
//	char	string[] = "one longer than in here because null ending ,_,";
//	int i = ft_strlen(string);
//	printf("%s\t%d\n", string, i);
//}
