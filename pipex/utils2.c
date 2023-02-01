/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:12:36 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 15:13:57 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*store_cmd_path(t_pipex *args, char *command)
{
	t_counter	count;
	char		*command_path;
	char		*joined;
	char		*full_command;

	if (!args || !command)
		return (command);
	command_path = NULL;
	joined = NULL;
	count.i = 0;
	while (args->path[count.i] != NULL)
	{
		full_command = ft_strjoin("/", command);
		joined = ft_strjoin(args->path[count.i++], full_command);
		if (access(joined, X_OK | 0) == 0)
		{
			command_path = ft_strjoin(args->path[count.i - 1], full_command);
			free(joined);
			free(full_command);
			break ;
		}
		free(full_command);
		free(joined);
	}
	return (command_path);
}

/*
1)Fork
2)Take input from infile to command1
3)Execute and store output in pipe() file
4)Take input from pipe() file to command2
5)Execute and store output in outfile
*/
t_pipex	*fork_dup_execute(t_pipex *args, char *command1,
		char *command2, int pipe_fd[])
{
	command1 = ft_strtrim(command1, "/");
	command2 = ft_strtrim(command2, "/");
	exec_cmd1(args, command1, command2, pipe_fd);
	exec_cmd2(args, command2, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(args->infile_fd);
	close(args->outfile_fd);
	waitpid(-1, NULL, WUNTRACED);
	waitpid(-1, NULL, WUNTRACED);
	return (args);
}

t_pipex	*exec_cmd1(t_pipex *args, char *command1, char *command2, int pipe_fd[])
{
	int		fork_id;
	char	**flags;

	fork_id = fork();
	if (fork_id == 0)
	{
		flags = ft_split(command1, ' ');
		dup2(pipe_fd[1], STDOUT_FILENO);
		dup2(args->infile_fd, STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(args->infile_fd);
		close(args->outfile_fd);
		execve(args->cmd1_path, flags, NULL);
		perror("execve");
		free_2d(flags);
		free_everything(args);
		free(command1);
		free(command2);
		exit(1);
	}
	free(command1);
	return (args);
}

t_pipex	*exec_cmd2(t_pipex *args, char *command2, int pipe_fd[])
{
	int		fork_id;
	char	**flags;

	fork_id = fork();
	if (fork_id == 0)
	{
		flags = ft_split(command2, ' ');
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(args->outfile_fd, STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(args->infile_fd);
		close(args->outfile_fd);
		execve(args->cmd2_path, flags, NULL);
		perror("execve");
		free_2d(flags);
		free_everything(args);
		free(command2);
		exit(1);
	}
	free(command2);
	return (args);
}

void	print_struct(t_pipex *args)
{
	ft_printf("\nPRINTING COMMANDS:\n");
	ft_printf("%s\n", args->cmd1);
	ft_printf("%s\n", args->cmd2);
	ft_printf("\nPRINTING COMMANDS WITH NO FLAGS:\n");
	ft_printf("%s\n", args->cmd1_noflag);
	ft_printf("%s\n", args->cmd2_noflag);
	ft_printf("\nPRINTING COMMANDS PATH:\n");
	ft_printf("%s\n", args->cmd1_path);
	ft_printf("%s\n", args->cmd2_path);
	ft_printf("\nPRINTING RAW COMMANDS WITH NO FLAGS\n");
	ft_printf("%s\n", args->cmd1_raw);
	ft_printf("%s\n", args->cmd2_raw);
}
