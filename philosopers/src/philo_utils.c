/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:15:14 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/22 12:32:00 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		micro_time;

	gettimeofday(&time, NULL);
	micro_time = time.tv_sec * 1000000 + time.tv_usec;
	return (micro_time);
}

int	philo_printf(t_info *info, int index, char *str, int flag)
{
	long long	now_time;

	if (flag == 1 && info->total_must_eat != -1)
		info->total_must_eat--;
	pthread_mutex_lock(&(info->print));
	now_time = (get_time() - info->start_time) / 1000;
	if (info->simul == 1)
	{
		printf("%lld %d %s\n", now_time, index + 1, str);
		if (info->total_must_eat == 0)
			info->simul = 0;
		pthread_mutex_unlock(&(info->print));
		return (SUCCESS);
	}
	else
	{
		pthread_mutex_unlock(&(info->print));
		return (FAIL);
	}
}

void	my_usleep(long long time)
{
	long long	now;
	long long	start;

	start = get_time();
	while (1)
	{
		now = get_time();
		if (now - start > time)
			break ;
		usleep(150);
	}
}
