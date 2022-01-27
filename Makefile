HEADER		=	./includes/

LIB_PATH	=	./lib/

LIBS		=	libft mlx

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

CFLAGS		=	-Wall -Werror -Wextra -I $(HEADER) -I $(addprefix $(LIB_PATH), $(LIBS)) 

NAME		=	so_long

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				$(CC) -o $@ -c $< -I $(HEADER)

$(NAME):		$(OBJS)
				ar rcs $@ $^

all:			$(NAME)

clean:
				rm -rf $(OBJ_PATH)

fclean:			clean
				rm -f $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re
