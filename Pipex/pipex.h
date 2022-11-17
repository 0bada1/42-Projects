/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:54:39 by ooutabac          #+#    #+#             */
/*   Updated: 2022/11/14 11:51:42 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <limits.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct s_counter
{
	int	i;
	int	j;
	int	k;
}
t_counter;

typedef struct s_pipex
{
	char	*envp;
	char	*file1;
	char	*file2;
}
t_pipex

/*--------------------------------CHECK_ERRORS---------------------------------*/
int			check_errors(int argc, char *argv[], char *envp[]);

/*-----------------------------------UTILS1------------------------------------*/


/*-----------------------------------UTILS2------------------------------------*/


/*-----------------------------------UTILS3------------------------------------*/


/*-----------------------------------UTILS4------------------------------------*/

