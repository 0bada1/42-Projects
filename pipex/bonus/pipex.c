/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 04:02:23 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 20:48:29 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_errors3(t_pipex *args, int *pipe_fd[])
{
	int	check_error_exit;

	check_error_exit = check_errors(args, pipe_fd);
	if (check_error_exit < 0)
	{
		if (check_error_exit == -2 || check_error_exit == -3)
		{
			free_everything(args);
			close_files(args, pipe_fd);
			return (-3);
		}
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*args;
	int		i;
	int		**pipe_fd;

	if (argc >= 4)
	{
		args = args_pipex(argc, argv, envp);
		i = 0;
		pipe_fd = malloc(sizeof(int *) * (args->number_of_commands - 1));
		while (i < args->number_of_commands - 1)
		{
			pipe_fd[i] = ft_calloc(sizeof(int), 2);
			pipe(pipe_fd[i]);
			i++;
		}
		if (check_errors3(args, pipe_fd) <= -2)
			return (0);
		execution_loop(args, pipe_fd);
	}
	else
		ft_printf("Usage: ./pipex Infile cmd1 cmd2 cmd3 ... cmdn Outfile\n");
	return (0);
}

t_pipex	*args_pipex(int argc, char *argv[], char *envp[])
{
	t_counter	count;
	t_pipex		*args;

	args = args_pipex2(argc, argv);
	args = get_path(args, envp);
	count.i = 0;
	if (args->full_path != NULL && args->path != NULL)
	{
		while (count.i < args->number_of_commands
			&& args->cmd_noflag[count.i] != NULL)
		{
			args->cmd_path[count.i] = store_cmd_path(args,
					args->cmd_noflag[count.i]);
			count.i++;
		}
	}
	else
	{
		while (args->cmd[count.i] != NULL)
		{
			args->cmd_path[count.i] = args->cmd_noflag[count.i];
			count.i++;
		}
	}
	return (args);
}

t_pipex	*args_pipex2(int argc, char *argv[])
{
	t_pipex		*args;
	t_counter	count;

	args = ft_calloc(1, sizeof(t_pipex));
	count.i = 0;
	count.j = 2;
	args->number_of_commands = argc - 3;
	if (ft_strncmp(argv[1], "here_doc", 10) == 0)
	{
		args->here_doc = open(argv[1], O_CREAT | O_RDWR | O_APPEND, 0777);
		args->limiter = ft_strdup(argv[2]);
		args->number_of_commands = argc - 4;
		count.j = 3;
		record_here_doc(args->here_doc, args->limiter);
	}
	args = calloc_pipex(args, argc, argv);
	while (count.i < args->number_of_commands)
	{
		args->cmd[count.i] = ft_strjoin("/", argv[count.j]);
		args->cmd_noflag[count.i] = store_cmd(args->cmd[count.i]);
		args->cmd_raw[count.i++] = store_cmd(argv[count.j++]);
	}
	return (args);
}

t_pipex	*get_path(t_pipex *args, char *envp[])
{
	int	i;

	i = 0;
	args->envp = envp;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i++], "PATH=", 5))
		{
			args->full_path = ft_strdup(envp[i - 1]);
			args->path = ft_split(args->full_path + 5, ':');
			break ;
		}
	}
	return (args);
}
