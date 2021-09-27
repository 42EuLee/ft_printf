#include "ft_printf.h"

int	ft_print_s(t_list *spec, va_list args)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str);
		str++;
		i++;
	}
	return (i);
}
