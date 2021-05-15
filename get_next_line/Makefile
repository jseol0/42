CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a

SRCS =	get_next_line_utils.c	\
		get_next_line.c	\

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
