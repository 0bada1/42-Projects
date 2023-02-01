/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:54:39 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 19:08:17 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <sys/wait.h>
# include <time.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_counter
{
	int	i;
	int	j;
	int	k;
	int	m;
	int	n;
	int	trigger;
}t_counter;

typedef struct s_pipex
{
	char	**envp;
	char	**path;
	char	*cmd1_raw;
	char	*cmd2_raw;
	char	*cmd1;
	char	*cmd2;
	char	*cmd1_noflag;
	char	*cmd2_noflag;
	int		infile_fd;
	int		outfile_fd;
	char	*cmd1_path;
	char	*cmd2_path;
	char	*full_path;
}t_pipex;

/*------------------------------------PIPEX-----------------------------------*/
/*------------------------------------PARSE-----------------------------------*/
t_pipex		*args_pipex(char *argv[], char *envp[]);
t_pipex		*args_pipex_2(t_pipex *args);
t_pipex		*get_path(t_pipex *args, char *envp[]);

/*--------------------------------CHECK_ERRORS--------------------------------*/
int			check_errors(t_pipex *args, int pipe_fd[]);
int			is_abs(t_pipex *args, char *str);
int			check_errors_2(t_pipex *args, int pipe_fd[]);

/*-----------------------------------UTILS1-----------------------------------*/
int			check_access(t_pipex *args, char *command);
int			check_for_abs_path(char *command);
int			ft_strlen_custom(char *command);
char		*store_cmd(char *command);
int			check_for_abs_path2(char *command);

/*-----------------------------------UTILS2-----------------------------------*/
void		print_struct(t_pipex *args);
char		*store_cmd_path(t_pipex *args, char *command);
t_pipex		*fork_dup_execute(t_pipex *args, char *command1,
				char *command2, int pipe_fd[]);
t_pipex		*exec_cmd1(t_pipex *args, char *command1,
				char *command2, int pipe_fd[]);
t_pipex		*exec_cmd2(t_pipex *args, char *command2, int pipe_fd[]);

/*------------------------------------FREE------------------------------------*/
void		free_everything(t_pipex *args);
void		free2(t_pipex *args);
void		free_2d(char **array);
int			close_files(t_pipex *args, int pipe_fd[]);

#endif