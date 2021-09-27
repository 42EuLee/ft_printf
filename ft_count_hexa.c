#include "ft_printf.h"

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
