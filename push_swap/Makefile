CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap
LIBS	= -lft
LIB_DIR	= ./libft
LIB_NAME = libft.a
# SRCS	= $(wildcard *.c)
SRCS 	= push_swap.c	\
		check_error.c	\
		make_info.c		\
		operation_1.c	\
		operation_2.c	\
		operation_3.c	\
		put_stack_a.c	\
		stack.c			\
		list_utils.c
OBJS	= $(SRCS:.c=.o)


$(NAME) : $(OBJS) $(LIB_NAME)
		$(CC) $(CFLAGS) $(OBJS) -L $(LIB_DIR) $(LIBS) -o $(NAME)

$(LIB_NAME) :
		$(MAKE) -C $(LIB_DIR)

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
		$(MAKE) -C $(LIB_DIR) fclean
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all
