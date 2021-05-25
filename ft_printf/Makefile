CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS =	ft_printf.c	\
		check.c		\
		nbr.c		\
		util_1.c	\
		util_2.c	\
		applys.c	\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

t : fclean all
	gcc -Wall -Wextra -Werror main.c -L. -lftprintf -fsanitize=address
