/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresengham_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:45:26 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/17 14:30:31 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_position	algorithm(t_position point1, t_position point2, t_data *img)
{
	t_position	**array;
	int			Pk;
	int			m;
	int			x;
	int			y;
	
	Pk = 2 * ((point2.posx - point1.posx) - (point2.posy - point1.posy));
	x = point1.posx;
	y = point1.posy;
	if (point1.posx == point2.posx)
	{
		draw_vert_line(point2.posy - point1.posy, x, y, img);
		return;
	}
	m = ((point2.posy - point1.posy) / (point2.posx - point1.posx));
	if (m == 0)
		draw_hor_line(point2.posx - point1.posx, x, y, img);
	else if (m < 1)
	{
		while (x <= point2.posx)
		{
			my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
			x++;
			if (Pk < 0)
				Pk += 2 * (point2.posy - point1.posy);
			else if (Pk >= 0)
			{
				Pk += 2 * (point2.posy - point1.posy) - 2 * (point2.posx - point1.posx);
				y++;
			}
		}
	}
	else if (m >= 1)
	{
		while (y <= point2.posy)
		{
			my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
			y++;
			if (Pk < 0)
				Pk += 2 * (point2.posx - point1.posx);
			else if (Pk >= 0)
			{
				Pk += 2 * (point2.posx - point1.posx) - 2 * (point2.posy - point1.posy);
				x++;
			}
		}
	}
}

void	draw_algorithm