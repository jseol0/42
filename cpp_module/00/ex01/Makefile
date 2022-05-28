# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseol <jseol@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 12:31:04 by jseol             #+#    #+#              #
#    Updated: 2022/05/26 19:59:42 by jseol            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook

SRCS =	./main.cpp	\
		./Contact.cpp	\
		./PhoneBook.cpp

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