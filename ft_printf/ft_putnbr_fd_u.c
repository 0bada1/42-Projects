/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:07:55 by ooutabac          #+#    #+#             */
/*   Updated: 2022/07/04 20:22:27 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_u(unsigned int n, int fd, int counter)
{
	unsigned int	nbr;
	int				count;

	count = counter;
	nbr = n;
	if (nbr >= 10)
		ft_putnbr_fd_u(nbr / 10, fd, count);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
	if (n == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

/*int main(void)
{
	int i;

	i = -100;
	while (i != 500)
	{
		ft_putnbr_fd(i, 1);
		i+= 50;
		printf("\n");
	}
	printf("\n");
	ft_putnbr_fd(-2147483648LL, 2);
	printf("\n");
	return 0;
}*/