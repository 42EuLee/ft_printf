#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define SPEC "cspdiuxX%"

typedef struct s_list
{
	int	c;
}	t_list;

int		ft_printf(const char *format, ...);
char	*ft_strchr(char *str, char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_putnbr_u(long n, int len);
int		ft_print_hexa(unsigned long long d, int len, int caps, int p);
int		ft_count_hexa(unsigned long long d);
int		ft_count_n(long d);
int		ft_print_c(va_list args);
int		ft_print_d(va_list args);
int		ft_print_p(va_list args);
int		ft_print_s(va_list args);
int		ft_print_u(va_list args);
int		ft_print_x(t_list *spec, va_list args);

#endif