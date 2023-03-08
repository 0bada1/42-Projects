/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 04:09:10 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 20:42:25 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* CHECK FOR ERRORS
- Check if path of cmd1 and cmd2 exists.
- Check that cmd1 and cmd2 are not files
*/
int	check_errors(t_pipex *args, int *pipe_fd[])
{
	t_counter	count;

	count.i = 0;
	if (args == NULL)
		return (-1);
	while (count.i < args->number_of_commands)
	{
		if (check_access(args, args->cmd_path[count.i]) < 0
			|| is_abs(args, args->cmd_raw[count.i]) != 0)
		{
			args->cmd_path[count.i] = ft_strdup(args->cmd_raw[count.i]);
			if (check_access(args, args->cmd_path[count.i]) < 0)
				ft_printf("Pipex: %s: No such file or directory\n",
					args->cmd_raw[count.i]);
		}
		count.i++;
	}
	return (check_errors2(args, pipe_fd));
}
// ft_printf("%d\n", check_access(args, args->cmd1_noflag));
// ft_printf("%d\n", check_access(args, args->cmd2_noflag));

int	check_errors2(t_pipex *args, int *pipe_fd[])
{
	t_counter	count;

	count.i = 0;
	while (count.i < args->number_of_commands - 1)
	{
		if (!pipe_fd[count.i])
		{
			ft_printf("Error: File could not be opened\n");
			return (-2);
		}
		count.i++;
	}
	if (args->infile_fd < 0 || args->outfile_fd < 0)
	{
		ft_printf("Error: File could not be opened\n");
		return (-3);
	}
	if (!args->full_path || !args->path)
	{
		ft_printf("No path was found\n");
		return (-4);
	}
	return (0);
}

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
