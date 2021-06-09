CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBS	= -lft
LIB_DIR	= ./libft
LIB_NAME = libft.a
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
NAME	= push_swap

$(LIB_NAME) :
	$(MAKE) -C $(LIB_DIR) bonus

$(NAME) : $(OBJS) $(LIBS)
		$(CC) $(CFLAGS) -c $(SRCS) -L$(LIB_DIR) $(LIBS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all : $(NAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_DIR) $(LIBS)

clean :
		$(MAKE) -C $(LIB_DIR) fclean
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all
