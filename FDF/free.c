/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:38:16 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/09 21:38:25 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_parsed_map(t_position **points, t_data *img)
{
	int	y;

	y = 0;
	while (y + 1 < img->rows)
	{
		free(points[y]);
		y++;
	}
	free (points);
}

// void	free_img(t_data *img)
// {
// 	while ()
// }