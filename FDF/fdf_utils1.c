/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:53:39 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/17 14:09:16 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Draws a pixel
Used to draw a pixel on the window. An image must be already present to insert a
pixel to the window.
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > 1920 || y > 1080)
		return ;
	x += 1920 / 3;
	y += 1080 / 3;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* Draw horizontal line
Draw a horizontal line. Keep increasing x variable till length
*/
void	draw_hor_line(int length, int x, int y, t_data *img)
{
	int	i;

	i = 0;
	while (i++ < length)
	{
		printf("\nY IN HRLINE = %i\n", y);
		printf("\nX IN HRLINE = %i\n", x);
		my_mlx_pixel_put(img, x++, y, 0x00FFFFFF);
	}
}
/* Draws a square
length is the length of all sides of the square
*/

void	draw_vert_line(int length, int x, int y, t_data *img)
{
	int	i;

	i = 0;
	while (i++ < length)
		my_mlx_pixel_put(img, x, y++, 0x00FFFFFF);
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

