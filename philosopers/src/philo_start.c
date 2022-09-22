/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:13 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/22 12:25:20 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

static void	deadline_init(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	info->start_time = get_time();
	while (i < info->philo_num)
	{
		pthread_mutex_lock(&(philo[i].die));
		philo[i].deadline = info->start_time + info->starve_time * 1000;
		pthread_mutex_unlock(&(philo[i].die));
		i++;
	}
}

int	sit_philo_table(t_philo *philo, t_info *info)
{
	int	i;
	int	j;

	pthread_mutex_lock(&(info->print));
	info->simul = 1;
	i = 0;
	j = 0;
	while (j < 2)
	{
		i += j;
		while (i < info->philo_num)
		{
			if (pthread_create(&(philo[i].thread), NULL, philo_action, \
					(void *)&philo[i]))
				return (THREAD_CREATE_ERROR);
			usleep(10);
			i += 2;
		}
		my_usleep(800);
		i = 0;
		j++;
	}
	deadline_init(philo, info);
	pthread_mutex_unlock(&(info->print));
	return (NO_ERROR);
}
