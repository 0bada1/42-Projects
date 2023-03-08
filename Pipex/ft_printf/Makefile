# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 20:27:13 by ooutabac          #+#    #+#              #
#    Updated: 2022/10/19 21:36:21 by ooutabac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

SOURCES = ft_printf.c			\
		ft_putchar_fd.c			\
		ft_putnbr_fd.c			\
		ft_putstr_fd.c			\
		ft_putnbr_hexa.c		\
		ft_putnbr_hexa_cap.c	\
		ft_putnbr_fd_u.c		\

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@
	
$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re