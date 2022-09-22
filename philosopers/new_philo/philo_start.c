/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:42:49 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/22 21:48:31 by seongwch         ###   ########.fr       */
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
		philo[i].sh_dead_tm = info->start_time + info->starve_tm * 1000;
		i++;
	}
}

e_error	sit_philo_table(t_philo *philo, t_table *table, t_info info)
{
	int	i;
	int	j;

	pthread_mutex_lock(&(table->print));
	table->sh_simul = 1; // share_data
	i = 0;
	j = 0;
	while (j < 2)
	{
		i += j;
		while (i < info.philo_num)
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
	deadline_init(philo, &(table->info));
	pthread_mutex_unlock(&(table->print));
	return (NO_ERROR);





	
}