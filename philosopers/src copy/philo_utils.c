/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:15:14 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/20 16:08:47 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

long long get_time(void)
{
	struct timeval	time;
	long long		micro_time;

	gettimeofday(&time, NULL);
	micro_time = time.tv_sec * 1000000 + time.tv_usec;
	return (micro_time);
}

static void	action_pf(long long time, int philo, char *str)
{
	printf("%lld %d %s\n", time / 1000, philo, str);
}

long long	philo_printf(t_philo *philo, t_info *info, int flag)
{
	long long	time_diff;

	time_diff = get_time() - info->start_time;
	pthread_mutex_lock(&(info->print));
	if (info->simul == 1)
	{
		if (flag == FORK)
			action_pf(time_diff, philo->ph_index, "has taken a fork");
		else if (flag == EAT)
			action_pf(time_diff, philo->ph_index, "is eating");
		else if (flag == SLEEP)
			action_pf(time_diff, philo->ph_index, "is sleeping");
		else if (flag == THINK)
			action_pf(time_diff, philo->ph_index, "is thinking");
		else if (flag == DEAD)
		{
			action_pf(time_diff, philo->ph_index, "died");
			info->simul = 0;
			time_diff = -1;
		}
		pthread_mutex_unlock(&(info->print));
		return (time_diff + info->start_time);
	}
	pthread_mutex_unlock(&(info->print));
	return (-1);
}

void	my_usleep(t_info *info, long long time)
{
	int	i;
	long long	now;
	long long	start;

	i = 0;
	start = get_time();
	while (1)
	{
		now = get_time();
		if (now - start > time)
			break;
		usleep(10);
	}
}
