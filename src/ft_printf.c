/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 17:21:50 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-08-05 17:21:50 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

// t_data	**query(void)
// {
// 	static t_data	*data;

// 	return (&data);
// }

// int	reset_flags_extension(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data)
// 	{
// 		if (data->value_base)
// 			free(data->value_base);
// 		data->value_base = NULL;
// 		if (data->temp)
// 			free(data->temp);
// 		data->temp = NULL;
// 		data->string = NULL;
// 		data->c = '\r';
// 	}
// 	else
// 		return (1);
// 	return (0);
// }

// int	reset_flags(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data)
// 	{
// 		data->do_sign = false;
// 		data->do_width = false;
// 		data->do_precision = false;
// 		data->sign_positive = false;
// 		data->is_negative = false;
// 		data->leftbound = false;
// 		data->padd_char = ' ';
// 		data->pointer_prefix = false;
// 		data->width = 0;
// 		data->precision = 0;
// 		data->insert_identifier = '\0';
// 		data->value_length = 0;
// 	}
// 	else
// 		return (1);
// 	reset_flags_extension();
// 	return (0);
// }

// int	ft_init(const char *format)
// {
// 	t_data	*data;

// 	if (format)
// 	{
// 		*query() = malloc(sizeof(t_data));
// 		ft_bzero(*query(), sizeof(t_data));
// 		data = *query();
// 		data->format = (char *)format;
// 		data->insert = NULL;
// 		data->i = 0;
// 		data->skipped = 0;
// 		data->added = 0;
// 		data->written = 0;
// 		if (reset_flags())
// 			return (1);
// 		data->debug = false;
// 	}
// 	else
// 		return (1);
// 	return (0);
// }

// int	ft_close(int return_value)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data)
// 	{
// 		if (data->value_base)
// 			free(data->value_base);
// 		data->value_base = NULL;
// 		free(data);
// 		*query() = NULL;
// 	}
// 	return (return_value);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str && str[i] != '\0')
// 		i++;
// 	return (i);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*c;
// 	size_t			i;

// 	c = (unsigned char *)s;
// 	i = 0;
// 	while (n > i)
// 	{
// 		c[i] = '\0';
// 		i++;
// 	}
// }

// void	ft_memset(void *s, char r, size_t n)
// {
// 	unsigned char	*c;
// 	size_t			i;

// 	c = (unsigned char *)s;
// 	i = 0;
// 	while (n > i)
// 	{
// 		c[i] = r;
// 		i++;
// 	}
// }

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*s;
// 	unsigned char	*d;

// 	i = 0;
// 	if (!dest && !src)
// 		return (NULL);
// 	s = (unsigned char *)src;
// 	d = (unsigned char *)dest;
// 	while (n > i)
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	return (dest);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*dest;
// 	size_t	i;
// 	size_t	len;

// 	len = ft_strlen(s);
// 	dest = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!dest)
// 		return (NULL);
// 	i = 0;
// 	while (len > i)
// 	{
// 		dest[i] = s[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// char	*ft_strchr(char c, char *s)
// {
// 	if (!s)
// 		return (NULL);
// 	while (s && *s)
// 	{
// 		if (*s == c)
// 			return (s);
// 		s++;
// 	}
// 	if (s && c == '\0')
// 		return (s);
// 	return (NULL);
// }

// char	*ft_strrchr(const char *s, int c)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = -1;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char)c)
// 			j = i;
// 		i++;
// 	}
// 	if ((char)c == '\0')
// 		return (((char *)s) + i);
// 	if (j == -1)
// 		return (NULL);
// 	return (((char *)s) + j);
// }

// int	ft_atoi(const char *nptr)
// {
// 	int	i;
// 	int	sign;
// 	int	num;

// 	i = 0;
// 	sign = 1;
// 	num = 0;
// 	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
// 		i++;
// 	if (nptr[i] == 43 || nptr[i] == 45)
// 	{
// 		if (nptr[i] == 45)
// 			sign *= -1;
// 		i++;
// 	}
// 	while (nptr[i] > 47 && nptr[i] < 58)
// 	{
// 		num = num * 10 + nptr[i] - '0';
// 		i++;
// 	}
// 	return (num * sign);
// }

// int	ft_log(unsigned long num, int base)
// {
// 	int	digits;

// 	digits = 0;
// 	if (num <= 0)
// 		digits++;
// 	while (num)
// 	{
// 		digits++;
// 		num = num / base;
// 	}
// 	return (digits);
// }

// int	ft_putchar(char c)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data->debug)
// 	{
// 		if (fwrite(&c, 1, 1, data->f) != 1)
// 			return (0);
// 	}
// 	else
// 	{
// 		if (write(1, &c, 1) != 1)
// 			return (0);
// 	}
// 	data->written++;
// 	return (1);
// }

