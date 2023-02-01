/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 04:09:10 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 14:44:50 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* CHECK FOR ERRORS
- Check if path of cmd1 and cmd2 exists.
- Check that cmd1 and cmd2 are not files
*/
int	check_errors(t_pipex *args, int pipe_fd[])
{
	if (args == NULL)
		return (-1);
	if (check_access(args, args->cmd1_path) < 0
		|| is_abs(args, args->cmd1_raw) != 0)
	{
		free(args->cmd1_path);
		args->cmd1_path = ft_strdup(args->cmd1_raw);
		if (check_access(args, args->cmd1_path) < 0)
			ft_printf("Pipex: %s: No such file or directory\n", args->cmd1_raw);
	}
	if (check_access(args, args->cmd2_path) < 0
		|| is_abs(args, args->cmd2_raw) != 0)
	{
		free(args->cmd2_path);
		args->cmd2_path = ft_strdup(args->cmd2_raw);
		if (check_access(args, args->cmd2_path) < 0)
			ft_printf("Pipex: %s: No such file or directory\n", args->cmd2_raw);
	}
	return (check_errors_2(args, pipe_fd));
}

int	check_errors_2(t_pipex *args, int pipe_fd[])
{
	if (args->infile_fd < 0 || args->outfile_fd < 0
		|| !pipe_fd[0] || !pipe_fd[1])
	{
		ft_printf("Error: File could not be opened\n");
		return (-2);
	}
	if (!args->full_path || !args->path)
	{
		ft_printf("No path was found\n");
		return (-3);
	}
	return (0);
}
// ft_printf("%d\n", check_access(args, args->cmd1_noflag));
// ft_printf("%d\n", check_access(args, args->cmd2_noflag));

int	is_abs(t_pipex *args, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	if (str[0] == '/' && check_access(args, str) == 0)
		return (2);
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
