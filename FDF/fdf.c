/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:51:22 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/17 14:26:54 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;


	ft_putstr_fd("HELLO FDF\n", 1);
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "FDF Test Window");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	int fd = open("test_maps/42.fdf", O_RDONLY);
	t_position **points = parse(fd, &img);
	draw_graph(points, &img);
	algorithm(points[0][0], points[0][1], &img);
	algorithm(points[0][0], points[1][0], &img);
	algorithm(points[1][0], points[1][1], &img);
	algorithm(points[0][1], points[1][1], &img);
	// draw_vert_line(1080, 960, 0, &img);
	// fill_bucket(0x0000FF00, 1919, 1079, &img);
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
