/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:21:33 by ooutabac          #+#    #+#             */
/*   Updated: 2022/12/22 14:43:57 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	*ft_memset(void *b, int c, size_t len);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	j = dest_length;
	i = 0;
	if (dest_length < size - 1 && size > 0)
	{
		while (src[i] && dest_length + i < size - 1)
			dst[j++] = src[i++];
		dst[j] = 0;
	}
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}

// int	main(void)
// {
// 	char *dest = "hellooo";
// 	char *src = "world";
// 	printf("%zu\n", ft_strlcat(dest, src, 15));
// 	// printf("%s\n", dest);
// 	// ft_memset(dest, 'r', 15);
// 	// printf("%zu", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
// 	// write(1, "\n", 1);
// 	write(1, dest, 15);
// }

/*void	*ft_memset(void *b, int c, size_t len)
{
	char	*altb;

	altb = b;
	while (len--)
		*altb++ = (unsigned char)c;
	return (b);
}*/