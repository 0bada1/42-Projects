/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:31:08 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/24 18:49:35 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	size_t	value;

	i = 0;
	j = 1;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - 48);
		i++;
	}
	if (value > 2147483647 && j == 1)
		return (-1);
	if (value > 2147483648 && j == -1)
		return (0);
	return (value * j);
}

// int main(void)
// {
// 	printf("%i\n", ft_atoi("0xFFFFFF"));
// 	printf("%i\n", atoi("0xFFFFFF"));
// }