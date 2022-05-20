# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 19:06:02 by jseol             #+#    #+#              #
#    Updated: 2022/05/12 19:06:15 by jseol            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFALGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

SRCS = ./megaphone.cpp
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