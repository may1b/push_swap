NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

AR		= ar rcs
RM		= rm -f

SRCS	=	ft_printf.c        \
			ft_print_memory.c  \
			ft_strlen.c        \
			ft_strupcase.c     \
			ft_print.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re
