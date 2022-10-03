/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:58:48 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/03 18:59:51 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_position	**copy_parsed_array(t_position **points1, t_position **points2, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while(y < img->rows)
	{
		x = 0;
		while (x < img->cols)
		{
			points2[y][x].posx = points1[y][x].posx;
			points2[y][x].posy = points1[y][x].posy;
			points2[y][x].posz = points1[y][x].posz;
			printf("point (%i,%i)\n", img->original_points[y][x].posx, img->original_points[y][x].posy);
			x++;
		}
		y++;
	}
	return (points2);
}