// int	repeat_char(char c, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (!ft_putchar(c))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	ft_putstr_null(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if ((data->precision > 0 || !data->do_precision) && !ft_putchar('('))
// 		return (0);
// 	if ((data->precision > 1 || !data->do_precision) && !ft_putchar('n'))
// 		return (0);
// 	if ((data->precision > 2 || !data->do_precision) && !ft_putchar('u'))
// 		return (0);
// 	if ((data->precision > 3 || !data->do_precision) && !ft_putchar('l'))
// 		return (0);
// 	if ((data->precision > 4 || !data->do_precision) && !ft_putchar('l'))
// 		return (0);
// 	if ((data->precision > 5 || !data->do_precision) && !ft_putchar(')'))
// 		return (0);
// 	return (1);
// }

// int	ft_putstr_case(char *s)
// {
// 	int		i;
// 	t_data	*data;

// 	data = *query();
// 	if (!s)
// 		ft_putstr_null();
// 	i = 0;
// 	while (s && s[i] && (data->precision > i || !data->do_precision))
// 	{
// 		if (!ft_putchar(s[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	print_base(char *base, unsigned long nbr)
// {
// 	int	i;
// 	int	error;
// 	int	baselen;

// 	i = 0;
// 	baselen = ft_strlen(base);
// 	if (!baselen)
// 		base = "0123456789";
// 	if (nbr >= (unsigned long)ft_strlen(base))
// 	{
// 		error = print_base(base, nbr / ft_strlen(base));
// 		if (error < 0)
// 			return (-1);
// 		i += error;
// 	}
// 	error = ft_putchar(base[(nbr % ft_strlen(base))]);
// 	if (error < 0)
// 		return (-1);
// 	return (error + i);
// }

// /**
//  * ALERT this function is highly unsstable and relies
//  * on the memory to be allocated and iterates starting in the end
//  */
// void	print_base_to_mem(char *dest, char *base, unsigned long nbr)
// {
// 	int	i;
// 	int	baselen;

// 	i = 0;
// 	baselen = ft_strlen(base);
// 	if (!baselen)
// 		base = "0123456789";
// 	if (nbr >= (unsigned long)ft_strlen(base))
// 	{
// 		print_base_to_mem(dest - 1, base, nbr / ft_strlen(base));
// 	}
// 	*dest = base[(nbr % ft_strlen(base))];
// }

// void	debug_data()
// {
// 	t_data	*data;
// 	FILE	*out;

// 	out = fopen("{PATH_PLACEHOLDER}}/ft_printf/debug.txt", "a+");
// 	data = *query();
// 	fprintf(out, "\nData Snapshot\n");
// 	fprintf(out, "the given format is ");
// 	fwrite(data->format + data->i - 1, 1, data->skipped + 1, out);
// 	fprintf(out, "\ncurrently we are at position %i\n", data->i);
// 	fprintf(out, "the flag is of length %i\n", data->skipped);
// 	fprintf(out, "the type of insertion is %c\n", data->insert_identifier);
// 	fprintf(out, "do we leave signspace? %s\n", data->do_sign ? "yes" : "no");
// 	fprintf(out, "sign positives? %s\n", data->sign_positive ? "yes" : "no");
// 	fprintf(out, "precision? %s\n", data->do_precision ? "yes" : "no");
// 	fprintf(out, "width is set at %i\n", data->width);
// 	fprintf(out, "precision is set at %i\n", data->precision);
// 	data->do_precision ? fprintf(out, "\tprecisionlength  %i\n", \
// 		data->precision) : (void)out;
// 	fprintf(out, "do we give width %s\n", data->do_width ? "yes" : "no");
// 	data->do_precision ? fprintf(out, "\tthe width is of length  %i\n", \
// 		data->width) : (void)out;
// 	fprintf(out, "%s", data->leftbound ? "forget padding\n" : "");
// 	if (ft_strchr(data->insert_identifier, "idxoX"))
// 		fprintf(out, "the number has a length of %i\n", data->value_length);
// 	fclose(out);
// }

// int	string_padding_continuance(void)
// {
// 	t_data	*data;
// 	int		i;

// 	data = *query();
// 	i = 0;
// 	while (data->string && data->string[i] && \
// 			(data->precision > i || !data->do_precision))
// 	{
// 		if (!ft_putchar(data->string[i]))
// 			return (0);
// 		i++;
// 	}
// 	if (data->leftbound && (data->width > i))
// 	{
// 		if (!repeat_char(' ', data->width - i))
// 			return (0);
// 	}
// 	return (1);
// }

