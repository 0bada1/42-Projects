/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:27:12 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/10 22:22:20 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
				algorithm(points, current_point, points[y][x + 1], img);
			if (y + 1 < img->rows)
				algorithm(points, current_point, points[y + 1][x], img);
			x++;
			current_point = points[y][x];
		}
		y++;
	}
}
// printf("current_point[%i][%i] to points[%i][%i]\n", points[y][x].posx, points[y][x].posy, points[y][x + 1].posx, points[y][x + 1].posy);
// printf("current_point[%i][%i] to points[%i][%i]\n", points[y][x].posx, points[y][x].posy, points[y + 1][x].posx, points[y + 1][x].posy);