# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 22:22:50 by elim              #+#    #+#              #
#    Updated: 2022/01/23 21:42:03 by jaeyu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g
CFLAGS = -Wall -Wextra -Wall

NAME = minishell
TEST = test

SRCS_DIR = ./srcs
SRCS_NAME = main.c handle_envp.c print_banner.c \
			get_next_line.c get_next_line_utils.c \
			cmd.c cmd_utils.c \
			ft_free_cmd.c ft_free_token.c ft_free_split.c \
			get_cmd_args.c \
			get_redir_struct.c \
			get_split_size_utils.c get_split_size.c \
			malloc_env_utils.c \
			malloc_token.c malloc_token_utils.c \
			parse_cmd.c parse_cmd_utils_1.c parse_cmd_utils_2.c \
			parse_line.c \
			signal.c \
			exec.c exec_util.c \
			ft_error.c ft_error_util.c \
			ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_exit_util.c ft_export.c ft_export_util.c ft_pwd.c ft_unset.c \
			nonbuiltin.c redirect.c redir_file_check.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

FT_DIR = ./libft
FT = ft

#USER = elim
USER = jseol

INCS = -I./includes -I./libft -I/usr/local/opt/readline/include
#INCS = -I./includes -I./libft -I/Users/$(USER)/.brew/opt/readline/include
#INCS = -I./includes -I./libft -I/opt/homebrew/opt/readline/include

READLINE_LIB = -lreadline -L/usr/local/opt/readline/lib
#READLINE_LIB = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib
#READLINE_LIB = -lreadline -L/opt/homebrew/opt/readline/lib

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCS)

$(NAME): $(OBJS)
	$(MAKE) bonus -C $(FT_DIR)
	$(CC) $(CFLAGS) -L$(FT_DIR) -l$(FT) $(READLINE_LIB) $(INCS) $(OBJS) -o $@

$(TEST):
	$(MAKE) bonus -C $(FT_DIR)
	$(CC) $(CFLAGS) -L$(FT_DIR) -l$(FT) $(READLINE_LIB) $(INCS) $(SRCS) -o $@

all: $(NAME)

test: $(TEST)

clean:
	$(MAKE) clean -C $(FT_DIR)
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(FT_DIR)
	rm -rf $(NAME)
	rm -rf $(TEST)

re: fclean all

retest: fclean test

.PHONY: all test clean fclean re retest