// int	string_padding(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (!data->leftbound)
// 	{
// 		if (data->do_precision && (data->width > data->precision))
// 		{
// 			if (!repeat_char(data->padd_char, data->width - data->precision))
// 				return (0);
// 		}
// 		else if (!data->do_precision && (data->width > data->value_length))
// 		{
// 			if (!repeat_char(data->padd_char, data->width - data->value_length))
// 				return (0);
// 		}
// 	}
// 	string_padding_continuance();
// 	return (1);
// }

// int	char_padding_extension(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data->is_negative)
// 		ft_putchar('-');
// 	else if (data->insert_identifier == 'c' || data->insert_identifier == '%')
// 		ft_putchar(data->c);
// 	if (data->leftbound && data->do_width && (data->width > data->precision))
// 	{
// 		if (!repeat_char(' ', data->width - data->precision))
// 			return (0);
// 	}
// 	return (1);
// }

// int	char_padding(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (!data->leftbound && data->do_width && (data->width > data->precision))
// 	{
// 		if (data->padd_char == '0' && data->is_negative)
// 		{
// 			ft_putchar('-');
// 			data->is_negative = false;
// 		}
// 		if (!repeat_char(data->padd_char, data->width - data->precision))
// 			return (0);
// 	}
// 	if (data->do_precision && data->precision > data->value_length)
// 	{
// 		if (data->is_negative)
// 		{
// 			ft_putchar('-');
// 			data->is_negative = false;
// 		}
// 		if (!repeat_char('0', data->precision - data->value_length))
// 			return (0);
// 	}
// 	char_padding_extension();
// 	return (1);
// }

// void	set_pad(unsigned long num)
// {
// 	t_data	*data;
// 	int		pad;

// 	data = *query();
// 	pad = 0;
// 	if (num || !data->do_precision)
// 		pad = data->value_length;
// 	if (data->precision > pad)
// 		pad = data->precision;
// 	if (data->width > pad)
// 		pad = data->width;
// 	if (pad && data->precision == 0 && data->do_precision == true && \
// 														data->do_width == false)
// 		pad--;
// 	if (data->is_negative || data->do_sign || data->sign_positive)
// 		pad++;
// 	if (data->pointer_prefix)
// 		pad += 2;
// 	data->temp = malloc(pad + 1);
// 	ft_memset(data->temp, '@', pad + 1);
// 	data->temp[pad] = '\0';
// 	if ((data->do_precision && data->precision) || !data->do_precision)
// 		print_base_to_mem(data->temp + pad - 1, data->value_base, num);
// 	data->pad = pad;
// }

// void	handle_precision(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	while (data->p_i < data->precision)
// 	{
// 		*ft_strrchr(data->temp, '@') = '0';
// 		data->p_i++;
// 	}
// 	while (data->p_i < data->width && data->padd_char == '0')
// 	{
// 		*ft_strrchr(data->temp, '@') = '0';
// 		data->p_i++;
// 	}
// }

// void	handle_sign(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data->is_negative && !data->pointer_prefix)
// 	{
// 		*ft_strrchr(data->temp, '@') = '-';
// 		data->p_i++;
// 	}
// 	else if (data->sign_positive && !data->pointer_prefix)
// 	{
// 		*ft_strrchr(data->temp, '@') = '+';
// 		data->p_i++;
// 	}
// 	else if (data->do_sign && !data->pointer_prefix)
// 	{
// 		*ft_strrchr(data->temp, '@') = ' ';
// 		data->p_i++;
// 	}
// }

// void	handle_pointy(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data->pointer_prefix && ft_strchr(data->insert_identifier, "pxX"))
// 	{
// 		if (data->insert_identifier == 'X')
// 			*ft_strrchr(data->temp, '@') = 'X';
// 		else
// 			*ft_strrchr(data->temp, '@') = 'x';
// 		data->p_i++;
// 		*ft_strrchr(data->temp, '@') = '0';
// 		data->p_i++;
// 	}
// }

// void	handle_leftsbound(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data->leftbound && data->p_i < data->pad)
// 	{
// 		ft_memcpy(data->temp, ft_strrchr(data->temp, '@') + 1, \
// 									ft_strlen(ft_strrchr(data->temp, '@') + 1));
// 		while (data->p_i < data->pad)
// 		{
// 			data->temp[data->p_i] = ' ';
// 			data->p_i++;
// 		}
// 	}
// }

// int	handle_padding(unsigned long num)
// {
// 	t_data	*data;
// 	int		i;

