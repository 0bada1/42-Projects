/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:21:05 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/03 14:30:22 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Add t_data *img to parameter to make the function more dynamic..
input to this function will have to be manually changed everytime window
size is changed. can itterate till next pixel = '\0' and then / 2
*/
int	find_center_point_x(int max_x)
{
	int x;
	
	x = max_x/2;
	
	return (x);
}

int	find_center_point_y(int max_y)
{
	int y;
	
	y = max_y/2;
	return (y);
}

// int	img_to_screen_ratio(t_data *img)
// {
// 	int	ratio_x;
// 	int	ratio_y;

// 	ratio_x = (img->screen_size_x / img->cols);
// 	ratio_y = (img->screen_size_y / img->rows);
// 	img->ratio_x = ratio_x;
// 	img->ratio_y = ratio_y;
// 	printf("ratio_x = %i\nratio_y = %i\n", img->ratio_x, img->ratio_y);
// 	return (ratio_x);
// }