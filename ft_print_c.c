#include "ft_printf.h"

int	ft_print_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}
