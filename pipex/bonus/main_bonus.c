/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:30:23 by seongwch          #+#    #+#             */
/*   Updated: 2022/07/06 21:54:30 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_error(char *str, int flag)
{
	if (flag == 0)
		exit(1);
	else if (flag == 1)
	{	
		perror(str);
		exit(1);
	}
	else if (flag == 2)
	{
		write(2, "command not found :", 20);
		write(2, str, strlen(str));
		write(2, "\n", 2);
		exit(1);
	}
	else if (flag == 3)
	{
		write(2, str, strlen(str));
		exit(1);
	}
}

void	init_pipe(t_info *info)
{
	if(pipe(info->pipe_fd[0]) == -1)
		ft_error("pipe - error", 1);
	if(pipe(info->pipe_fd[1]) == -1)
		ft_error("pipe - error", 1);
}

int main(int argc, char **argv, char **envp)
{
	t_info	info;
	pid_t	pid;
	int		i;
	int	pipeA[2];
	int pipeB[2];
	char buff[100];
	
	i = 0;
	int k;
	if (1)
	{
		// init_pipe(&info);
		pipe(pipeA);
		pipe(pipeB);
		while (i < 3)
		{
			pid = fork();
			if (pid == -1)
				ft_error("fork - error", 1);
			if (pid == 0)
			{
				dup2(pipeB[PIPIN], STDIN);
				dup2(pipeA[PIPOUT], STDOUT);
				write(STDOUT, "hi", 3);
				return 0;
			}
			else
			{
				dup2(pipA[PIPIN], STDIN);
				wait(NULL);
				k = read(STDIN, buff, 100);
				buff[k + 1] = '\0';
				printf("-------------------\n");
			}
			i++;
		}
	}
	else
		ft_error("argc - error!\n", 3);
	return (0);
}