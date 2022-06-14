# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseol <jseol@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 10:51:52 by jseol             #+#    #+#              #
#    Updated: 2022/05/31 11:01:09 by jseol            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Account

SRCS =	./tests.cpp	\
		./Account.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all