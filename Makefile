HEADER		=	./includes/

LIB_PATH	=	./lib/

LIBS		=	$(addprefix $(LIB_PATH), libft/ mlx/)

SRC_PATH	=	./src/

SRCS		=	exit.c \
				init.c \
				input.c \
				main.c \
				map.c \
				mlx_func.c \
				render.c \

OBJ_PATH	=	./bin/

OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

NAME		=	so_long

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				make -C 
				@mkdir -p $(OBJ_PATH)
				$(CC) -o $@ -c $< -I $(HEADER) -I $(LIBS)

$(NAME):		$(OBJS)

all:			$(NAME)

clean:
				rm -rf $(OBJ_PATH)

fclean:			clean
				rm -f $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re
