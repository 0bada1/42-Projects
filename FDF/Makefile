# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 14:27:08 by ooutabac          #+#    #+#              #
#    Updated: 2022/10/03 18:07:05 by ooutabac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f

LIBFT = libft.a
MLX = libmlx.dylib

SOURCES = 	fdf.c					\
			fdf_utils1.c			\
			fdf_utils2.c			\
			parsing.c				\
			center_image.c			\
			bresengham_algorithm.c	\
			isometric_projection.c	\
			free.c					\
			key_hooks.c
			
OBJ = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -Ilibft -c $< -o $@
		
all: $(NAME)

$(NAME): $(MLX) $(OBJ)
# cp mlx/libmlx.dylib .
	$(MAKE) -C libft
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME)
# make -C libft
# make bonus -C libft

# $(LIBFT): $(OBJ)
# make -C libft bonus

$(MLX):
	make -C mlx
	cp mlx/libmlx.dylib .
	
clean:
	$(RM) $(OBJ)
	$(RM) $(MLX)
	make -C mlx clean
	make -C libft clean
#	$(RM) libft/*.o
	
fclean:	clean
	$(RM) $(NAME)
	$(RM) libft/libft.a
	
re: fclean all

.PHONY: all clean fclean re