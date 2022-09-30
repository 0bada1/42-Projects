/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:41:23 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/30 18:48:21 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* *********PARSING***********
Current line uses get_next_line to read through the fdf file and 
*/
// REPLACE PRINTF WITH FT_PRINTF
t_position	**parse(int fd, t_data *data)
{
	char	*current_line;
	char	**char_fdf_list;
	char 	**row;
	int		i;
	int		j;

	i = 0;
	j = 0;
	char_fdf_list = ft_calloc(sizeof(char*), 1000);
	current_line = get_next_line(fd);
	// if (current_line != NULL)
	// 	return (NULL);
	while (current_line != NULL)
	{
		char_fdf_list[i] = current_line;
		current_line = get_next_line(fd);
		i++;
		if (i > 10000)
		{
			printf("FILE TOO LARGE\n");
			exit(1);
		}
	}
	data->rows = i;
	char_fdf_list[i] = NULL;
	t_position **points = ft_calloc(sizeof(t_position *), data->rows + 1);
	i = 0;
	row = ft_split(char_fdf_list[i], ' ');
	data->cols = num_of_cols(row);
	// constant = img_to_screen_ratio(data);
	data->size = find_scale_size(data);
	while (char_fdf_list[i])
	{
		row = ft_split(char_fdf_list[i], ' ');
		// printf("row = %s", *row);
		points[i] = ft_calloc(sizeof(t_position), num_of_cols(row) + 1);
		j = 0;
		while (row[j])
		{
			points[i][j].posy = data->size * i;
			points[i][j].posx = data->size * j;
			points[i][j].posz = data->size * ft_atoi(row[j]);
			points[i][j].color = 0x00FFFFFF;
			// printf("%i  ", points[i][j].posz);
			// printf("y = %d\n", points[i][j].posx);
			// printf("x = %d\n", points[i][j].posy);
			// printf("z = %d\n", points[i][j].posz);
			j++;
		}
		// printf("\n");
		i++;
	}
	return (points);
}

