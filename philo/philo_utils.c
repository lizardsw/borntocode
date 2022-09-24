/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:15:14 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/24 15:38:34 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

long long	get_time_from(struct timeval start_time)
{
	struct timeval	now_time;
	long long		ms_time;

	if (gettimeofday(&now_time, NULL) == -1)
		return (-1);
	ms_time = (now_time.tv_sec - start_time.tv_sec) * 1000;
	ms_time += (now_time.tv_usec - start_time.tv_usec) / 1000;
	return (ms_time);
}

void	my_usleep(long long time, struct timeval start_time)
{
	long long	now;
	long long	start;

	start = get_time_from(start_time);
	if (start == -1)
		return ;
	while (1)
	{
		now = get_time_from(start_time);
		if (now - start >= time || now == -1)
			break ;
		usleep(150);
	}
}

void	table_free(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->info.philo_num)
	{
		pthread_mutex_destroy(&(table->fork[i]));
		i++;
	}
	free(table->fork);
	pthread_mutex_destroy(&(table->print));
}
