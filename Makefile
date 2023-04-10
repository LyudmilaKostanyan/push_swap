NAME = push_swap
NAME_BONUS = checker
CC = cc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
IFLAGS = -I./libft -I./ft_printf
LFLAGS = -L./libft -lft -L./ft_printf -lftprintf
FILES = mandatory/push_swap.c \
		mandatory/parse.c \
		mandatory/parse_utils.c \
		mandatory/merge.c \
		mandatory/rotates.c \
		mandatory/for_list.c \
		mandatory/from_3_to_13.c \
		mandatory/butterfly.c \
		mandatory/butterfly_utils.c

FILES_BONUS = bonus/checker_bonus.c \
				bonus/get_next_line_bonus.c \
				bonus/get_next_line_utils_bonus.c \
				bonus/parse_bonus.c \
				bonus/parse_utils_bonus.c \
				bonus/rotates_bonus.c \
				bonus/for_list_bonus.c

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(FILES_BONUS:.c=.o)

%.o: %.c Makefile
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

all: libs $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) $(LFLAGS) -o $(NAME_BONUS)

libs:
	make -C libft
	make -C ft_printf

bonus : libs $(NAME_BONUS)

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re libs bonus
