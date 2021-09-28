#include "ft_printf.h"

int	ft_print_u(va_list args)
{
	unsigned int	d;
	int				len;

	d = va_arg(args, unsigned int);
	len = ft_count_n(d);
	return (ft_putnbr_u(d, len));
}
