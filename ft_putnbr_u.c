#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n)
{
	if (n < 0)
	{
		n = UINT_MAX - n + 1;
		ft_putnbr_u(n);
	}
	else if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
}
