#include "ft_printf.h"

int	ft_count_n(long d)
{
	long	i;

	i = 0;
	if (d < 0)
		i++;
	while (d / 10)
	{
		i++;
		d = d / 10;
	}
	i++;
	return (i);
}
