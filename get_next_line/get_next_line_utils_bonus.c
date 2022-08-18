/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 10:42:11 by ooutabac          #+#    #+#             */
/*   Updated: 2022/08/07 10:42:30 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	int			bzero;
	char		*char_s;

	i = 0;
	bzero = 0;
	char_s = (char *)s;
	while (i < n)
	{
		char_s[i] = bzero;
		i++;
	}
	s = char_s;
	return ;
}

/* ft_calloc
- Used to allocate memory space for buffer which is filled with zeros.
**USE IN GET_NEXT_LINE.C**
- Allocate 'BUFFER_SIZE' space for static 'buffer'.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && (nmemb > SIZE_MAX / size))
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
// int	main(void)
// {
// 	printf("%zu", ft_calloc(SIZE_MAX, SIZE_MAX));
// }

// Unused function get_line
// int	get_line(char *text)
// {
// 	static int	i = 0;
// int			j;
// 	int			malloc_size;
// 	char		*line;
// 	// j = i;
// 	malloc_size = 0;
// 	while (text[i] != '\n' && text[i] != '\0')
// 	{
// 		i++;
// 		malloc_size++;
// 	}
// 	i++;
// 	printf("malloc_size = %i && i = %i\n", malloc_size, i);
// 	return (malloc_size);
// }
	// line = malloc(malloc_size++ * sizeof(char));
	// //printf("malloc_size = %i", malloc_size);
	// j = 0;
	// while (text[i] != '\n')
	// {
	// 	line[j] = text[i];
	/////// -i++;
	// 	j++;
	// }
	// line[j] = '\n';
	// i++;

// Unused function ft_strnstr
// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*m;
// 	m = (char *)haystack;
// 	i = 0;
// 	if (!*needle)
// 		return ((char *)haystack);
// 	while (haystack[i] != '\0' && i < len)
// 	{
// 		j = 0;
// 		while (haystack[i + j] == needle[j] && needle[j] != '\0' && i + j < len)
// 			j++;
// 		if (j == ft_strlen(needle))
// 			return (&m[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

/* ft_free2
- Used to minimize lines in "get_next_line.c" (fixing norminette)
**INITIAL LINES IN "GET_NEXT_LINE.C"**
{
free(buffer[fd]);
buffer[fd] = NULL;
return (NULL);
}
*/
// char	*ft_free2(char *s1)
// {
// 	if (s1 != NULL)
// 		free(s1);
// 	s1 = NULL;
// 	return (s1);
// }

/* ft_strnchr
- Finds a character in a string and returns it if it exists,
otherwise it returns 0
**USE IN GET_NEXT_LINE.C**
- Used to find the '\n' character when encountering a new line.
It is used as a condition in
the while loop to stop whenever a new line has been passed.
*/
char	ft_strnchr(char *haystack, char needle, size_t len)
{
	size_t	i;

	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle)
			return (needle);
		i++;
	}
	return (0);
}

// Unused function find_size
// int	find_size(char *haystack, char needle, size_t len)
// {
// 	size_t	i;
// 	i = 0;
// 	while (haystack[i] != '\0' && i < len)
// 	{
// 		if (haystack[i] == needle)
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

/* ft_substr 
- Allocates size with malloc and returns a substring from string s.
- len is maximum size of substring
- String starts at index 'start' of string s.
**USE IN GET_NEXT_LINE.C**
- After the while loop exits and the line is stores in
'buffer', 'final_line' stores that line
by running ft_substr and later 'final_line' is returned.
This is done so that when get_next_line
is called again, buffer doesn't contain the previous
lines that we already printed/returned.
*/
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

/* ft_strjoin
- Joins 2 strings together and returns them as one string.
**USE IN GET_NEXT_LINE.C**
- When a line is read and stored in 'temp_line',
it is strjoined with the full string 'buffer'
so that:
1) The previous line is not lost
2) Memory can be freed
*/
char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	size_t		s1_len;
	size_t		s2_len;
	char		*str_joined;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_joined = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str_joined == NULL)
		return (NULL);
	while (j < s1_len)
		str_joined[i++] = s1[j++];
	j = 0;
	while (j < s2_len)
		str_joined[i++] = s2[j++];
	str_joined[i] = '\0';
	free(s1);
	free(s2);
	return (str_joined);
}
