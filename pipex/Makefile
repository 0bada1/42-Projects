# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:52:24 by ooutabac          #+#    #+#              #
#    Updated: 2023/01/23 21:34:47 by ooutabac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = 	pipex.c			\
			check_errors.c	\
			utils1.c		\
			utils2.c		\
			free.c			\

BSOURCES = 	./bonus/pipex.c			\
			./bonus/utils1.c		\
			./bonus/utils2.c		\
			./bonus/utils3.c		\
			./bonus/check_errors.c	\
			./bonus/free.c			\

OBJ = $(SOURCES:.c=.o)
BOBJ = $(BSOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

%.o : %.c
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a ft_printf/libprintf.a -o $(NAME)
# $(MAKE) libft
# $(MAKE) ft_printf

bonus: $(BOBJ)
	ar -r $(NAME) $?

clean:
	rm -f $(OBJ)
	$(MAKE) -C bonus clean
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C bonus fclean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean bonus re