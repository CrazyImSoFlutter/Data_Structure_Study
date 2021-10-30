CC = gcc
NAME = tree_height

MLX = mlx

LXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

SRCS = main.c\
	   tree.c\
	   random_loop.c\
	   node.c\
	   draw.c\
	   itoa.c\

OBJS = $(SRCS:.c = .o)

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
		$(CC) -g -o $(NAME) $(OBJS) $(LXFLAGS)

$(MLX):
		@$(MAKE) -C mlx

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
