/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:12:36 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 19:30:32 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_joined_str(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

char	*store_cmd_path(t_pipex *args, char *command)
{
	t_counter	count;
	char		*command_path;
	char		*joined;
	char		*joined2;

	if (!args || !command)
		return (NULL);
	command_path = NULL;
	joined = NULL;
	joined2 = NULL;
	count.i = 0;
	while (args->path[count.i] != NULL)
	{
		joined2 = ft_strjoin("/", command);
		joined = ft_strjoin(args->path[count.i++], joined2);
		if (access(joined, F_OK | X_OK) == 0)
		{
			command_path = ft_strjoin(args->path[count.i - 1], command);
			free_joined_str(joined, joined2);
			break ;
		}
		free_joined_str(joined, joined2);
	}
	return (command_path);
}

static t_pipex	*child_process(t_pipex *args, int cmd_no, int *pipe_fd[])
{
	if (cmd_no == 0 && args->number_of_commands > 1)
	{
		if (args->limiter != NULL)
		{
			close(args->here_doc);
			args->here_doc = open("here_doc", O_RDONLY, 0777);
			dup2(args->here_doc, STDIN_FILENO);
		}
		else
			dup2(args->infile_fd, STDIN_FILENO);
		dup2(pipe_fd[0][1], STDOUT_FILENO);
	}
	else if (cmd_no == args->number_of_commands - 1)
	{
		dup2(pipe_fd[cmd_no - 1][0], STDIN_FILENO);
		dup2(args->outfile_fd, STDOUT_FILENO);
	}
	else if (cmd_no < args->number_of_commands - 1)
	{
		dup2(pipe_fd[cmd_no - 1][0], STDIN_FILENO);
		dup2(pipe_fd[cmd_no][1], STDOUT_FILENO);
	}
	return (args);
}

/*
1)Fork
2)Take input from infile to command1
3)Execute and store output in pipe() file
4)Take input from pipe() file to command2
5)Execute and store output in outfile
*/
t_pipex	*fork_dup_execute(t_pipex *args, int cmd_no, int *pipe_fd[])
{
	int		fork_id;
	char	**flags;
	char	*command;

	command = ft_strtrim(args->cmd[cmd_no], "/");
	fork_id = fork();
	if (fork_id == 0)
	{
		child_process(args, cmd_no, pipe_fd);
		flags = ft_split(command, ' ');
		free(command);
		close_files(args, pipe_fd);
		execve(args->cmd_path[cmd_no], flags, args->envp);
		perror("Pipex: Execve failed\n");
		free_2d(flags);
		free_everything(args);
		exit(1);
	}
	free(command);
	return (args);
}
	// ft_printf("if1 cmd_no = %i\n", cmd_no);
	// ft_printf("if3 cmd_no = %i\n", cmd_no);
	// ft_printf("if2 cmd_no = %i\n", cmd_no);
