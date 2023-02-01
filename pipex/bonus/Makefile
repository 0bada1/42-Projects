# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:52:24 by ooutabac          #+#    #+#              #
#    Updated: 2023/01/23 21:43:04 by ooutabac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = 	pipex.c									\
			check_errors.c							\
			utils1.c								\
			utils2.c								\
			utils3.c								\
			free.c									\
			./get_next_line/get_next_line.c			\
			./get_next_line/get_next_line_utils.c	\
			
OBJ = $(SOURCES:.c=.o)
BOBJ = $(BSOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

%.o : %.c
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ../libft
	$(MAKE) -C ../ft_printf
	$(CC) $(CFLAGS) $(OBJ) ../libft/libft.a ../ft_printf/libprintf.a -o $(NAME)
# $(MAKE) libft
# $(MAKE) ft_printf

bonus: $(OBJ) $(BOBJ)
	ar -r $(NAME) $?

clean:
	rm -f $(OBJ)
	$(MAKE) -C ../libft clean
	$(MAKE) -C ../ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ../libft fclean
	$(MAKE) -C ../ft_printf fclean

re: fclean all

.PHONY: all clean fclean re