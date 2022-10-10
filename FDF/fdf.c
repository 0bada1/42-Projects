/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:51:22 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/10 23:38:06 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	int		fd;
	t_data	img;

	img.mlx = mlx_init();
	img.screen_size_x = 1920;
	img.screen_size_y = 1080;
	ft_putstr_fd("HELLO FDF\n", 1);
	img.window = mlx_new_window(img.mlx, img.screen_size_x, img.screen_size_y, "FDF Test Window");
	img.img = mlx_new_image(img.mlx, img.screen_size_x, img.screen_size_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	fd = open("test_maps/t1.fdf", O_RDONLY);
	img.original_points = parse(fd, &img);
	if (!img.original_points)
		return 0;
	initialize_img_values(&img);
	printf("img->cols = %i\nimg->rows = %i\n", img.cols, img.rows);
	img.points = copy_parsed_array(img.original_points, img.points, &img);
	img.points = resize_points(img.points, &img);
	img.points = isometric_projection(img.points, &img);
	printf("Before aborting\n");
	draw_graph(img.points, &img);
	printf("after aborting\n");
	// algorithm(points[0][0], points[0][1], &img);
	// algorithm(points[0][0], points[1][0], &img);
	// algorithm(points[1][0], points[1][1], &img);
	// algorithm(img.points[0][1], img.points[1][1], &img);
	// algorithm(img.points[8][5], img.points[0][5], &img);

	// draw_vert_line(500, 0, 0, &img);
	// fill_bucket(0x0000FF00, 1919, 1079, &img);
	mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0); 
	mlx_hook(img.window, 2, 1L<<0, key_hook, &img);
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