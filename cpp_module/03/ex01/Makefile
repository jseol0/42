# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseol <jseol@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 15:30:32 by jseol             #+#    #+#              #
#    Updated: 2022/07/27 12:21:21 by jseol            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = a.out

SRCS =	./main.cpp	\
		./ClapTrap.cpp	\
		./ScavTrap.cpp

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