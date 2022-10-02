/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:21:05 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/29 20:55:02 by ooutabac         ###   ########.fr       */
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

// remove printf
int	find_number_of_rows(int fd)
{
	int i;
	
	i = 0;
	while (get_next_line(fd) != 0)
		i++;
	printf("\nBytes read = %i\n", i);
	return (i);
}

int	find_number_of_columns(int fd)
{
	int		col;
	char	*gtl;
	
	gtl =  get_next_line(fd);
	printf("\n%s\n", gtl);
	col = ft_strlen2(gtl);
	printf("\ncolumns = %i\n", col);
	return (col);
}

int ft_strlen2(char *str)
{
	int	i;
	int	counter;
	
	i = 0;
	counter = 0;
	while (str != NULL && str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != ' ')
			counter++;
		i++;
	}
	printf("cols = %i", counter);
	return (counter);
}

t_position	find_cols_rows(int fd)
{
	t_position	pos;
	int			i;
	char		*gtl;

	i = 0;
	// pos = NULL;
	ft_bzero(&pos, sizeof(pos));
	// problem from line below
	pos.posy = 0;
	gtl = get_next_line(fd);
	// for columns
	while (gtl[i] != '\0' && gtl != NULL)
	{
		if (gtl[i] >= '0' && gtl[i] <= '9' && gtl[i - 1] == ' ')
			pos.posy++;
		i++;
	}
	// for rows
	// pos.posx = 1 because we already used get_next_line() once, therefore it had gone through the first row already
	pos.posx = 1;
	while (gtl != NULL)
	{
		gtl = get_next_line(fd);
		pos.posx++;
	}
	// printf("columns = %i", pos.posy);
	// printf("rows = %i", pos.posx);
	return (pos);	
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