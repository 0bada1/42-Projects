/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:41:23 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/17 13:42:11 by ooutabac         ###   ########.fr       */
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
	int		constant;

	constant = 35;
	i = 0;
	j = 0;
	char_fdf_list = malloc(sizeof(char*) * 10000);
	current_line = get_next_line(fd);
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
	t_position **points = malloc(sizeof(t_position *) * i);
	i = 0;
	while (char_fdf_list[i])
	{
		row = ft_split(char_fdf_list[i], ' ');
		points[i] = malloc(sizeof(t_position) * num_of_cols(row));
		data->cols = num_of_cols(row);
		j = 0;
		while (row[j])
		{
			points[i][j].posy = constant * i;
			points[i][j].posx = constant * j;
			points[i][j].posz = constant * ft_atoi(row[j]);
			points[i][j].color = 0x00FFFFFF;
			// printf("x = %d  ", points[i][j].posx);
			// printf("y = %d  ", points[i][j].posy);
			// printf("z = %d", points[i][j].posz);
			
			j++;
		}
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

void	draw_graph(t_position **points, t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < img->cols)
	{
		x = 0;
		while (x < img->rows)
		{
			// algorithm(points[x][y], points[x + 1][y + 1], img);
			my_mlx_pixel_put(img, points[x][y].posx, points[x][y].posy, points[x][y].color);
			x++;
		}
		y++;
	}
}
