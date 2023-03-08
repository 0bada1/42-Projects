/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:38:33 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 20:46:31 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_files(t_pipex *args, int *pipe_fd[])
{
	int	x;

	x = 0;
	while (x < args->number_of_commands - 1)
	{
		close(pipe_fd[x][0]);
		close(pipe_fd[x][1]);
		free(pipe_fd[x]);
		x++;
	}
	free(pipe_fd);
	close(args->outfile_fd);
	close(args->infile_fd);
	if (args->here_doc)
		close(args->here_doc);
	return (0);
}

void	free_2d(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

void	free_everything(t_pipex *args)
{
	t_counter	count;

	if (args->path != NULL)
		free_2d(args->path);
	count.i = 0;
	while (count.i < args->number_of_commands)
	{
		if (args->cmd_noflag[count.i] != NULL)
			free(args->cmd_noflag[count.i]);
		count.i++;
	}
	if (args->cmd_noflag)
		free(args->cmd_noflag);
	count.i = 0;
	while (count.i < args->number_of_commands)
	{
		if (args->cmd[count.i] != NULL)
			free(args->cmd[count.i]);
		count.i++;
	}
	if (args->cmd)
		free(args->cmd);
	free2(args);
	return ;
}

void	free2(t_pipex *args)
{
	t_counter	count;

	count.i = 0;
	while (count.i < args->number_of_commands)
	{
		if (args->cmd_path[count.i] != NULL)
			free(args->cmd_path[count.i]);
		count.i++;
	}
	free(args->cmd_path);
	count.i = 0;
	while (count.i < args->number_of_commands)
	{
		if (args->cmd_raw[count.i] != NULL)
			free(args->cmd_raw[count.i]);
		count.i++;
	}
	free(args->cmd_raw);
	if (args->full_path != NULL)
		free(args->full_path);
	if (args->limiter != NULL)
		free(args->limiter);
	if (args != NULL)
		free(args);
}
