/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 04:02:19 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 19:16:14 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Checks if the command exists or not in the path
// by joining it with the paths stored then using access function
int	check_access(t_pipex *args, char *command)
{
	t_counter	count;
	char		*temp;

	if (!args->path || !args->full_path || !command)
		return (-1);
	count.trigger = -1;
	count.i = 0;
	if (check_for_abs_path(command) == 0)
	{
		if (access(command, F_OK | X_OK) == 0)
			count.trigger = 0;
		return (count.trigger);
	}
	while (args->path[count.i] != NULL && count.trigger == -1)
	{
		temp = ft_strjoin(args->path[count.i++], command);
		if (access(temp, F_OK | X_OK) == 0)
			count.trigger = 0;
		free(temp);
	}
	return (count.trigger);
}

// Checks if a command is an absolute path
// or not by checking for a '/' in the command
int	check_for_abs_path(char *command)
{
	t_counter	count;

	count.i = 0;
	count.trigger = -1;
	while (command[count.i] != '\0' && count.trigger == -1)
		if (command[count.i++] == '/')
			count.trigger = 0;
	return (count.trigger);
}

char	*store_cmd(char *command)
{
	t_counter	count;
	char		*cmd_noflag;

	count.i = 0;
	cmd_noflag = malloc(sizeof(char) * ft_strlen_custom(command) + 1);
	while (command[count.i] && command[count.i] != ' ')
	{
		cmd_noflag[count.i] = command[count.i];
		count.i++;
	}
	cmd_noflag[count.i] = '\0';
	return (cmd_noflag);
}

int	ft_strlen_custom(char *command)
{
	t_counter	count;

	count.i = 0;
	while (command[count.i] != '\0' && command[count.i] != ' ')
		count.i++;
	return (count.i);
}
