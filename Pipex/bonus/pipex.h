/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:54:39 by ooutabac          #+#    #+#             */
/*   Updated: 2023/01/24 19:46:38 by ooutabac         ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

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
	char	**cmd;
	char	**cmd_path;
	char	**cmd_noflag;
	char	**cmd_raw;
	int		number_of_commands;
	int		here_doc;
	char	*limiter;
	int		infile_fd;
	int		outfile_fd;
	char	*full_path;
}t_pipex;

/*------------------------------------PIPEX-----------------------------------*/
/*------------------------------------PARSE-----------------------------------*/
t_pipex		*args_pipex(int argc, char *argv[], char *envp[]);
t_pipex		*get_path(t_pipex *args, char *envp[]);
t_pipex		*args_pipex2(int argc, char *argv[]);

/*--------------------------------CHECK_ERRORS--------------------------------*/
int			check_errors2(t_pipex *args, int *pipe_fd[]);
int			check_errors(t_pipex *args, int *pipe_fd[]);
int			is_abs(t_pipex *args, char *str);

/*-----------------------------------UTILS1-----------------------------------*/
int			check_access(t_pipex *args, char *command);
int			check_for_abs_path(char *command);
int			ft_strlen_custom(char *command);
char		*store_cmd(char *command);

/*-----------------------------------UTILS2-----------------------------------*/
t_pipex		*fork_dup_execute(t_pipex *args, int cmd_no, int *pipe_fd[]);
char		*store_cmd_path(t_pipex *args, char *command);

/*-----------------------------------UTILS3-----------------------------------*/
t_pipex		*calloc_pipex(t_pipex *args, int argc, char *argv[]);
t_pipex		*execution_loop(t_pipex *args, int *pipe_fd[]);
int			record_here_doc(int here_doc, char *limiter);
void		print_struct(t_pipex *args);

/*------------------------------------FREE------------------------------------*/
int			close_files(t_pipex *args, int *pipe_fd[]);
void		free_everything(t_pipex *args);
void		free_2d(char **array);
void		free2(t_pipex *args);

#endif