HEADER_INC	=	-I./include

LIB_PATH	=	./lib/

LIBFT_PATH	=	$(LIB_PATH)libft

MLX_PATH	=	$(LIB_PATH)mlx

ifeq ($(shell uname -m), arm64)
	MLX_FLAG	:=  -lmlx -framework OpenGL
else
	MLX_FLAG	:=  -lmlx -lXext -lX11
endif

LIBS		=	libft mlx

LIB_INC		=	$(addprefix -I$(LIB_PATH), $(LIBS))

SRC_PATH	=	./src/

SRCS		=	exit.c \
				init.c \
				input.c \
				main.c \
				map.c \
				mlx_func.c \
				render.c \
				error.c \

OBJ_PATH	=	./bin/

OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

CFLAGS_FSAN	=	-Wall -Werror -Wextra -g3 -fsanitize=address

NAME		=	so_long

NAME_BONUS	=	so_long_bonus

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				$(CC) $(CFLAGS) $(HEADER_INC) $(LIB_INC) -c $< -o $@

$(NAME):		$(OBJS)
				make -C $(LIBFT_PATH)
				make -C $(MLX_PATH)
				$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) $(MLX_FLAG) -o $(NAME)

$(NAME_BONUS):	$(OBJS)
				make -C $(LIBFT_PATH)
				make -C $(MLX_PATH)
				$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) $(MLX_FLAG) -o $(NAME_BONUS)

all:			$(NAME) $(NAME_BONUS)

clean:
				rm -rf $(OBJ_PATH)
				make -C $(LIBFT_PATH) fclean
				make -C $(MLX_PATH) clean

fclean:			clean
				rm -f $(NAME) $(NAME_BONUS)

re: 			fclean all

bonus:			$(NAME_BONUS)

.PHONY:			all clean fclean re bonus
