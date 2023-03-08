/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:38:33 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 15:16:56 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_files(t_pipex *args, int pipe_fd[])
{
	if (args->infile_fd >= 0)
		close(args->infile_fd);
	if (args->outfile_fd >= 0)
		close(args->outfile_fd);
	if (pipe_fd[0] >= 0)
		close(pipe_fd[0]);
	if (pipe_fd[1] >= 0)
		close(pipe_fd[1]);
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
	if (args->path != NULL)
		free_2d(args->path);
	if (args->cmd1_raw != NULL)
		free(args->cmd1_raw);
	if (args->cmd2_raw != NULL)
		free(args->cmd2_raw);
	if (args->cmd1_noflag != NULL)
		free(args->cmd1_noflag);
	if (args->cmd2_noflag != NULL)
		free(args->cmd2_noflag);
	free2(args);
	return ;
}

void	free2(t_pipex *args)
{
	if (args->cmd1 != NULL)
		free(args->cmd1);
	if (args->cmd2 != NULL)
		free(args->cmd2);
	if (args->full_path != NULL)
		free(args->full_path);
	if (args->cmd1_path != NULL)
	{
		free(args->cmd1_path);
		args->cmd1_path = NULL;
	}
	if (args->cmd2_path != NULL)
	{
		free(args->cmd2_path);
		args->cmd2_path = NULL;
	}
	if (args != NULL)
		free(args);
}

// void	free_everything(t_pipex *args, int pipe_fd[])
// {
// 	print_struct(args);
// 	(void)pipe_fd;
// 	if (args->path != NULL)
// 		free_2d(args->path);
// 	if (args->full_path != NULL)
// 		free(args->full_path);
// 	free(args->cmd1);
// 	free(args->cmd2);
// 	free(args->cmd1_raw);
// 	free(args->cmd2_raw);
// 	free(args->cmd1_path);
// 	free(args->cmd2_path);
// 	free(args->cmd1_noflag);
// 	free(args->cmd2_noflag);
// 	free(args);
// 	return;
// }