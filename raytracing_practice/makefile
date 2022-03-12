NAME	= test

# src / obj files
SRC		=	main.c	\
			canvas.c	\
			print.c	\
			ray.c	\
			scene.c	\
			vec3_utils.c	\
			object_create.c	\

OBJ		=	$(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# directories
SRCDIR	= ./src/
INCDIR	= ./include/
OBJDIR	= ./obj/

all: obj $(NAME)

obj:
		@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -lm -o $(NAME)

clean:
		@rm -rf $(OBJDIR)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re