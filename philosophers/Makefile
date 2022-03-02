# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:07:49 by jaeyu             #+#    #+#              #
#    Updated: 2022/02/18 16:53:00 by jaeyu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCDIR = ./includes/
SRCDIR = ./srcs/

SRC =	main.c \
		utils.c	\
		clear.c	\
		init.c	\
		state.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@ 

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re