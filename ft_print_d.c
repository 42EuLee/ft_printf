#include "ft_printf.h"

int	ft_print_d(t_list *spec, va_list args)
{
	int	d;
	int	len;

	d = va_arg(args, int);
	len = ft_count_n(d);
	ft_putnbr(d);
	return (len);
}
