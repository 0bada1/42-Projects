/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:51:22 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/02 23:27:46 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	int		fd;
	// void	*mlx;
	// void	*mlx_window;
	t_data	img;

	img.mlx = mlx_init();
	img.screen_size_x = 1920;
	img.screen_size_y = 1080;
	ft_putstr_fd("HELLO FDF\n", 1);
	img.window = mlx_new_window(img.mlx, img.screen_size_x, img.screen_size_y, "FDF Test Window");
	img.img = mlx_new_image(img.mlx, img.screen_size_x, img.screen_size_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	// img.window = mlx_window;
	// img.mlx = mlx;
	fd = open("test_maps/42.fdf", O_RDONLY);
	t_position **points = parse(fd, &img);
	img.original_points = points;
	initialize_img_values(&img);
	printf("img->cols = %i\nimg->rows = %i\n", img.cols, img.rows);
	points = resize_points(points, &img);
	points = isometric_projection(points, &img);
	img.points = points;
	// printf("img->cols = %i\nimg->rows = %i\n", img.cols, img.rows);
	printf("Before aborting\n");
	draw_graph(img.points, &img);
	printf("after aborting\n");
	// algorithm(points[0][0], points[0][1], &img);
	// algorithm(points[0][0], points[1][0], &img);
	// algorithm(points[1][0], points[1][1], &img);
	// algorithm(points[0][1], points[1][1], &img);
	// algorithm(points[0][0], points[1][18], &img);

	// draw_vert_line(500, 0, 0, &img);
	// fill_bucket(0x0000FF00, 1919, 1079, &img);
	mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0); 
	mlx_hook(img.window, 2, 1L<<2, key_hook, &img);
	mlx_loop(img.mlx);
	// close(fd);
	// free_parsed_map()
}

// int	main(void)
// {
// 	t_data	img;
// 	t_vars	vars;

// 	img.screen_size_x = 1920;
// 	img.screen_size_y = 1080;
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, img.screen_size_x, img.screen_size_y, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close(, &vars);
// 	mlx_loop(vars.mlx);
// }