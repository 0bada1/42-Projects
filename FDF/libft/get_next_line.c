/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:39:39 by ooutabac          #+#    #+#             */
/*   Updated: 2022/09/24 19:01:57 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Libraries
#include "libft.h"

/* get_next_line.c
**VARIABLES**
A 2d array buffer stores the number of bytes read
(which is the return value of function read) ..
- "if (!buffer[fd])" allocates memory for buffer only the first
time it is used since it'd be
null the first time.
- "if (fd < 0 || BUFFER_SIZE <= 0)" means that the file is empty and
there are no bytes to read
or the buffer size is 0 therefore no bytes can be read.
- The while loop uses 'ft_strnchr' which would search for the '\n'
character in 'BUFFER_SIZE'
number of bytes.
Size is allocated for 'temp_line' everytime, but is freed before so
that previous line is not lost (to prevent memory leaks)
*/
char	*get_next_line(int fd)
{
	char		*final_line;
	int			i;
	char		*old_buffer;
	static char	*buffer[4000];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_calloc_gtl(BUFFER_SIZE + 1, sizeof(char));
		if (buffer[fd] == NULL)
			return (NULL);
	}
	if (get_next_line_while_loop(&buffer[fd], fd) == NULL)
		return (NULL);
	i = 0;
	while (buffer[fd][i] != '\n' && buffer[fd][i] != '\0')
		i++;
	old_buffer = buffer[fd];
	final_line = ft_substr_gtl(old_buffer, 0, i + 1);
	buffer[fd] = ft_substr_gtl(old_buffer, i + 1, ft_strlen_gtl(buffer[fd]));
	free(old_buffer);
	return (final_line);
}

char	*get_next_line_while_loop(char **buffer, int fd)
{
	int		j;
	char	*temp_line;

	j = 0;
	while (ft_strnchr_gtl(*buffer, '\n', BUFFER_SIZE) != '\n')
	{
		temp_line = ft_calloc_gtl(BUFFER_SIZE + 1, sizeof(char));
		j = read(fd, temp_line, BUFFER_SIZE);
		temp_line[j] = '\0';
		*buffer = ft_strjoin_gtl(*buffer, temp_line);
		if (j <= 0 && *buffer[0] == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		if (j < BUFFER_SIZE)
			break ;
	}
	return (*buffer);
}

size_t	ft_strlen_gtl(const char *txt)
{
	size_t	i;

	i = 0;
	while (txt[i] != '\0')
		i++;
	return (i);
}

/* ft_free1
- Used to minimize lines in "get_next_line.c" (fixing norminette)
**INITIAL LINES IN "GET_NEXT_LINE.C"**
{
free(temp_line);
free(buffer[fd]);
buffer[fd] = NULL;
return (NULL);
}
*/
char	*ft_free1(char *s1, char *s2)
{
	free(s1);
	free(s2);
	s2 = NULL;
	return (s2);
}

/* Main function
Can make use of open/fopen function in main.
Also fopen works by indicating file and then "r" for read mode.
**USE OF OPEN/FOPEN**
1) open:
arguments : 3+
argv[0] = file to open ("file.txt")
argv[1] = mode to open in (O_RDONLY means read mode)
argv[2] = variadic function (just put in a 0)
2) fopen:
arguments : 2
argv[0] = file to open (file.txt)
argv[1] = mode to open in ("r" means read and "w" means write)
*/
// int	main(void)
// {
// 	int	fd1 = open("file2.txt", O_RDONLY, 0);
// 	int	fd2 = open ("file.txt", O_RDONLY, 0);
// 	int		i = 0;

// 	while (i < 10)
// 	{
// 		char	*line1 = get_next_line(fd1);
// 		char	*line2 = get_next_line(fd2);
// 		printf("%s%s", line1, line2);
// 		i++;
// 		free(line1);
// 		free(line2);
// 	}
// }