/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:30:23 by seongwch          #+#    #+#             */
/*   Updated: 2022/07/06 21:31:33 by seongwch         ###   ########.fr       */
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
	
	i = 0;
	if (1)
	{
		// init_pipe(&info);
		while (i < 3)
		{
			pid = fork();
			if (pid == -1)
				ft_error("fork - error", 1);
			if (pid == 0)
			{
				if (i != 0)
				return 0;
			}
			else
			{
				printf("부모 프로세스 pid : %d\n", pid);
				printf("부모!\n");
				waitpid(pid, NULL, WUNTRACED);
				printf("-------------------\n");
			}
			i++;
		}
	}
	else
		ft_error("argc - error!\n", 3);
	return (0);
}