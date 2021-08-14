/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 20:28:03 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/14 13:02:47 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#ifndef PRINTF_H
# define PRINTF_H

// typedef struct p_pool
// {
// 	int			ni;
// 	int			*i;
// 	int			nc;
// 	char		*c;
// 	int			ns;
// 	char		**s;
// 	int			np;
// 	void		*p;
// }					t_pool;

// count the length of a given string
size_t	ft_strlen(char *str);
// count the number of digits in the given number
size_t	ft_ndigit(size_t n);
// convert the given positive integral number to a char representation in *res
static void	pitoa (long m, int p, int l, char *res);
// write an integer to a given file-directory
void	ft_putnbr_fd(int n, int fd);
// write a given string to a given file-directory
void	ft_putstr_fd(char *s, int fd);
// write a given integer represented in a different clean base
void	ft_putnbr_base(int nbr, char *base);

//check if there is an indicator flag at the current position
int	indcheck(const char *str);
//check if and what kind of indicator (flag) is at the current position
int	indidentify(const char *str);
//calling functions to write the needed data type
int	express(int n, va_list elem);
//main function call
int	ft_printf(const char *str, ...);
#endif