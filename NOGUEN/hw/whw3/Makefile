NAME = whw3

CC = gcc

CFLAGS = -I.

SRCS = whw3.c\
	   init.c\
	   utils.c\
	   hash.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:		clean
				rm -rf $(NAME)

re: fclean all
