/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:15:14 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/22 21:46:11 by seongwch         ###   ########.fr       */
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
		usleep(200);
	}
}
