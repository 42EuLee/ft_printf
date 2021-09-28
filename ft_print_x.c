#include "ft_printf.h"

int	ft_print_x(t_list *spec, va_list args)
{
	int					len;
	unsigned int		d;
	int					caps;
	int					p;

	p = 0;
	caps = 0;
	if (spec->c == 'X')
		caps = 1;
	d = va_arg(args, unsigned int);
	len = ft_count_hexa(d);
	return (ft_print_hexa(d, len, caps, p));
}
