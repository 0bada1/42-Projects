/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:37:57 by ooutabac          #+#    #+#             */
/*   Updated: 2022/07/04 20:23:43 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

// Printf functions
int		ft_printf(const char *format, ...);
int		check_place_holder(va_list args, char format);

// Libft functions
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd, int counter);
int		ft_putnbr_hexa(unsigned long n, int fd, int counter);
int		ft_putnbr_hexa_cap(unsigned long n, int fd, int counter);
int		ft_putnbr_fd_u(unsigned int n, int fd, int counter);

#	endif