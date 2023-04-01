NAME = push_swap
CC = cc
FLAGS = -c -Wall -Wextra -Werror
IFLAGS = -I./libft -I./ft_printf
LFLAGS = -L./libft -lft -L./ft_printf -lftprintf
FILES = main.c \
		parse.c \
		parse_utils.c \
		merge.c \
		cmds_spr.c \
		for_list.c
OBJS = $(FILES:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) $(IFLAGS) $< -o $@

all: lib ftprintf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

lib:
	cd libft && make

ftprintf:
	cd ft_printf && make

clean:
	rm -f ./*.o libft/*.o ft_printf/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re lib ftprintf