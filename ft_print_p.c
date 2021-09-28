#include "ft_printf.h"

int	ft_print_p(va_list args)
{
	unsigned long long		d;
	int						len;
	int						caps;
	int						p;

	p = 1;
	caps = 0;
	d = (unsigned long long)va_arg(args, void *);
	len = ft_count_hexa(d);
	return (ft_print_hexa(d, len, caps, p) + 2);
}
