/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdftest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:48:08 by ooutabac          #+#    #+#             */
/*   Updated: 2022/08/30 13:34:00 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Initializing graphical system
// int	main(void)
// {
// 	void	*mlx;

// 	mlx = mlx_init();
// }

/* Creating a window of size 1920 x 1080 named Hello world!
mlx_new_window() function is used to create a new window. Meanwhile mlx_loop()
function is used to keep that window open.
*/
// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }

/* Creating a new image
mlx_new_image() creates a new image to be displayed. We store the output in a varibale
so that we can use that variable to store the pixels later. It is done this way because
the function mlx_pixel_put() tends to be very slow since it pushes the pixel before the
image is rendered.
*/

// int main(void)
// {
// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	t_data	img;

// 	mlx = mlx_init();
// 	img.img = mlx_new_image(mlx, 1920, 1080);

// 	/*
// 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// 	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
// 	** then be set accordingly for the *current* data address.
// 	*/
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 								mlx_get_data_addr()
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int		i;
// 	int		x;
// 	int		y;

// 	i = 0;
// 	x = 0;
// 	y = 0;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	draw_square(1000, 960, 520, img, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

// Drawing a squre
// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	draw_square(200, 960, 540, &img);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_window;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_window = mlx_new_window(mlx, 1920, 1080, "FDF Test Window");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 				&img.endian);
// 	// draw_vert_line(1080, 960, 0, &img);
// 	fill_bucket(0xFFFFFFFF, 1910, 1070, &img);
// 	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
// 	mlx_loop(mlx);
// }