CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS =	ft_bzero.c	\

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
	gcc -Wall -Wextra -Werror main.c -L. -lft
