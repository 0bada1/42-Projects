/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:34:23 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/19 22:15:54 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'
				|| format[i + 1] == 'd' || format[i + 1] == 'i'
				|| format[i + 1] == 'p' || format[i + 1] == 'X'
				|| format[i + 1] == 'x' || format[i + 1] == '%'
				|| format[i + 1] == 'u'))
		{
			count += check_place_holder(args, format[i + 1]);
			i += 2;
		}
		else
			count += ft_putchar_fd_ft_printf(format[i++], 1);
	}
	va_end(args);
	return (count);
}

int	check_place_holder(va_list args, char format)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter += ft_putchar_fd_ft_printf(va_arg(args, int), 1);
	else if (format == 's')
		counter += ft_putstr_fd_ft_printf(va_arg(args, char *), 1);
	else if (format == 'd' || format == 'i')
		counter += ft_putnbr_fd_ft_printf(va_arg(args, int), 1, 0);
	else if (format == 'p')
	{
		write(1, "0x", 2);
		counter += ft_putnbr_hexa(va_arg(args, unsigned long), 1, 0) + 2;
	}
	else if (format == 'X')
		counter += ft_putnbr_hexa_cap(va_arg(args, unsigned int), 1, 0);
	else if (format == 'x')
		counter += ft_putnbr_hexa(va_arg(args, unsigned int), 1, 0);
	else if (format == '%')
		counter += write(1, "%%", 1);
	else if (format == 'u')
		counter += ft_putnbr_fd_ft_printf_u(va_arg(args, unsigned int), 1, 0);
	return (counter);
}

// int	main(void)
// {
// 	//int		num = NULL;
// 	//char	letter = 'O';
// 	char	*letters = NULL;
// 	int 	a = printf("%s", letters);
// 	int 	b = ft_printf("%s", letters);
// 	printf("\n");
// 	ft_printf("%i\n%i\n", a, b);
// }