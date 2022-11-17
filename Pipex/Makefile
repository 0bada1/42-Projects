# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:52:24 by ooutabac          #+#    #+#              #
#    Updated: 2022/11/14 11:59:10 by ooutabac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = 	pipex.c			\
			check_errors.c	\
			utils1.c		\
			free.c			\
			
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

OBJ = $(SOURCES:.c=.o)

%.c : %.o
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(OBJ)
	$(CC) $(CFLAGS)
	$(MAKE) -C libft
	$(MAKE) -C ft_printf

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