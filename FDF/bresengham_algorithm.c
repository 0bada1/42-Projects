/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresengham_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:45:26 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/29 16:01:48 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Not drawing diagonal lines properly. Search for fix.
// void	algorithm(t_position point1, t_position point2, t_data *img)
// {
// 	// t_position	**array;
// 	int			Pk;
// 	int			x;
// 	int			y;
// 	int			m;
	
// 	Pk = 2 * ((point2.posx - point1.posx) - (point2.posy - point1.posy));
// 	x = point1.posx;
// 	y = point1.posy;
// 	if (point1.posx == point2.posx)
// 	{
// 		printf("This is m = infinite\n");
// 		draw_vert_line(point2.posy - point1.posy, x, y, img);
// 		return;
// 	}
// 	m = ((point2.posy - point1.posy) / (point2.posx - point1.posx) * 1.0);
// 	// if (m == 0)
// 	// {
// 	// 	printf("This line is horizontal\n");
// 	//	x -= 2;
// 	//	y -= 2;
// 	// 	draw_hor_line(point2.posx - point1.posx, x, y, img);
// 	// }
// 	if (m < 1)
// 	{
// 		printf("This is m < 1 && m > 0\n");
// 		x -= 2;
// 		y -= 2;
// 		while (x <= point2.posx)
// 		{
// 			my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
// 			x++;
// 			if (Pk < 0)
// 				Pk += 2 * (point2.posy - point1.posy);
// 			else if (Pk >= 0)
// 			{
// 				Pk += 2 * (point2.posy - point1.posy) - 2 * (point2.posx - point1.posx);
// 				y++;
// 			}
// 		}
// 	}
// 	else if (m >= 1)
// 	{
// 		printf("This is m >= 1\n");
// 		while (y <= point2.posy)
// 		{
// 			my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
// 			y++;
// 			if (Pk < 0)
// 				Pk += 2 * (point2.posx - point1.posx);
// 			else if (Pk >= 0)
// 			{
// 				Pk += 2 * (point2.posx - point1.posx) - 2 * (point2.posy - point1.posy);
// 				x++;
// 			}
// 		}
// 	}
// }

void	algorithm(t_position point1, t_position point2, t_data *img)
{
	int			Pk;

	// printf("Point1.posx = %i\nPoint1.posy = %i\nPoint2.posx = %i\nPoint2.posy = %i\n", point1.posx, point1.posy, point2.posx, point2.posy);
	Pk = 2 * ((point2.posx - point1.posx) - (point2.posy - point1.posy));
	check_conditions_and_redirect(Pk, point1, point2, img);

}

