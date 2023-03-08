/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 06:30:14 by ooutabac          #+#    #+#             */
/*   Updated: 2022/11/27 19:53:58 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_moved;
	char	*src_moved;

	dst_moved = (char *)dst;
	src_moved = (char *)src;
	if (dst == src)
	{
		return (dst);
	}
	if (dst > src)
	{
		while (len--)
		{
			dst_moved[len] = src_moved[len];
		}
		return (dst);
	}
	else
	{
		while (len--)
		{
			*dst_moved++ = *src_moved++;
		}
		return (dst);
	}
}

// int main ()
// {
//   char str1[] = "Geeee"; 
//   char str2[] = "Kkkkkkkkk"; 
//   puts("str1 before mem");
//   puts(str1);
//   ft_memmove(str1 + 1, str1, 20);
//   puts("\nstr1 after mem ");
//   puts(str1);
//   return 0;
// }