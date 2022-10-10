/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:50:16 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/10 22:52:07 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typedef enum e_arrow_keys {
// 	up_arrow_key,
// 	left_arrow_key,
// 	down_arrow_key,
// 	right_arrow_key
// }	t_arrow_keys;

#  define red 		0xFF0000
#  define green 	0x00FF00
#  define blue 		0x0000FF
#  define yellow	0xFFFF00

#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define Q 12
#  define E 14
#  define C 8

#  define up_arrow_key 126
#  define left_arrow_key 123
#  define down_arrow_key 125
#  define right_arrow_key 124

#  define PLUS 24
#  define MINUS 27

#  define Esc 53


#ifndef FDF_H
# define FDF_H

#  define PI 3.142857
#  define alpha 35.264 * (PI/180)
#  define beta 45 * (PI/180)

// typedef struct	s_vars 
// {
// 	void	*mlx;
// 	void	*win;
// }
// t_vars;

typedef struct	s_counter
{
	int	i;
	int	j;
}
t_counter;

typedef	struct	s_position
{
	int		posx;
	int		posy;
	int		posz;
	long	color;
}
t_position;

typedef struct	s_data 
{
	void		*img;
	char		*addr;
	void		*window;
	void		*mlx;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			screen_size_x;
	int			screen_size_y;
	int			rows;
	int			cols;
	int			size;
	float		ratio_x;
	float		ratio_y;
	float		ratio;
	int			hor;
	int			vert;
	int			rotation;
	int			color;
	int			gradient_index;
	int			projection;
	t_position	**points;
	t_position  **original_points;
}
t_data;

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

/*-------------------------------------FDF UTILS1-----------------------------------*/
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_square(int length, int posx, int posy, t_data *img);
void		draw_hor_line(int length, t_position point, t_position point1, t_data *img);
void		draw_vert_line(int length, t_position point, t_position point1, t_data *img);
void		draw_hor_line_reverse(int length, t_position point, t_position point1, t_data *img);
void		draw_vert_line_reverse(int length, t_position point, t_position point1, t_data *img);
void		fill_bucket(int color, int window_size_x, int window_size_y, t_data *img);

/*-------------------------------------FDF UTILS2-----------------------------------*/
t_position	**copy_parsed_array(t_position **points1, t_position **opints2, t_data *img);
int			ft_atoh(char *str);

/*-------------------------------------PARSING FILE---------------------------------*/
t_position	**parse(int fd, t_data *data);
t_position	**parse_v2(t_counter counter, char **char_fdf_list, t_position **points, t_data *img);
int			find_center_point_x(int max_x);
int			find_center_point_y(int max_y);
int			num_of_cols(char **str);
int			find_line_size(int fd);

/*--------------------------------------CENTER IMAGE--------------------------------*/

/*-------------------------------------DRAWING GRAPH--------------------------------*/
void		draw_graph(t_position **points, t_data *img);
void		draw_graph_rows(t_position **points, t_data *img);
void		draw_graph_cols(t_position **points, t_data *img);

/*----------------------------------BRESENGHAM ALGORITHM----------------------------*/
void		algorithm(t_position **points, t_position point1, t_position point2, t_data *img);

/*----------------------------------ALGORITHM CONDITIONS----------------------------*/
/*
m < 1 && m > 0
m >= 1
m < 0 && m > -1
m <= -1
*/
void		check_conditions_and_redirect(t_position **points, t_position point1, t_position point2, t_data *img);

void		algorithm_m_less_than_1_and_greater_than_0(int Pk, t_position point1, t_position point2, t_data *img);
void		algorithm_m_greater_than_or_equal_to_1(int Pk, t_position point1, t_position point2, t_data *img);
void		algorithm_m_less_than_0_and_greater_than_minus1(int Pk, t_position point1, t_position point2, t_data *img);
void		algorithm_m_less_than_or_equal_to_minus1(int Pk, t_position point1, t_position point2, t_data *img);

void		algorithm_m_less_than_1_and_greater_than_0_reverse(int Pk, t_position point1, t_position point2, t_data *img);
void		algorithm_m_greater_than_or_equal_to_1_reverse(int Pk, t_position point1, t_position point2, t_data *img);
void		algorithm_m_less_than_0_and_greater_than_minus1_reverse(int Pk, t_position point1, t_position point2, t_data *img);
void		algorithm_m_less_than_or_equal_to_minus1_reverse(int Pk, t_position point1, t_position point2, t_data *img);

void		draw_algorithm(t_position **point, t_data *img);

// void	algorithm_m_less_than_1_reverse(int Pk, t_position point1, t_position point2, t_data *img);
// void	algorithm_m_greater_than_or_equal_to_1_reverse(int Pk, t_position point1, t_position point2, t_data *img);

/*--------------------------------ISOMETRIC PROJECTION-------------------------------*/
t_position		**isometric_projection(t_position **point, t_data *img);

/*---------------------------------------OTHER---------------------------------------*/
void		ft_swap(int	*a, int *b);
void		initialize_img_values(t_data *img);
int			assign_color(t_position **points, int x, int y);
int			find_scale_size(t_data *img);
int			img_to_screen_ratio(t_data *imgx);
// t_position		**scale_img(t_position **points, t_data *img);
int			key_hook(int keypress, t_data *img);
t_position	**resize_points(t_position **points, t_data *img);
t_position	**revert_minus(t_position **points, t_data *img);
t_position	**revert_plus(t_position **points, t_data *img);

/*-----------------------------------KEY HOOKS--------------------------------------*/
void		translation(int keypress, t_data *img);
void		enlargment(int keypress, t_data *img);
void		change_color(t_data *img);

#endif