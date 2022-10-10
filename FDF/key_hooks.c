/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:01:07 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/10 23:26:57 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keypress, t_data *img)
{
	// int	horizontal_move_value;
	// int	vertical_move_value;
	// int	rotation_move_value;
	// int	size_change_value;
	
	
	printf("hello from keyhook!\n");
	// mlx_clear_window(img->mlx, img->window);	
	if (keypress == Esc)
	{
		mlx_destroy_window(img->mlx, img->window);
		exit(1);
	}
	if (keypress == W || keypress == A || keypress == S || keypress == D)
		translation(keypress, img);
	if (keypress == PLUS || keypress == MINUS)
		enlargment(keypress, img);
	// if (keypress == up_arrow_key)
	// 	img->size -= 1;
	// if (keypress == left_arrow_key)
	// 	img->size -= 1;
	// if (keypress == down_arrow_key)
	// 	img->size -= 1;
	// if (keypress == right_arrow_key)
	// 	img->size -= 1;
	// if (keypress == Q)
	// {
	// 	img->rotation -= 
	// }
	if (keypress == C)
	{
		if (img->color < 4)
			img->color += 1;
		else
			img->color = 0;
		change_color(img);
	}
	return 0;
}

void	change_color(t_data *img)
{
	int	color;
	int	x;
	int	y;

	y = 0;
	if (!img)
		return;
	img->img = mlx_new_image(img->mlx, img->screen_size_x, img->screen_size_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
					&img->endian);
	if (img->color == 1)
		color = red;
	else if (img->color == 2)
		color = green;
	else if (img->color == 3)
		color = blue;
	else if (img->color == 4)
		color = yellow;
	while (y < img->rows)
	{
		x = 0;
		while (x < img->cols)
		{
			img->points[y][x].color = color;
			x++;
		}
		y++;
	}
	draw_graph(img->points, img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
}

void	enlargment(int keypress, t_data *img)
{
	// t_position **points = img->points;
	// int x = 0;
	// int y = 0;

	img->img = mlx_new_image(img->mlx, img->screen_size_x, img->screen_size_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
				&img->endian);
	// while (y < img->rows)
	// {
	// 	x = 0;
	// 	while (x < img->cols)
	// 	{
	// 		printf("point (%i,%i)\n", img->original_points[y][x].posx, img->original_points[y][x].posy);
	// 		x++;
	// 	}
	// 	y++;
	// }
	img->points = img->original_points;
	if (keypress == PLUS)
	{
		// revert_plus(img->points, img);
		img->size += 1;
	}
	if (keypress == MINUS && img->size > 1)
	{
		// revert_minus(img->points, img);
		img->size -= 1;
	}
	// printf("img->size = %i\n", img->size);
	img->points = resize_points(img->points, img);
	img->points = isometric_projection(img->points, img);
	draw_graph(img->points, img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	mlx_destroy_image(img->mlx, img->img);
}

void	translation(int keypress, t_data *img)
{
	if (keypress == W)
		img->vert -= 4;
	if (keypress == A)
		img->hor -= 4;
	if (keypress == S)
		img->vert += 4;
	if (keypress == D)
		img->hor += 4;
	img->img = mlx_new_image(img->mlx, img->screen_size_x, img->screen_size_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
				&img->endian);
	// if (img->points == NULL)
	// 	printf("no image\n");
	draw_graph(img->points, img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	mlx_destroy_image(img->mlx, img->img);
	// mlx_clear_window(img->mlx, img->window);
}

// int	key_hook(int keycode, t_vars *vars)
// {
// 	if ()
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

void	initialize_img_values(t_data *img)
{
	img->hor = 0;
	img->vert = 0;
	img->rotation = 0;
	img->gradient_index = 0;
	img->projection = 0;
	img->size = find_scale_size(img);
	// img->ratio_x = (img->screen_size_x / img->cols);
	// img->ratio_y = (img->screen_size_y / img->rows);
	img->ratio = ((img->cols * img->rows) / (img->screen_size_x * img->screen_size_y));
	// img->ratio = ((img->screen_size_x / img->screen_size_y));
	printf("img->ratio = %f\n", img->ratio);
	// printf("img->ratio_y = %f\n", img->ratio_y);
	// printf("img->ratio_x = %f\n", img->ratio_x);
}
