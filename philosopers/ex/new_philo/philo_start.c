/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:42:49 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/23 18:38:43 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

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
			philo[i].sh_dead_tm = table->info.starve_tm * 1000;
			if (pthread_create(&(philo[i].thread), NULL, philo_action, \
					(void *)&philo[i]))
				return (THREAD_CREATE_ERROR);
			usleep(10);
			i += 2;
		}
		usleep(100);
		i = 0;
		j++;
	}
	table->sh_start_time = start_time();
	pthread_mutex_unlock(&(table->print));
	return (NO_ERROR);
}