#include "ft_printf.h"

int	ft_print_c(t_list *spec, va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

