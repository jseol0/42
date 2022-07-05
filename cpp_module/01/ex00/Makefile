# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseol <jseol@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 16:35:10 by jseol             #+#    #+#              #
#    Updated: 2022/07/04 22:08:37 by jseol            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFALGS = -Wall -Wextra -Werror -std=c++98
NAME = zombie

SRCS =	main.cpp	\
		Zombie.cpp	\
		newZombie.cpp	\
		randomChump.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
		$(CC) $(CFALGS) $^ -o $@

%.o : %.cpp
		$(CC) $(CFALGS) -c $< -o $@

all : $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all