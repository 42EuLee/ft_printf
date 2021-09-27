SRC			=		*ft_strchr.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_u.c \
						ft_printf.c ft_print_hexa.c ft_count_hexa.c ft_count_n.c ft_print_c.c \
						ft_print_d.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc

rm			= rm -f

CFLAGS		= -c -Wall -Wextra -Werror -I

NAME		= libftprintf.a

all: $(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re