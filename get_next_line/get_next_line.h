/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:40:49 by ooutabac          #+#    #+#             */
/*   Updated: 2022/08/07 10:45:10 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Defining variables
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif
// Libraries
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

// Prototypes
char	*get_next_line(int fd);
char	ft_strnchr(char *haystack, char needle, size_t len);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_free1(char *s1, char *s2);
char	*ft_free2(char *s1);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*get_next_line_while_loop(char **buffer, int fd);
size_t	ft_strlen(const char *txt);

#	endif