int	num_of_cols(char **str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

// int	num_of_rows(char *str)
// {
// 	int	i;
// 	// int	counter;

// 	i = 0;
// 	// counter = 0;
// 	while (str[i])
// 	{
// 		// if (str[i] == '\n')
// 		// 	counter++;
// 		i++;
// 	}
// 	return (i);
// }

// int	main(void)
// {
// 	int fd = open("test_maps/42.fdf", O_RDONLY);
// 	t_position **points = parse(fd);
// 	printf("%i\n", points[2][2].posz);
// }

// void draw_graph(int rows, int columns, int size_between_each_pixel, t_data *img)
// {
// 	int	x;
// 	int	y;
// 	int	max_x;
// 	int	max_y;

// 	max_x = 1920;
// 	max_y = 1080;
// 	y = find_center_point_y(1080 - 1) - columns;
// 	while (y < max_y)
// 	{
// 		x = find_center_point_x(1920 - 1) - rows;
// 		while (x < max_x)
// 		{
// 			draw_hor_line(size_between_each_pixel, x, y, img);
// 			x += size_between_each_pixel;
// 			if (x > max_x)
// 				break;
// 		}
// 		y += size_between_each_pixel;
// 	}
// 	x = find_center_point_x(1920 - 1) - rows;
// 	while (x < max_x)
// 	{
// 		y = find_center_point_y(1080 - 1) - columns;
// 		while (y < max_y)
// 		{
// 			draw_vert_line(size_between_each_pixel, x, y, img);
// 			y += size_between_each_pixel;
// 			if (y > max_y)
// 				break;
// 		}
// 		printf("\nhello\n");
// 		x += size_between_each_pixel;
// 	}
// }

// ------DRAW POINTS ONLY-------
// void	draw_graph(t_position **points, t_data *img)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (y < img->cols)
// 	{
// 		x = 0;
// 		while (x < img->rows)
// 		{
// 			// algorithm(points[x][y], points[x + 1][y + 1], img);
// 			my_mlx_pixel_put(img, points[x][y].posx, points[x][y].posy, points[x][y].color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_graph(t_position **points, t_data *img)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	printf("drawing rows\n");
// 	draw_graph_rows(points, img);
// 	printf("drawing cols\n");
// 	draw_graph_cols(points, img);
// 	// draw_graph_all_except_last_column(x, points, current_point, img);
// 	// draw_graph_last_column(points, img);
// }

// void	draw_graph_all_except_last_column(int x, t_position **points, t_position current_point, t_data *img)
// {
// 	int	y;

// 	y = 0;
// 	while (y < img->rows)
// 	{
// 		x = 0;
// 		current_point.posy = points[y][x].posy;
// 		current_point.posx = points[y][x].posx;
// 		while (x + 1 < img->cols)
// 		{
// 			if (x + 1 < img->cols || x == img->cols)
// 				algorithm(current_point, points[y][x + 1], img);
// 			if (y + 1 < img->rows || y == img->rows)
// 				algorithm(current_point, points[y + 1][x], img);
// 			if (x == img->cols)
// 				algorithm(current_point, points[y + 1][x], img);
// 			x++;
// 			if (x + 1 < img->cols)
// 			{
// 				current_point.posx = points[y][x].posx;
// 				current_point.posy = points[y][x].posy;
// 			}
// 		}
// 		y++;
// 	}
// }

// void	draw_graph_last_column(t_position **points, t_data *img)
// {
// 	t_position	current_point;
// 	int			x;
// 	int			y;

// 	y = 0;
// 	x = img->cols - 1;
// 	current_point = points[y][x];
// 	while (y < img->rows)
// 	{
// 		if (y + 1 < img->rows || y == img->rows)
// 		{
// 			// printf("point (%i,%i) to point (%i,%i)\n", current_point.posx, current_point.posy, points[y + 1][x].posx, points[y + 1][x].posy);
// 			algorithm(current_point, points[y + 1][img->cols - 1], img);
// 		}
// 		y++;
// 	}
// }

// void	draw_graph(t_position **points, t_data *img)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x < img->cols)
// 	{
// 		if (x + 1 != img->cols)
// 			algorithm(points[y][x], points[y][x + 1], img);
// 		else
// 		{
// 			y++;
// 			x = 0;
// 		}
// 		x++;
// 		if (y + 1 == img->rows)
// 			break ;
// 	}
// 	x = 0;
// 	y = 0;
// 	while (y < img->rows)
// 	{
// 		if (y + 1 != img->rows)
// 			algorithm(points[y][x], points[y + 1][x], img);
// 		else
// 		{
// 			x++;
// 			y = 0;
// 		}
// 		y++;
// 		if (x + 1 == img->cols)
// 			break ;
// 	}
// }

void	draw_graph_rows(t_position **points, t_data *img)
{
	t_position	current_point;
	int	x;
	int	y;

	x = 0;
	y = 0;
	current_point = points[y][x];
	while (x < img->cols && y < img->rows)
	{
		current_point = points[y][x];
		if (x < img->cols)
		{
			algorithm(current_point, points[y][x + 1], img);
			x++;
		}
		if (x + 1 >= img->cols)
		{
			x = 0;
			y++;
		}
	}
}

void	draw_graph_cols(t_position **points, t_data *img)
{
	t_position	current_point;
	int	x;
	int	y;

	x = 0;
	y = 0;
	current_point = points[y][x];
	while (y < img->rows && x < img->cols)
	{
		current_point = points[y][x];
		// printf("x = %i\n", current_point.posx);
		// printf("y = %i\n", current_point.posy);
		if (y < img->rows)
		{
			algorithm(current_point, points[y + 1][x], img);
			y++;
		}
		if (y + 1 >= img->rows)
		{
			y = 0;
			x++;
		}
	}
}

void	draw_graph(t_position **points, t_data *img)
{
	t_position	current_point;
	int			x;
	int			y;
	
	x = 0;
	y = 0;
	current_point = points[y][x];
	while (y < img->rows)
	{
		x = 0;
		current_point = points[y][x];
		while (x < img->cols)
		{
			if (x + 1 < img->cols)
			{
				// printf("current_point[%i][%i] to points[%i][%i]\n", points[y][x].posx, points[y][x].posy, points[y][x + 1].posx, points[y][x + 1].posy);
				algorithm(current_point, points[y][x + 1], img);
			}
			if (y + 1 < img->rows)
			{
				// printf("current_point[%i][%i] to points[%i][%i]\n", points[y][x].posx, points[y][x].posy, points[y + 1][x].posx, points[y + 1][x].posy);
				algorithm(current_point, points[y + 1][x], img);
			}
			x++;
			current_point = points[y][x];
		}
		y++;
	}
}