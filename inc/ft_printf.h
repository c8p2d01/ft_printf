/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/13 20:28:03 by cdahlhof		  #+#	#+#			 */
/*   Updated: 2022/07/17 00:50:30 by cdahlhof		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>

# include <stdio.h>
# include <limits.h>
# include <string.h>

typedef struct s_data
{
	char	*format;
	char	*insert;
	int		i;
	int		skipped;
	int		written;
	int		added;
	int		add;
	int		len;

	bool	do_sign;
	bool	do_width;
	bool	do_precision;
	bool	sign_positive;
	bool	is_negative;
	bool	leftbound;
	char	padd_char;
	bool	pointer_prefix;
	int		width;
	int		precision;
	int		pad;
	int		p_i;
	char	insert_identifier;

	int		value_length;
	char	*value_base;
	char	*temp;
	char	*string;
	char	c;

	bool	debug;
	FILE	*f;
}	t_data;

t_data	**query(void);

int		reset_flags_extension(void);
int		reset_flags(void);
int		ft_init(const char *format);
int		ft_close(int return_value);

size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_memset(void *s, char r, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(char c, char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *nptr);
int		ft_log(unsigned long num, int base);
int		ft_putchar(char c);
int		repeat_char(char c, size_t n);
int		print_base(char *base, unsigned long nbr);
void	print_base_to_mem(char *dest, char *base, unsigned long nbr);

int		string_padding(void);
int		char_padding_extension(void);
int		char_padding(void);

void	set_pad(unsigned long num);
void	handle_precision(void);
void	handle_sign(void);
void	handle_pointy(void);
void	handle_leftsbound(void);
int		handle_padding(unsigned long num);

int		delegate_handlers(va_list a);
int		handle_d_i(va_list a);
int		handle_u(va_list a);
int		handle_p(va_list a);
int		handle_x(va_list a);
int		handle_big_x(va_list a);
int		handle_c(va_list a);
int		handle_percent(void);
int		handle_s(va_list a);

void	read_numbers(void);
void	read_flags(void);
int		trigger_insert(va_list a);
int		sprint(va_list a);

int		ft_printf(const char *format, ...);
int		ft_vfprintf(FILE *f, const char *format, va_list a);
void	compare(char *fmt, ...);

#endif