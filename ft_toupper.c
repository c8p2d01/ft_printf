/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:40:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/05/26 21:47:26 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🌊

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		return (c - 32);
	return (c);
}
//#include <stdio.h>
//int main()
//{
//	char	c[] = {'a','I','T','e','4','K'};
//	printf("%s\n", c);
//	for(int i = 0; i < 6; i++)
//		c[i] = ft_toupper(c[i]);
//	printf("%s\n", c);
//}
