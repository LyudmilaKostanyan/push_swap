NAME = push_swap
NAME_BONUS = checker
CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
IFLAGS = -I./libft -I./ft_printf
LFLAGS = -L./libft -lft -L./ft_printf -lftprintf
FILES = push_swap.c \
		parse.c \
		parse_utils.c \
		merge.c \
		rotates.c \
		for_list.c \
		from_3_to_13.c \
		butterfly.c \
		butterfly_utils.c

FILES_BONUS = bonus/checker.c \
				bonus/get_next_line_bonus.c \
				bonus/get_next_line_utils_bonus.c \
				bonus/parse.c \
				bonus/parse_utils.c \
				bonus/rotates.c \
				bonus/for_list.c

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(FILES_BONUS:.c=.o)

# TO_BUILD = $(if $(filter bonus, $(MAKECMDGOALS)), $(OBJS_BONUS), $(OBJS))

%.o: %.c Makefile
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

all: lib ftprintf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) $(LFLAGS) -o $(NAME_BONUS)

lib:
	make -C libft

ftprintf:
	make -C ft_printf

bonus : lib ftprintf $(NAME_BONUS)

clean:
	rm -f ./*.o ./bonus/*.o libft/*.o ft_printf/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re lib ftprintf bonus