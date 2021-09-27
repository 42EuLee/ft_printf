#include "ft_printf.h"

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
