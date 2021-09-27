#include "ft_printf.h"

int	ft_count_n(int d)
{
	unsigned int	i;

	i = 0;
	while (d / 10)
	{
		i++;
		d = d / 10;
	}
	i++;
	return (i);
}

