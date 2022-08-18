/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_cap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:46:21 by ooutabac          #+#    #+#             */
/*   Updated: 2022/07/04 19:59:26 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa_cap(unsigned long n, int fd, int counter)
{
	unsigned long	nbr;
	int				count;

	count = counter;
	nbr = (unsigned long)n;
	if (nbr >= 16)
		ft_putnbr_hexa_cap(nbr / 16, fd, count);
	if (nbr % 16 < 10)
		ft_putchar_fd((char)(nbr % 16 + '0'), fd);
	else
		ft_putchar_fd((char)(nbr % 16 + 'A' - 10), fd);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}
