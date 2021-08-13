/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 20:28:03 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/13 20:34:51 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#ifndef PRINTF_H
# define PRINTF_H
//check if there is an indicator flag at the current position
int	indcheck(const char *str);
//check if and what kind of indicator (flag) is at the current position
int	indidentify(const char *str);
//calling functions to write the needed data type
int	express(int n, va_list elem);
//main function call
int	ft_printf(const char *str, ...);
#endif