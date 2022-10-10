/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:33:27 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/10 19:41:16 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_position	**revert_minus(t_position **points, t_data *img)
{
	t_position	**resized_points;
	int			x;
	int			y;

	resized_points = points;
	x = 0;
	y = 0;
	if (!points)
		return (NULL);
	while (y < img->rows && img->size >= 0)
	{
		x = 0;
		while (x < img->cols && points && img->size >= 0)
		{
			resized_points[y][x].posx /= (img->size);
			resized_points[y][x].posy /= (img->size);
			resized_points[y][x].posz /= (img->size);
			x++;
		}
		y++;
	}
	return (resized_points);
}

t_position	**revert_plus(t_position **points, t_data *img)
{
	t_position	**resized_points;
	int			x;
	int			y;

	resized_points = points;
	x = 0;
	y = 0;
	if (img->size <= 0)
		img->size++;
	if (!points)
		return (NULL);
	while (y < img->rows)
	{
		x = 0;
		while (x < img->cols && points)
		{
			resized_points[y][x].posx /= (img->size);
			resized_points[y][x].posy /= (img->size);
			resized_points[y][x].posz /= (img->size);
			x++;
		}
		y++;
	}
	return (resized_points);
}
