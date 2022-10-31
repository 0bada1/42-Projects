NAME = push_swap

SOURCES =	main.c				\
			check_for_errors.c	\
			utils1.c			\
			utils2.c			\
			utils3.c			\
			parsing.c			\
			algorithm.c			\
			movements.c			\
			libft_lists.c		\
			free.c				\

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	$(CC) $(FLAGS) $(OBJECTS) -Llibft -lft -Lft_printf -lprintf -o $(NAME)

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re