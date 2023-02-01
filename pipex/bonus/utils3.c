/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:45:15 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 19:56:15 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_struct(t_pipex *args)
{
	t_counter	counter;

	counter.i = 0;
	counter.j = 0;
	counter.k = 0;
	counter.m = 0;
	counter.n = 0;
	ft_printf("\nPRINTING COMMANDS:\n");
	while (counter.i < args->number_of_commands)
		ft_printf("%s\n", args->cmd[counter.i++]);
	ft_printf("\nPRINTING RAW COMMANDS:\n");
	while (counter.n < args->number_of_commands)
		ft_printf("%s\n", args->cmd_raw[counter.n++]);
	ft_printf("\nPRINTING COMMANDS PATH:\n");
	while (counter.j < args->number_of_commands)
		ft_printf("%s\n", args->cmd_path[counter.j++]);
	ft_printf("\nPRINTING COMMANDS WITH NO FLAGS:\n");
	while (counter.k < args->number_of_commands)
		ft_printf("%s\n", args->cmd_noflag[counter.k++]);
	ft_printf("\nPRINTING FULL PATH:\n%s\n", args->full_path);
	ft_printf("\nPRINTING SPLIT PATHS:\n");
	while (args->path[counter.m])
		ft_printf("%s\n", args->path[counter.m++]);
	ft_printf("\n\n");
	return ;
}

char	*get_next(int fd)
{
	char	*copy;
	char	*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	copy = ft_calloc(sizeof(char), 100000);
	tmp = copy;
	while (read(fd, tmp, 1))
	{
		if (*(tmp++) == '\n')
			break ;
	}
	if (copy[0] == '\0')
	{
		free(copy);
		return (NULL);
	}
	else
		return (copy);
	return (copy);
}

int	record_here_doc(int here_doc, char *limiter)
{
	char		*string;
	size_t		limiter_length;
	int			trigger;

	string = NULL;
	trigger = 0;
	limiter_length = ft_strlen(limiter);
	while (string || trigger == 0)
	{
		trigger = 1;
		write(1, "> ", 2);
		string = get_next(STDIN_FILENO);
		if (ft_strncmp(string, limiter, limiter_length) == 0
			&& ft_strlen(string) - 1 == limiter_length)
			break ;
		write(here_doc, string, ft_strlen(string));
		free(string);
	}
	free(string);
	return (here_doc);
}

t_pipex	*calloc_pipex(t_pipex *args, int argc, char *argv[])
{
	args->cmd_noflag = ft_calloc(sizeof(char *), args->number_of_commands);
	args->cmd_path = ft_calloc(sizeof(char *), args->number_of_commands);
	args->cmd_raw = ft_calloc(sizeof(char *), args->number_of_commands);
	args->cmd = ft_calloc(sizeof(char *), args->number_of_commands);
	args->infile_fd = open(argv[1], O_RDONLY, 0777);
	args->outfile_fd = open(argv[argc - 1], O_CREAT | O_WRONLY
			| O_RDONLY | O_TRUNC, 0777);
	return (args);
}

t_pipex	*execution_loop(t_pipex *args, int *pipe_fd[])
{
	int	i;

	i = 0;
	while (i < args->number_of_commands)
	{
		fork_dup_execute(args, i, pipe_fd);
		i++;
	}
	close_files(args, pipe_fd);
	i = 0;
	while (i++ < args->number_of_commands)
		waitpid(-1, NULL, 0);
	free_everything(args);
	return (args);
}