// 	data = *query();
// 	set_pad(num);
// 	data->p_i = data->value_length;
// 	handle_precision();
// 	handle_sign();
// 	i = data->p_i;
// 	handle_pointy();
// 	handle_leftsbound();
// 	i = 0;
// 	while (data->temp && data->temp[i])
// 	{
// 		if (data->temp[i] == '@')
// 			data->temp[i] = ' ';
// 		if (!ft_putchar(data->temp[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	handle_d_i(va_list a)
// {
// 	t_data	*data;
// 	long	val;
// 	int		num;

// 	data = *query();
// 	val = va_arg(a, int);
// 	num = val;
// 	if (val < 0)
// 	{
// 		data->is_negative = true;
// 		num = -val;
// 	}
// 	data->value_base = ft_strdup("0123456789");
// 	data->value_length = ft_log((unsigned int)num, 10);
// 	if (num && data->value_length > data->precision)
// 		data->precision = data->value_length;
// 	if (data->do_precision)
// 		data->padd_char = ' ';
// 	data->width -= (data->do_sign || data->sign_positive || data->is_negative);
// 	return (handle_padding((unsigned int)num));
// }

// int	handle_u(va_list a)
// {
// 	t_data			*data;
// 	unsigned int	num;

// 	data = *query();
// 	num = va_arg(a, int);
// 	data->value_base = ft_strdup("0123456789");
// 	data->value_length = ft_log(num, 10);
// 	data->width -= (data->do_sign || data->sign_positive);
// 	if (num && data->value_length > data->precision)
// 		data->precision = data->value_length;
// 	if (data->do_precision)
// 		data->padd_char = ' ';
// 	return (handle_padding(num));
// }

// int	handle_x(va_list a)
// {
// 	t_data			*data;
// 	unsigned int	num;

// 	data = *query();
// 	num = va_arg(a, int);
// 	if (!num)
// 		data->pointer_prefix = false;
// 	data->value_base = ft_strdup("0123456789abcdef");
// 	data->value_length = ft_log(num, 16);
// 	if (data->do_precision)
// 		data->padd_char = ' ';
// 	if (num && data->value_length > data->precision)
// 		data->precision = data->value_length;
// 	data->width -= (data->do_sign || data->sign_positive);
// 	if (num && data->pointer_prefix)
// 		data->width -= 2;
// 	return (handle_padding(num));
// }

// int	handle_p(va_list a)
// {
// 	t_data			*data;
// 	unsigned long	num;

// 	data = *query();
// 	num = va_arg(a, unsigned long);
// 	data->do_width = false;
// 	data->width -= 2;
// 	data->pointer_prefix = true;
// 	data->value_base = ft_strdup("0123456789abcdef");
// 	data->value_length = ft_log(num, 16);
// 	if (data->value_length > data->precision)
// 		data->precision = data->value_length;
// 	data->width -= (data->do_sign || data->sign_positive);
// 	return (handle_padding(num));
// }

// int	handle_big_x(va_list a)
// {
// 	t_data			*data;
// 	unsigned int	num;

// 	data = *query();
// 	num = va_arg(a, int);
// 	if (!num)
// 		data->pointer_prefix = false;
// 	data->value_base = ft_strdup("0123456789ABCDEF");
// 	data->value_length = ft_log(num, 16);
// 	if (data->do_precision)
// 		data->padd_char = ' ';
// 	if (num && data->value_length > data->precision)
// 		data->precision = data->value_length;
// 	data->width -= (data->do_sign || data->sign_positive);
// 	if (num && data->pointer_prefix)
// 		data->width -= 2;
// 	return (handle_padding(num));
// }

// int	handle_c(va_list a)
// {
// 	t_data	*data;
// 	char	c;

// 	data = *query();
// 	c = va_arg(a, int);
// 	data->value_length = 1;
// 	data->do_precision = false;
// 	data->c = c;
// 	data->width--;
// 	return (char_padding());
// }

// int	handle_percent(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	data->value_length = 1;
// 	data->do_precision = false;
// 	data->c = '%';
// 	data->width--;
// 	return (char_padding());
// }

// int	handle_s(va_list a)
// {
// 	t_data	*data;
// 	char	*s;

// 	data = *query();
// 	s = va_arg(a, char *);
// 	if (!s)
// 	{
// 		data->value_base = ft_strdup("(null)");
// 		s = data->value_base;
// 	}
// 	data->value_length = ft_strlen(s);
// 	data->string = s;
// 	if (data->precision > data->value_length && s)
// 		data->precision = data->value_length;
// 	if (!s && !data->do_precision)
// 		data->precision = 6;
// 	return (string_padding());
// }

