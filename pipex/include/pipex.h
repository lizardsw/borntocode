/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:19:37 by seongwch          #+#    #+#             */
/*   Updated: 2022/07/07 10:28:14 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../prtf/ft_printf.h"
# include <fcntl.h>

# define STDIN 0
# define STDOUT 1

void	ft_error(char	*str, int flag);

void	ft_free(char **str);
char	*get_path(char *cmd, char **envp);
char	*join_path(char *cmd, char **path);
char	**get_option(char *cmd);
char	**split_path(char **envp);

void	child_setting(int *pipe_fd, int fd);
void	parent_setting(int *pipe_fd, int fd);
void	parent_process(int *pipe_fd, int argc, char **argv, char **envp);
void	child_process(int *pipe_fd, char **argv, char **envp);

#endif