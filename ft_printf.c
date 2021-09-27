#include "ft_printf.h"

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
