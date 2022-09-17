/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:50:16 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/17 13:40:25 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef	struct	s_position
{
	int	posx;
	int	posy;
	int posz;
	int color;
}
t_position;

typedef struct	s_data 
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			screen_size_x;
	int			screen_size_y;
	int			rows;
	int			cols;
	t_position	**points;
}			t_data;


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "mlx.h"
# include "libft.h"

/*-------------------------------------FDF UTILS1-----------------------------------*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_square(int length, int posx, int posy, t_data *img);
void	draw_hor_line(int length, int x, int y, t_data *img);
void	draw_vert_line(int length, int x, int y, t_data *img);
void	fill_bucket(int color, int window_size_x, int window_size_y, t_data *img);

/*-------------------------------------PARSING FILE---------------------------------*/
t_position		**parse(int fd, t_data *data);
void			draw_graph(t_position **points, t_data *img);
int				find_center_point_x(int max_x);
int				find_center_point_y(int max_y);
int				find_number_of_rows(int fd);
int				find_number_of_columns(int fd);
int				ft_strlen2(char *str);
int				num_of_cols(char **str);

/*----------------------------------BRESENGHAM ALGORITHM----------------------------*/
void			algorithm(t_position point1, t_position point2, t_data *img);

#endif