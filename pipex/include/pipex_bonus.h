/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:29:45 by seongwch          #+#    #+#             */
/*   Updated: 2022/07/06 21:46:09 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../prtf/ft_printf.h"
#include <fcntl.h>

#include <string.h>
#include <sys/wait.h>

#define STDOUT 1
#define STDIN 0
#define PIPIN 0
#define PIPOUT 1

typedef struct s_info
{
	int pipe_fd[2][2];
	pid_t	*pid;
	
}	t_info;


#endif