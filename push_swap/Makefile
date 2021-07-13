CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap
NAME_B	= checker

LIBS	= -lft
LIB_DIR	= ./libft
LIB_NAME = libft/libft.a

SRCS	=	array.c	\
			check_error.c	\
			compress_oper.c	\
			free.c	\
			hardsorting_2.c	\
			list_utils.c	\
			make_info.c	\
			operation_1.c	\
			operation_2.c	\
			operation_3.c	\
			push_swap.c	\
			put_stack_a.c	\
			sort_5.c	\
			sort_a.c	\
			sort_remain.c	\
			stack_add.c	\
			stack_del.c	\

SRCS_B	=	checker.c	\
			check_error.c	\
			make_info.c	\
			operation_1.c	\
			operation_2.c	\
			operation_3.c	\
			put_stack_a.c	\
			list_utils.c	\
			stack_add.c	\
			stack_del.c	\
			array.c	\
			free.c	\
			./get_next_line/get_next_line.c	\
			./get_next_line/get_next_line_utils.c	\

OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(SRCS_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIB_NAME)
		$(CC) $(CFLAGS) $(OBJS) -L $(LIB_DIR) $(LIBS) -o $(NAME)

$(LIB_NAME) :
		$(MAKE) -C $(LIB_DIR)

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

bonus : $(NAME_B)

$(NAME_B) : $(OBJS_B) $(LIB_NAME)
		$(CC) $(CFLAGS) $(OBJS_B) -L $(LIB_DIR) $(LIBS) -o $(NAME_B)

clean :
		$(MAKE) -C $(LIB_DIR) fclean
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)
		rm -rf $(OBJS_B)
		rm -rf $(NAME_B)

re : fclean all