/*
Functions to handle each slope
FUNCTION 1 : M is less than 1 and y2 is less than y1, therefore
y must be found through sampling and both are incremented.
FUNCTION 2 : M is greater than 1 and x2 is less than x1, therefore
x must be found through sampling and both are incremented.
FUNCTION 3 : M is less than 1 and y2 is greater than y1, therefore
y must be found through sampling and both are decremented.
FUNCTION 4 : M is greater than 1 and x2 is greater than x1, therefore
x must be found through sampling and both are decremented.
*/
void	check_conditions_and_redirect(int Pk, t_position point1, t_position point2, t_data *img)
{
	float	m;

	if (point1.posx == point2.posx && point1.posy > point2.posy)
	{
		draw_vert_line(point2.posy - point1.posy, point1.posx, point1.posy, img);
		return ;
	}
	else if (point1.posx == point2.posx && point1.posy < point2.posy)
	{
		draw_vert_line_reverse(point1.posy - point2.posy, point1.posx, point2.posx, img);
		return ;
	}
	m = (((point2.posy - point1.posy) * 1.0) / ((point2.posx - point1.posx) * 1.0));
	// printf("m = %f\n", m);
	if (m < 1 && m > 0 && point1.posx < point2.posx && point1.posy < point2.posy)
		algorithm_m_less_than_1_and_greater_than_0(Pk, point1, point2, img);
	else if (m >= 1 && point1.posx < point2.posx && point1.posy < point2.posy)
		algorithm_m_greater_than_or_equal_to_1(Pk, point1, point2, img);
	else if (m < 0 && m > -1 && point1.posx < point2.posx && point1.posy > point2.posy)
		algorithm_m_less_than_0_and_greater_than_minus1(Pk, point1, point2, img);
		// printf("enterting function\n");
	else if (m <= -1 && point1.posx < point2.posx && point1.posy > point2.posy)
		algorithm_m_less_than_or_equal_to_minus1(Pk, point1, point2, img);
	else if (m == 0 && point1.posx < point2.posx)
		draw_hor_line(point2.posx - point1.posx, point1.posx, point1.posy, img);
	else if (m == 0 && point1.posx > point2.posx)
		draw_hor_line_reverse(point1.posx - point2.posx, point1.posx, point1.posy, img);
	else if (m < 1 && m > 0 && point1.posx > point2.posx && point1.posy > point2.posy)
		algorithm_m_less_than_1_and_greater_than_0_reverse(Pk, point1, point2, img);
	else if (m >= 1 && point1.posx > point2.posx && point1.posy > point2.posy)
		algorithm_m_greater_than_or_equal_to_1_reverse(Pk, point1, point2, img);
	else if (m <= -1 && point1.posx > point2.posx && point1.posy < point2.posy)
		algorithm_m_less_than_or_equal_to_minus1_reverse(Pk, point1, point2, img);
	else if (m < 0 && m > -1 && point1.posx > point2.posx && point1.posy < point2.posy)
		algorithm_m_less_than_0_and_greater_than_minus1_reverse(Pk, point1, point2, img);
}
// FUNCTION 1
void	algorithm_m_less_than_1_and_greater_than_0(int Pk, t_position point1, t_position point2, t_data *img)
{
	int	x;
	int	y;

	// if (point1.posx > point2.posx)
	// {
	// 	ft_swap(&point1.posx, &point2.posx);
	// 	ft_swap(&point1.posy, &point2.posy);
	// }
	// if (point1.posy > point2.posy)
	// {
	// 	algorithm_m_less_than_1_and_greater_than_0_reverse(Pk, point1, point2, img);
	// 	return ;
	// }
	// x = point1.posx - 2;
	// y = point1.posy - 2;
	x = point1.posx;
	y = point1.posy;
	// printf("0 < m < 1 && point1 (%i, %i) to point2 (%i, %i)\n", point1.posx, point1.posy, point2.posx, point2.posy);
	while (x <= point2.posx)
	{
		// printf("This is m < 1 && m > 0\n");
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

//	FUNCTION 2
void	algorithm_m_greater_than_or_equal_to_1(int Pk, t_position point1, t_position point2, t_data *img)
{
	int	x;
	int	y;

	// if (point1.posy > point2.posy)
	// {
	// 	ft_swap(&point1.posx, &point2.posx);
	// 	ft_swap(&point1.posy, &point2.posy);
	// }
	// if (point1.posy > point2.posy)
	// {
	// 	algorithm_m_greater_than_or_equal_to_1_reverse(Pk, point2, point1, img);
	// 	return ;
	// }
	x = point1.posx;
	y = point1.posy;
	// printf("m >= 1 && point1 (%i, %i) to point2 (%i, %i)\n", point1.posx, point1.posy, point2.posx, point2.posy);
	while (y <= point2.posy)
	{
		// printf("This is m >= 1\n");
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

//	FUNCTION 3
void	algorithm_m_less_than_0_and_greater_than_minus1(int Pk, t_position point1, t_position point2, t_data *img)
{
	int	x;
	int	y;

	// if (point1.posx > point2.posx)
	// {
	// 	ft_swap(&point1.posx, &point2.posx);
	// 	ft_swap(&point1.posy, &point2.posy);
	// }
	if (point1.posy < point2.posy)
	{
		algorithm_m_less_than_0_and_greater_than_minus1_reverse(Pk, point2, point1, img);
		return ;
	}
	// x = point1.posx - 2;
	// y = point1.posy + 2;
	x = point1.posx;
	y = point1.posy;
	// printf("-1 < m < 0 && point1 (%i, %i) to point2 (%i, %i)\n", point1.posx, point1.posy, point2.posx, point2.posy);
	while (x <= point2.posx)
	{
		// printf("m < 0 && m > -1\n");
		// printf("Pk = %i\n", Pk);
		my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
		x++;
		if (Pk < 0)
			Pk += 2 * (point1.posy - point2.posy);
		else if (Pk >= 0)
		{
			Pk += (2 * (point1.posy - point2.posy)) - (2 * (point2.posx - point1.posx));
			y--;
		}
	}
}
// Pk += 2 * (point2.posy - point1.posy);
// Pk += (2 * (point2.posy - point1.posy)) - (2 * (point2.posx - point1.posx));

//	FUNCTION 4
void	algorithm_m_less_than_or_equal_to_minus1(int Pk, t_position point1, t_position point2, t_data *img)
{
	int	x;
	int	y;

	// if (point1.posx > point2.posx)
	// {
	// 	ft_swap(&point1.posx, &point2.posx);
	// 	ft_swap(&point1.posy, &point2.posy);
	// }
	if (point1.posy < point2.posy && point1.posx > point2.posy)
	{
		algorithm_m_less_than_or_equal_to_minus1_reverse(Pk, point2, point1, img);
		return ;
	}
	// x = point1.posx - 2;
	// y = point1.posy + 2;
	x = point1.posx;
	y = point1.posy;
	// printf("m <= -1 && point1 (%i, %i) to point2 (%i, %i)\n", point1.posx, point1.posy, point2.posx, point2.posy);
	while (x <= point2.posx)
	{
		// printf("m <= -1\n");
		// printf("x = %i\n", x);
		// printf("Pk = %i\n", Pk);
		my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
		y--;
		if (Pk < 0)
			Pk += 2 * (point2.posx - point1.posx);
		else if (Pk >= 0)
		{
			Pk += (2 * (point2.posx - point1.posx)) - (2 * (point1.posy - point2.posy));
			x++;
		}
	}
}

void	ft_swap(int	*a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
//	REVERSE FUNCTIONS

//	FUNCTION 1
void	algorithm_m_less_than_1_and_greater_than_0_reverse(int Pk, t_position point1, t_position point2, t_data *img)
{
	int	x;
	int	y;

	// if (point1.posx > point2.posx)
	// {
	// 	ft_swap(&point1.posx, &point2.posx);
	// 	ft_swap(&point1.posy, &point2.posy);
	// }
	x = point1.posx;
	y = point1.posy;
	// printf("0 < m < 1 reverse && point1 (%i, %i) to point2 (%i, %i)\n", point1.posx, point1.posy, point2.posx, point2.posy);
	while (x >= point2.posx)
	{
		// printf("Pk = %i\n", Pk);
		my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
		x--;
		if (Pk < 0)
			Pk += 2 * (point1.posy - point2.posy);
		else if (Pk >= 0)
		{
			Pk += 2 * (point1.posy - point2.posy) - 2 * (point1.posx - point2.posx);
			y--;
		}
	}
}

//	FUNCTION 2
void	algorithm_m_greater_than_or_equal_to_1_reverse(int Pk, t_position point1, t_position point2, t_data *img)
{
	int	x;
	int	y;

	// if (point1.posy > point2.posy)
	// {
	// 	ft_swap(&point1.posx, &point2.posx);
	// 	ft_swap(&point1.posy, &point2.posy);
	// }
	// x = point1.posx + 1;
	// y = point1.posy;
	x = point1.posx;
	y = point1.posy;
	// printf("m >= 1 reverse && point1 (%i, %i) to point2 (%i, %i)\n", point1.posx, point1.posy, point2.posx, point2.posy);
	while (y >= point2.posy)
	{
		// printf("Pk = %i\n", Pk);
		my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
		y--;
		if (Pk < 0)
			Pk += 2 * (point1.posx - point2.posx);
		else if (Pk >= 0)
		{
			Pk += 2 * (point1.posx - point2.posx) - 2 * (point1.posy - point2.posy);
			x--;
		}
	}
}

//	FUNCTION 3
void	algorithm_m_less_than_0_and_greater_than_minus1_reverse(int Pk, t_position point1, t_position point2, t_data *img)
{
	int	x;
	int	y;

	// if (point1.posx > point2.posx)
	// {
	// 	ft_swap(&point1.posx, &point2.posx);
	// 	ft_swap(&point1.posy, &point2.posy);
	// }
	// x = point1.posx + 1;
	// y = point1.posy;
	x = point1.posx;
	y = point1.posy;
	// printf("-1 < m < 0 reverse && point1 (%i, %i) to point2 (%i, %i)\n", point1.posx, point1.posy, point2.posx, point2.posy);
	while (x >= point2.posx)
	{
		// printf("Pk = %i\n", Pk);
		my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
		x--;
		if (Pk < 0)
			Pk += 2 * (point2.posy - point1.posy);
		else if (Pk >= 0)
		{
			Pk += (2 * (point2.posy - point1.posy)) - (2 * (point1.posx - point2.posx));
			y++;
		}
	}
}

//	FUNCTION 4
void	algorithm_m_less_than_or_equal_to_minus1_reverse(int Pk, t_position point1, t_position point2, t_data *img)
{
	int	x;
	int	y;

	// if (point1.posx > point2.posx)
	// {
	// 	ft_swap(&point1.posx, &point2.posx);
	// 	ft_swap(&point1.posy, &point2.posy);
	// }
	x = point1.posx;
	y = point1.posy;
	// printf("m <= -1 reverse && point1 (%i, %i) to point2 (%i, %i)\n", point1.posx, point1.posy, point2.posx, point2.posy);
	while (x >= point2.posx && y <= point2.posy)
	{
		// printf("m <= -1 reverse\n");
		// printf("x = %i\n", x);
		my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
		y++;
		if (Pk < 0)
			Pk += 2 * (point1.posx - point2.posx);
		else if (Pk >= 0)
		{
			Pk += (2 * (point1.posx - point2.posx)) - (2 * (point2.posy - point1.posy));
			x--;
		}
	}
}