/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:50:56 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/10 21:02:28 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str_copy;

	i = 0;
	str_copy = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (!s || !str_copy)
		return (NULL);
	while (s[i] != '\0')
	{
		str_copy[i] = f(i, s[i]);
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}

/*int main(void)
{
    ft_strmapi();
}*/
