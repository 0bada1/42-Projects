/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:18:52 by ooutabac          #+#    #+#             */
/*   Updated: 2022/07/04 20:22:11 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_ft_printf(int n, int fd, int counter)
{
	unsigned int	nbr;
	int				count;

	count = counter;
	if (n < 0)
	{
		ft_putchar_fd_ft_printf('-', fd);
		count++;
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_fd_ft_printf(nbr / 10, fd, count);
	ft_putchar_fd_ft_printf((char)(nbr % 10 + 48), fd);
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
		ft_putnbr_fd_ft_printf(i, 1);
		i+= 50;
		printf("\n");
	}
	printf("\n");
	ft_putnbr_fd_ft_printf(-2147483648LL, 2);
	printf("\n");
	return 0;
}*/