#include "ft_printf.h"

int	ft_count_hexa(unsigned long long d)
{
	int	i;

	i = 0;
	while (d / 16)
	{
		i++;
		d /= 16;
	}
	i++;
	return (i);
}
