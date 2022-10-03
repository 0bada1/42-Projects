/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:53:39 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/03 11:16:52 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Draws a pixel
Used to draw a pixel on the window. An image must be already present to insert a
pixel to the window.
*/
void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	// x += img->screen_size_x / 5;
	// y += img->screen_size_y / 5;
	x += (find_center_point_x(img->screen_size_x) - ((img->cols * img->size) / 2) + img->hor);
	y += (find_center_point_y(img->screen_size_y) - ((img->rows * img->size) / 2) + img->vert);
	if (x > 0 && y > 0 && x < img->screen_size_x && y < img->screen_size_y)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

/* Draw horizontal line
Draw a horizontal line. Keep increasing x variable till length
*/
void	draw_hor_line(int length, int x, int y, t_data *img)
{
	int	i;

	i = 0;
	// printf("m == 0\n");
	while (i++ < length)
	{
	// 	printf("\nY IN HRLINE = %i\n", y);
	// 	printf("\nX IN HRLINE = %i\n", x);
		my_mlx_pixel_put(img, x++, y, 0x00FFFFFF);
	}
}

void	draw_hor_line_reverse(int length, int x, int y, t_data *img)
{
	int	i;

	i = 0;
	// printf("m == 0\n");
	while (i++ < length)
	{
	// 	printf("\nY IN HRLINE = %i\n", y);
	// 	printf("\nX IN HRLINE = %i\n", x);
		my_mlx_pixel_put(img, x--, y, 0x00FFFFFF);
	}
}
/* Draws a square
length is the length of all sides of the square
*/

void	draw_vert_line(int length, int x, int y, t_data *img)
{
	int	i;

	i = 0;
	// printf("m is infinite\n");
	while (i++ < length)
		my_mlx_pixel_put(img, x, y++, 0x00FFFFFF);
}

void	draw_vert_line_reverse(int length, int x, int y, t_data *img)
{
	int	i;

	i = 0;
	// printf("m is infinite\n");
	while (i++ < length)
		my_mlx_pixel_put(img, x, y--, 0x00FFFFFF);
}

void	draw_square(int length, int posx, int posy, t_data *img)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = posx;
	y = posy;
	while (i++ < length)
		my_mlx_pixel_put(img, x++, y, 0x00FFFFFF);
	i = 0;
	while (i++ < length)
		my_mlx_pixel_put(img, x, y++, 0x00FFFFFF);
	i = 0;
	while (i++ < length)
		my_mlx_pixel_put(img, x--, y, 0x00FFFFFF);
	i = 0;
	while (i++ < length)
		my_mlx_pixel_put(img, x, y--, 0x00FFFFFF);
	return ;
}

void	fill_bucket(int color, int window_size_x, int window_size_y, t_data *img)
{
	int		i;
	t_position pixel;

	i = 0;
	pixel.posx = - 1;
	pixel.posy = - 1;
	while (pixel.posy++ < window_size_y - 2)
	{
		while (pixel.posx++ < window_size_x)
			my_mlx_pixel_put(img, pixel.posx, pixel.posy, color);
		pixel.posx = 0;
	}
}
// void	draw_circle(int radius, int posx, int posy, t_data *img)
// {
// 	int i;

// 	i = 0;
// 	while ()
// }

/* Creates a gradient color to a line or set of lines
It is done by making a starting color and increasing the gradient 
till ending_color is met
*/
// void	gradient_color(int starting_color, int ending_color, position pixel, t_data *img)
// {
// 	int	i;

// 	i = 0;
// 	while (starting_color != ending_color)
// 	{
// 		starting_color++;
// 	}
// }

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// while ((img->cols * size) < img->screen_size_x && (img->rows * size) < img->screen_size_y && ((img->cols * img->rows * size) < (img->screen_size_x * img->screen_size_y * 0.75)))
// while (((img->cols * img->rows * size) < (img->screen_size_x * img->screen_size_y * 0.006)))
int	find_scale_size(t_data *img)
{
	while ((img->cols * img->size) < img->screen_size_x / 2 && (img->rows * img->size) < img->screen_size_y / 2)
		img->size++;
	// size--;
	// size *= 1.61803398875;
	printf("img->size = %i\n", img->size);
	return (img->size);
}

// t_position	**scale_img(t_position **points, t_data *img)
// {
// 	int	size;
// 	int	x;
// 	int	y;

// 	size = find_scale_size(img);
// 	y = 0;
// 	while (y < img->rows)
// 	{
// 		x = 0;
// 		while (x < img->cols)
// 		{
// 			points[y][x].posx *= size;
// 			points[y][x].posy *= size;
// 			points[y][x].posz *= size;
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (points);
// }
