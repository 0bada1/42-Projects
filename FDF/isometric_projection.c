/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:46:14 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/02 22:12:11 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
ISOMETRIC PROJECTION MATRICES FORMULA
[cx]	[1		0		0	][cosß		0		-sinß][ax]
[cy] =  [0		cosα	sinα][0			1			0][ay]
[cz]	[0		-sinα	cosα][sinß		0		 cosß][az]

[bx]	[1		0		0][cx]
[by] = 	[0		1		0][cy]
[0]	 	[0		0		0][cz]
*/
t_position	**isometric_projection(t_position **points, t_data *img)
{
	t_position	**projected_points;
	int			x;
	int			y;

	projected_points = points;
	y = 0;
	if (!points)
		return (NULL);
	while (y < img->rows)
	{
		x = 0;
		while (x < img->cols && points)
		{
			// projected_points[y][x].posx *= img->size;
			// projected_points[y][x].posy *= img->size;
			// projected_points[y][x].posz *= img->size;
			projected_points[y][x].posx = ((cos(beta) * points[y][x].posx) + (sin(alpha) * sin(beta) * points[y][x].posy) + (cos(alpha) * cos(beta) * points[y][x].posz));
			projected_points[y][x].posy = ((cos(alpha) * points[y][x].posy) - (sin(alpha) * points[y][x].posz));
			projected_points[y][x].posz = 0;
			x++;
		}
		y++;
	}
	return (projected_points);
}