# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 19:38:12 by jseol             #+#    #+#              #
#    Updated: 2022/01/04 23:31:19 by jaeyu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

# src / obj files
SRC		=	main.c	\
			pipex.c	\
			parse_input_value.c	\
			check_parsing.c

OBJ		=	$(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./src/
INCDIR	= ./include/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(NAME)

obj:
		@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		@make -sC $(FT)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) $(FT_LNK) -lm -o $(NAME)

clean:
		@rm -rf $(OBJDIR)
		@make -sC $(FT) clean

fclean: clean
		@rm -rf $(NAME)
		@make -sC $(FT) fclean

re: fclean all

.PHONY: all clean fclean re
