#ifdef FT_PRINTF
#define F(...) \
res = ft_printf(__VA_ARGS__);
#else
#define F(...) \
res = printf(__VA_ARGS__);
#endif

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

void	ft_putnbr_u(unsigned int n)
{
	if (n < 0)
	{
		n = UINT_MAX - n + 1;
		ft_putnbr_u(n);
	}
	else if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putnbr(-214748364);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_count_n(int d)
{
	unsigned int	i;

	i = 0;
	while (d / 10)
	{
		i++;
		d = d / 10;
	}
	i++;
	return (i);
}

int	ft_count_hexa(unsigned long d)
{
	unsigned long	i;

	i = 0;
	while (d / 16)
	{
		i++;
		d /= 16;
	}
	i++;
	return (i);
}

int	ft_print_hexa(unsigned long d, int len, int caps, int p)
{
	if (p == 1)
	{
		p--;
		ft_putstr("0x");
	}
	if (len > 0)
		ft_print_hexa(d / 16, len - 1, caps, p);
	if ((d % 16) >= 10 && caps == 0)
		ft_putchar((d % 16) - 10 + 'a');
	else if ((d % 16) >= 10 && caps == 1)
		ft_putchar((d % 16) - 10 + 'A');
	else if ((d % 16) == 0 && len == 0)
		return (0);
	else
		ft_putchar((d % 16) + '0');
	return (len);
}

int	ft_print_u(t_list *spec, va_list args)
{
	unsigned int	d;
	int				len;

	d = va_arg(args, unsigned int);
	len = ft_count_n(d);
	ft_putnbr_u(d);
	return (len);
}

int	ft_print_x(t_list *spec, va_list args)
{
	int	len;
	int	d;
	int	caps;
	int	p;

	p = 0;
	caps = 0;
	if (spec->c == 'X')
		caps = 1;
	d = va_arg(args, unsigned int);
	len = ft_count_hexa(d);
	return (ft_print_hexa(d, len, caps, p));
}

int	ft_print_s(t_list *spec, va_list args)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str);
		str++;
		i++;
	}
	return (i);
}

int	ft_print_d(t_list *spec, va_list args)
{
	int	d;
	int	len;

	d = va_arg(args, int);
	len = ft_count_n(d);
	ft_putnbr(d);
	return (len);
}

int	ft_print_c(t_list *spec, va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	ft_print_p(t_list *spec, va_list args)
{
	unsigned long	d;
	int				len;
	int				caps;
	int				p;

	p = 1;
	caps = 0;
	d = (unsigned long)va_arg(args, void *);
	len = ft_count_hexa(d);
	return (ft_print_hexa(d, len, caps, p) + 2);
}

int	ft_specifier(t_list *spec, va_list args)
{
	if (spec->c == 'c')
		return (ft_print_c(spec, args));
	if (spec->c == 'p')
		return (ft_print_p(spec, args));
	if (spec->c == 's')
		return (ft_print_s(spec, args));
	if (spec->c == 'd' || spec->c == 'i')
		return (ft_print_d(spec, args));
	if (spec->c == 'x' || spec->c == 'X')
		return (ft_print_x(spec, args));
	if (spec->c == 'u')
		return (ft_print_u(spec, args));
	if (spec->c == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

char	*read_args(t_list *spec, char *itr)
{
	if (!itr || *itr != '%')
		return (itr);
	itr++;
	while (*itr)
	{
		if (ft_strchr(SPEC, *itr))
		{
			spec->c = *itr;
			return (itr);
		}
		itr++;
	}
	return (itr);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	char	*variadic;
	va_list	args;
	t_list	spec;

	variadic = (char *)format;
	ret = 0;
	va_start(args, format);
	while (*variadic)
	{
		if (*variadic == '%')
		{
			variadic = read_args(&spec, variadic);
			ret = ret + ft_specifier(&spec, args);
		}
		else
		{
			ft_putchar(*variadic);
			ret++;
		}
		variadic++;
	}
	va_end(args);
	return (ret);
}

int	main(void)
{
	int		res;
	char	*p;

	p = "1234";
	F("I love pie alot\n")
	F("HELLOWORLD%sHELLOWORLD\n", "hi")
	F("[%d%d]\n", 01234, 01234)
	F("[%c]\n", 69)
	F("[%x]\n", 1234)
	F("[%X]\n", 1246)
	F("[%i]\n", 0x1234)
	F("[%u]\n", INT_MIN)
	F("[%%%%]\n")
	F("[%p]\n", "1234")
	F("[%%%c%d%p%X]\n\n", 50, 01234, NULL, 1234)

	ft_printf("%d\n", ft_printf("%p\n", "123456"));
	ft_printf("%d\n", printf("%p\n", "123456"));
	ft_printf("[%p]\n", p);
	printf("[%p]\n", p);
}
