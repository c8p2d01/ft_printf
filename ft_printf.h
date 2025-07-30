/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 20:28:03 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/17 00:50:30 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>

#include <stdio.h>
#include <limits.h>
# include <string.h>

typedef struct s_data
{
    char    *format;
    char    *insert;
    int     i;
    int     skipped;
	int		written;
    int     added;

    bool    do_sign;
	bool	do_width;
	bool	do_precision;
    bool    sign_positive;
	bool	is_negative;
    bool    left_justify;
    char	padding_char;
	bool	pointer_prefix;
	int		width;
	int		precision;
	char	insert_identifier;

	int		value_length;
	char	*value_base;
	char	*temp;
	char	*string;
	char	c;

	bool	debug;
	FILE	*f;
} t_data;

//main function call
int		ft_printf(const char *str, ...);

t_data **query();
int	reset_flags();
int ft_init(const char *format);
void	DEBUG();
int ft_error();
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
char *ft_strchr(char c, char *s);
int	ft_atoi(const char *nptr);
int	ft_log(unsigned long num, int base);
int ft_putchar(char c);
int	print_base(char *base, unsigned long nbr);
void	print_base_to_mem(char *dest, char *base, unsigned long nbr);
void    debug_logs(char *fmt, ...);
void	debug_data(va_list a);
int handle_padding(unsigned long num);
int	handle_d_i(va_list a);
int trigger_insert(va_list a);
int sprint(va_list a);
int ft_printf(const char *format, ...);
int ft_vfprintf(FILE *f, const char *format, va_list a);
void    all();
void compare(char *fmt, ...);

#endif