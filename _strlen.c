/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _strlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:06:39 by alatrach          #+#    #+#             */
/*   Updated: 2022/07/17 00:59:38 by cdahlhof         ###   ########.fr       */
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
