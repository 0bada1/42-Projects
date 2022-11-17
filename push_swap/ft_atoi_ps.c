/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:52:30 by ooutabac          #+#    #+#             */
/*   Updated: 2022/11/12 16:57:36 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	atoi_error(t_node *stack)
{
	free_everything(stack);
	write(1, "Error\n", 6);
	exit (1);
}

int	ft_atoi_ps(const char *str, t_node *stack)
{
	int			i;
	int			j;
	long long	value;

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
		if (value * j < INT_MIN || value * j > INT_MAX)
			atoi_error(stack);
		value = (value * 10) + (str[i] - 48);
		i++;
	}
	return (value * j);
}
