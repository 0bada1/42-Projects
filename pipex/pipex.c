/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 04:02:23 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 17:08:59 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*args;
	int		pipe_fd[2];
	int		check_error_exit;

	if (argc == 5)
	{
		pipe(pipe_fd);
		args = args_pipex(argv, envp);
		check_error_exit = check_errors(args, pipe_fd);
		if (check_error_exit < 0)
		{
			if (check_error_exit == -2)
			{
				free_everything(args);
				return (0);
			}
		}
		fork_dup_execute(args, args->cmd1, args->cmd2, pipe_fd);
		close_files(args, pipe_fd);
		free_everything(args);
	}
	else
		ft_printf("Usage: Infile cmd1 cmd2 Outfile\n");
	return (0);
}

t_pipex	*args_pipex(char *argv[], char *envp[])
{
	t_pipex		*args;

	args = ft_calloc(1, sizeof(t_pipex));
	if (!ft_strchr(argv[2], '/'))
		args->cmd1 = ft_strjoin("/", argv[2]);
	else
		args->cmd1 = ft_strdup(argv[2]);
	if (!ft_strchr(argv[3], '/'))
		args->cmd2 = ft_strjoin("/", argv[3]);
	else
		args->cmd2 = ft_strdup(argv[3]);
	args = get_path(args, envp);
	args->cmd1_raw = store_cmd(argv[2]);
	args->cmd2_raw = store_cmd(argv[3]);
	args->cmd1_noflag = store_cmd(args->cmd1);
	args->cmd2_noflag = store_cmd(args->cmd2);
	args->infile_fd = open(argv[1], O_RDONLY, X_OK, 0777);
	args->outfile_fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	args->envp = envp;
	return (args_pipex_2(args));
}

t_pipex	*args_pipex_2(t_pipex *args)
{
	if (args->full_path != NULL && args->path != NULL)
	{
		if (check_for_abs_path(args->cmd1_noflag) == 0)
			args->cmd1_path = ft_strdup(args->cmd1_noflag);
		else
			args->cmd1_path = store_cmd_path(args, args->cmd1_noflag);
		if (check_for_abs_path(args->cmd2_noflag) == 0)
			args->cmd2_path = ft_strdup(args->cmd2_noflag);
		else
			args->cmd2_path = store_cmd_path(args, args->cmd2_noflag);
	}
	else
	{
		args->cmd1_path = args->cmd1_noflag;
		args->cmd2_path = args->cmd2_noflag;
	}
	return (args);
}

t_pipex	*get_path(t_pipex *args, char *envp[])
{
	t_counter	count;

	count.i = 0;
	while (envp[count.i] != NULL)
	{
		if (ft_strnstr(envp[count.i++], "PATH=", 5))
		{
			args->full_path = ft_strdup(envp[count.i - 1]);
			args->path = ft_split(args->full_path + 5, ':');
			break ;
		}
	}
	return (args);
}
