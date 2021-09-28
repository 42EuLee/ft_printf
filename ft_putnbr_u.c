#include "ft_printf.h"

int	ft_putnbr_u(long n, int len)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr_u(n / 10, len);
		ft_putnbr_u(n % 10, len);
	}
	return (len);
}