// void	read_flags(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data->format[data->i + data->len] == ' ')
// 		data->do_sign = true;
// 	if (data->format[data->i + data->len] == '+')
// 		data->sign_positive = true;
// 	if (data->format[data->i + data->len] == '-')
// 		data->leftbound = true;
// 	if (data->format[data->i + data->len] == '#')
// 		data->pointer_prefix = true;
// 	if (data->format[data->i + data->len] == '0')
// 		data->padd_char = '0';
// }

// void	read_numbers(void)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data->format[data->i + data->len] == '.')
// 	{
// 		data->precision = ft_atoi(&data->format[data->i + data->len + 1]);
// 		if (data->precision != 0)
// 			data->add += ft_log(data->precision, 10);
// 		if (data->format[data->i + data->len + 1] == '0')
// 			data->add++;
// 		data->do_precision = true;
// 	}
// 	if (ft_strchr(data->format[data->i + data->len], "123456789"))
// 	{
// 		data->do_width = true;
// 		data->width = ft_atoi(&data->format[data->i + data->len]);
// 		data->add = ft_log(data->width, 10);
// 	}
// }

// int	delegate_handlers(va_list a)
// {
// 	t_data	*data;

// 	data = *query();
// 	if (data->insert_identifier == 'i' || data->insert_identifier == 'd')
// 		return (handle_d_i(a));
// 	if (data->insert_identifier == 'u')
// 		return (handle_u(a));
// 	if (data->insert_identifier == 'x')
// 		return (handle_x(a));
// 	if (data->insert_identifier == 'p')
// 		return (handle_p(a));
// 	if (data->insert_identifier == 'X')
// 		return (handle_big_x(a));
// 	if (data->insert_identifier == 'c')
// 		return (handle_c(a));
// 	if (data->insert_identifier == '%')
// 		return (handle_percent());
// 	if (data->insert_identifier == 's')
// 		return (handle_s(a));
// 	return (0);
// }

// int	trigger_insert(va_list a)
// {
// 	t_data	*data;

// 	data = *query();
// 	data->len = 0;
// 	while (data->format[data->i + data->len] && \
// 					!ft_strchr(data->format[data->i + data->len], "discuxXp%"))
// 	{
// 		data->add = 1;
// 		read_flags();
// 		read_numbers();
// 		data->len += data->add;
// 	}
// 	if (data->format[data->i + data->len])
// 		data->insert_identifier = \
// 					*ft_strchr(data->format[data->i + data->len], "discuxXp%");
// 	data->skipped = data->len + 1;
// 	delegate_handlers(a);
// 	reset_flags();
// 	return (0);
// }

int	sprint(va_list a)
{
	t_data	*data;
	int		i;

	data = *query();
	i = 0;
	while (data->format[i])
	{
		data = *query();
		if (data->format[i] != '%')
		{
			if (ft_putchar(data->format[i]) != 1)
				return (1);
		}
		else
		{
			data->i = i + 1;
			if (trigger_insert(a))
				return (1);
			data = *query();
			i += data->skipped;
		}
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_data	*data;
	va_list	a;

	if (ft_init(format))
		return (0);
	va_start(a, format);
	data = *query();
	if (!sprint(a))
		return (ft_close(data->written));
	va_end(a);
	ft_close(data->written);
	return (data->written);
}

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

// void	compare(char *fmt, ...)
// {
// 	va_list	va;
// 	FILE *ori;
// 	int returns;
// 	FILE *me;

// 	if (!fmt)
// 	{

// 		FILE *out = fopen("{PATH_PLACEHOLDER}}/ft_printf/debug.txt", "w+");
// 		fclose(out);
// 		ori = fopen("{PATH_PLACEHOLDER}}/ft_printf/ori.txt", "w+");
// 		me = fopen("{PATH_PLACEHOLDER}}/ft_printf/me.txt", "w+");
// 		fclose(ori);
// 		fclose(me);
// 		return ;
// 	}
// 	ori = fopen("{PATH_PLACEHOLDER}}/ft_printf/ori.txt", "a+");
// 	va_start(va, fmt);
// 	returns = vfprintf(ori, fmt, va);
// 	fprintf(ori, "\nreturn value = %i\n\n", returns);
// 	va_end(va);
// 	fclose(ori);

// 	me = fopen("{PATH_PLACEHOLDER}}/ft_printf/me.txt", "a+");
// 	va_start(va, fmt);
// 	returns = ft_vfprintf(me, fmt, va);
// 	fprintf(me, "\nreturn value = %i\n\n", returns);
// 	va_end(va);
// 	fclose(me);
// }

// int main(void)
// {
//	 compare(NULL);
// 	compare("Hello world\n");
// }
