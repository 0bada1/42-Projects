/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:58:48 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/10 23:38:36 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_position	**copy_parsed_array(t_position **points1, t_position **points2, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	points2 = points1;
	while(y < img->rows)
	{
		x = 0;
		while (x < img->cols)
		{
			points2[y][x].posx = points1[y][x].posx;
			points2[y][x].posy = points1[y][x].posy;
			points2[y][x].posz = points1[y][x].posz;
			// printf("point (%i,%i)\n", img->original_points[y][x].posx, img->original_points[y][x].posy);
			x++;
		}
		y++;
	}
	return (points2);
}

// int	ft_atoh(char *str)
// {
// 	unsigned long	nbr;
// 	int				num;

// 	while (*str != ',')
// 		*str++;
// 	nbr = (unsigned long)*str;
// 	while (*str)
// 	{
// 		if (nbr >= 16)
// 			ft_atoh(nbr / 16);
// 		if (nbr % 16 < 10)
// 			num = (nbr % 16 + '0');
// 		else
// 			num = (nbr % 16 + 'a' - 10);
// 		if (str == 0)
// 			return (1);
// 	}
// 	return (num);
// }

//function converts a hex array of characters to its equivalent decimal value
int ft_atoh(char *hex)
{
	int	i;
	int	sum;
	
	i = 0;
	sum = 0;
	hex++;
	printf("hex = %s\n", hex);
	while (hex[i] != '\0')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			sum = 16 * sum + hex[i] - '0';
		else if (hex[i] >= 'A' && hex[i] <= 'Z')
			sum = 16 * sum + hex[i] - 'A' + 10;
		else if (hex[i] >= 'a' && hex[i] <= 'z')
			sum = 16 * sum + hex[i] - 'a' + 10;
		i++;
	}
	return (sum);
}

// char	*get_hex(char *str)
// {
// 	char	*s2;
// 	int		i;
// 	int		j;
	
// 	i = 0;
// 	j = 0;
// 	s2 = malloc(sizeof(char) * 6 + 1);
// 	while ((str[i] != '0' && str[i + 1] != 'x') || str[i])
// 		i++;
// 	while (str[i])
// 	{
// 		s2[j] = str[i];
// 		i++;
// 		j++;
// 	}
// 	return (s2);
// }

t_position	**resize_points(t_position **points, t_data *img)
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
			resized_points[y][x].posx *= img->size;
			resized_points[y][x].posy *= img->size;
			resized_points[y][x].posz *= img->size;
			x++;
		}
		y++;
	}
	return (resized_points);
}

// int ft_atoh(char *hex)
// {
// 	int	length;
// 	int	i;
// 	int	sum;
	
// 	length = 0;
// 	i = 0;
// 	sum = 0;
// 	while (hex[length] != '\0')
// 		length++;
// 	while (hex[i] != '\0')
// 	{
// 		if (hex[i] >= '0' && hex[i] <= '9')
// 			sum += (hex[i] - '0') * pow(16, length - 1);
// 		else if (hex[i] >= 'A' && hex[i] <= 'Z')
// 			sum += hex[i] - 'A' + 10;
// 		else if (hex[i] >= 'a' && hex[i] <= 'z')
// 			sum += hex[i] - 'a' + 10;
// 		i++;
// 		length--;
// 	}
// 	return (sum);
// }