/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:51:22 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/30 18:51:31 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	int		fd;
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	// t_vars	vars;

	mlx = mlx_init();
	initialize_img_values(&img);
	img.screen_size_x = 1920;
	img.screen_size_y = 1080;
	ft_putstr_fd("HELLO FDF\n", 1);
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, img.screen_size_x, img.screen_size_y, "FDF Test Window");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	fd = open("test_maps/mars.fdf", O_RDONLY);
	t_position **points = parse(fd, &img);
	printf("img->cols = %i\nimg->rows = %i\n", img.cols, img.rows);
	points = isometric_projection(points, &img);
	// printf("img->cols = %i\nimg->rows = %i\n", img.cols, img.rows);
	printf("Before aborting\n");
	draw_graph(points, &img);
	printf("after aborting\n");
	// algorithm(points[0][0], points[0][1], &img);
	// algorithm(points[0][0], points[1][0], &img);
	// algorithm(points[1][0], points[1][1], &img);
	// algorithm(points[0][1], points[1][1], &img);
	// algorithm(points[0][0], points[1][18], &img);

	// draw_vert_line(500, 0, 0, &img);
	// fill_bucket(0x0000FF00, 1919, 1079, &img);
	// img.window = mlx_window;
	// img.mlx = mlx;
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
	// mlx_key_hook(mlx_window, key_hook, &img);
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