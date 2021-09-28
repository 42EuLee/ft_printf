#ifdef FT_PRINTF
#define F(...) \
res = ft_printf(__VA_ARGS__);
#else
#define F(...) \
res = printf(__VA_ARGS__);
#endif

#include "ft_printf.h"

int	main(void)
{
	int		res;
	char	*p;

	p = "1234";
	F("I love pie alot\n")
	F("[%s]\n", "hi")
	F("[%d%d]\n", 01234, 01234)
	F("[%c]\n", 69)
	F("[%x]\n", 1234)
	F("[%X]\n", 1246)
	F("[%i]\n", 0x1234)
	F("[%u]\n", INT_MIN)
	F("[%%%%]\n")
	F("[%p]\n", NULL)
	F("[%%%c%d%p%X]\n\n", 50, 01234, NULL, 1234)

	ft_printf("%d\n", ft_printf("%u\n", 123456));
	ft_printf("%d\n", printf("%u\n", 123456));
	ft_printf("[%p]\n", p);
	printf("[%p]\n", p);
}
