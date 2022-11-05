CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = a.out

SRCS =	./main.cpp	\
		./test_vector.cpp	\
		./test_map.cpp	\
		./test_stack.cpp


OBJS = $(SRCS:.cpp=.o)


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
