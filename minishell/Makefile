# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 22:22:50 by elim              #+#    #+#              #
#    Updated: 2022/01/09 18:20:43 by elim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Wall
INCS = -I./includes -I./libft -I/opt/homebrew/opt/readline/include

NAME = minishell

SRCS_DIR = ./srcs
SRCS_NAME = main.c \
			env.c env_utils.c \
			parse_line.c \
			cmd.c cmd_utils.c \
			signal.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

FT_DIR = ./libft
FT = ft

READLINE_LIB = -lreadline -L/opt/homebrew/opt/readline/lib

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCS)

$(NAME): $(OBJS)
	$(MAKE) bonus -C $(FT_DIR)
	$(CC) $(CFLAGS) -L$(FT_DIR) -l$(FT) $(READLINE_LIB) $(INCS) $(OBJS) -o $@ \
	-fsanitize=address

all: $(NAME)

clean:
	$(MAKE) clean -C $(FT_DIR)
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(FT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
