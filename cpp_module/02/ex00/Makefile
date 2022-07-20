# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 14:32:49 by jseol             #+#    #+#              #
#    Updated: 2022/07/20 12:42:00 by jseol            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = a.out

SRCS =	./main.cpp	\
		./Fixed.cpp

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
