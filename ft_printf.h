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

char	*ft_strchr(char *str, char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putnbr_u(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_print_hexa(unsigned long d, int len, int caps, int p);
int		ft_count_hexa(unsigned long d);
int		ft_count_n(int d);
int		ft_print_c(t_list *spec, va_list args);
int		ft_print_d(t_list *spec, va_list args);
int		ft_print_p(t_list *spec, va_list args);
int		ft_print_s(t_list *spec, va_list args);
int		ft_print_u(t_list *spec, va_list args);
int		ft_print_x(t_list *spec, va_list args);

#endif