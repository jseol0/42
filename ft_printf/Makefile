CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS =	ft_printf.c	\
		input.c		\
		nbr_1.c		\
		nbr_2.c		\
		util_1.c	\
		util_2.c	\
		put_width.c	\

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
	rm -rf a.out

re : fclean all

t : fclean all
	gcc -Wall -Wextra -Werror main.c -L. -lftprintf
