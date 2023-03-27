NAME = push_swap
CC = cc
FLAGS = -c -Wall -Wextra -Werror
IFLAGS = -I./libft
LFLAGS = -L./libft -lft
FILES = main.c \
		parse.c
OBJS = $(FILES:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) $(IFLAGS) $< -o $@

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

lib:
	cd libft && make

clean:
	rm -f ./*.o libft/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re lib