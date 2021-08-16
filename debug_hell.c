#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i = i + 1;
	return (i);
}

size_t	_ndigit(size_t n)
{
	size_t	i;
	size_t	p;

	p = 1;
	i = 10;
	while (i > 0)
	{
		if ((n % i) == n)
			return (p);
		i *= 10;
		p++;
	}
	return (p);
}

//##########################################################
int		base_check(char *str)
{
	int	i;
	int	c;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ('a' > str[i] && str[i] > 'z')
			if ('A' > str[i] && str[i] > 'Z')
				if ('0' > str[i] && str[i] > 'Z')
					return (0);
		c = i + 1;
		while (str[c])
		{
			if (str[i] == str[c])
				return (0);
			c++;
		}
		i++;
	}
	return (i);
}

void	print_base(char *base, long nbr)
{
	if (nbr >= (long)ft_strlen(base))
		print_base(base, nbr / ft_strlen(base));
	write(1, &base[(nbr % ft_strlen(base))], 1);
}

void	ft_putnbr_base(long nbr, char *base)
{
	long	i;

	i = nbr;
	if (base_check(base) > 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			i *= -1;
		}
		print_base(base, i);
	}
}

// #####################################################
int	out_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	out_hexa(int nbr)
{
	if (nbr >= 0)
		ft_putnbr_base(nbr, "0123456789abcdef");
	else
		ft_putnbr_base((4294967296 + nbr), "0123456789abcdef");
	if (nbr != 0)
		return (8);
	return (1);
}

int	out_integer(int i)
{
	ft_putnbr_base(i, "0123456789");
	return (_ndigit(i));
}

int	out_pointer(unsigned long i)
{
	write(1, "0x", 2);
	if (i != 0)
		ft_putnbr_base((long)i, "0123456789abcdef");
	else
		write(1, "0", 1);
	if (i != 0)
		return (14);
	return (3);
}

int	out_string(char *s)
{
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	out_unsigned_integer(unsigned int nbr)
{
	if (nbr >= 0)
		ft_putnbr_base(nbr, "0123456789");
	else
		ft_putnbr_base((4294967296 + nbr), "0123456789");
	if (nbr >= 0)
		return (_ndigit(nbr));
	return (_ndigit(4294967296 + nbr));
}

int	out_spread(const char *str, int n, va_list ap)
{
	if (n == 1)
		return (out_char((char)va_arg(ap, int)));
	else if (n == 2)
		return (out_hexa(va_arg(ap, int)));
	else if (n == 3)
		return (out_integer(va_arg(ap, int)));
	else if (n == 4)
		return (out_pointer(va_arg(ap, unsigned long)));
	else if (n == 5)
		return (out_string(va_arg(ap, char *)));
	else if (n == 6)
		return (out_unsigned_integer(va_arg(ap, unsigned int)));
	else if (n == 7)
		return (out_char('%'));
	return (-2147483648);
}

//'#'######################################################################
int	indidentify(const char *str)
{
	if (str[0] == '%')
	{
		if (str[1] == 'c')
			return (1);
		else if (str[1] == 'x')
			return (2);
		else if (str[1] == 'i' || str[1] == 'd')
			return (3);
		else if (str[1] == 'p')
			return (4);
		else if (str[1] == 's')
			return (5);
		else if (str[1] == 'u')
			return (6);
		else if (str[1] == '%')
			return (7);
	}
	return (0);
}

// 0 -> normal
// 1 -> char
// 2 -> hexa
// 3 -> integer & decimal
// 4 -> pointer
// 5 -> string
// 6 -> unsigned integer
// 7 -> %
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		n;
	int		total;

	i = -1;
	n = 0;
	total = 0;
	va_start(ap, str);
	while (str[++i] && n >= 0)
	{
		n = indidentify(&str[i]);
		if (n == 0)
		{
			write(1, str + i, 1);
			total++;
			continue ;
		}
		else
		{
			total += out_spread(str, n, ap);
			i++;
		}
	}
	return (total);
}

// int	main()
// {
// 	int out;
// 	int real;
// 	real = printf("%p:%s\n", &out, "why have you foresaken me?!");
// 	printf("%i\n\n\n\n", real);
// 	write(1, "", 1);
// 	out = ft_printf("%p:%s\n", &out, "why have you foresaken me?!");
// 	printf("%i\n", out);
// 	return (0);
// }

// int main(void)
// {
// 	// printf("%p\n",NULL);
// 	// printf("%i\n",(int)NULL);
// 	ft_putnbr_base(10, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(10, "0123456789abcdef");
// 	write(1, "\n", 1);
// 	return (0);
// }