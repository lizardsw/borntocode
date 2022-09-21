/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:13 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/20 23:55:21 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

static void	philo_eating(t_philo *philo, t_info *info)
{
	if (philo->ph_index % 2 == 0)
	{
		pthread_mutex_lock(&(info->fork[philo->left_fork]));
		philo_printf(info, philo->ph_index, "has taken a fork");
		pthread_mutex_lock(&(info->fork[philo->right_fork]));
		philo_printf(info, philo->ph_index, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(info->fork[philo->right_fork]));
		philo_printf(info, philo->ph_index, "has taken a fork");
		pthread_mutex_lock(&(info->fork[philo->left_fork]));
		philo_printf(info, philo->ph_index, "has taken a fork");
	}
	philo_printf(info, philo->ph_index, "is eating");
	pthread_mutex_lock(&(philo->die));
	philo->deadline = get_time() + info->starve_time * 1000;
	pthread_mutex_unlock(&(philo->die));
	my_usleep(info, info->eating_time * 1000);
	if (philo->ph_index % 2 == 0)
	{
		pthread_mutex_unlock(&(info->fork[philo->left_fork]));
		pthread_mutex_unlock(&(info->fork[philo->right_fork]));
	}
	else
	{
		pthread_mutex_unlock(&(info->fork[philo->right_fork]));
		pthread_mutex_unlock(&(info->fork[philo->left_fork]));
	}
}

void	*philo_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		philo_eating(philo, philo->info);
		if (philo_printf(philo->info, philo->ph_index, "is sleeping") == FAIL)
			break;
		my_usleep(philo->info, philo->info->sleeping_time * 1000);
		if (philo_printf(philo->info, philo->ph_index, "is thinking") == FAIL)
			break;
		my_usleep(philo->info, philo->info->philo_num);
	}
	return (NULL);
}

int	sit_philo_table(t_philo *philo, t_info *info)
{
	int	i;
	long long last_time;

	pthread_mutex_lock(&(info->print));
	info->simul = 1;
	i = 0;
	while (i < info->philo_num)
	{
		if (pthread_create(&(philo[i].thread), NULL, philo_action, (void *)&philo[i]))
			return (THREAD_CREATE_ERROR);
		usleep(10);
		i += 2;
	}
	my_usleep(info, 100);
	i = 1;
	while (i < info->philo_num)
	{
		if (pthread_create(&(philo[i].thread), NULL, philo_action, (void *)&philo[i]))
			return (THREAD_CREATE_ERROR);
		usleep(10);
		i += 2;
	}
	my_usleep(info, 100);
	i = 0;
	info->start_time = get_time();
	while (i < info->philo_num)
	{
		pthread_mutex_lock(&(philo[i].die));
		philo[i].deadline = info->start_time + info->starve_time * 1000;
		pthread_mutex_unlock(&(philo[i].die));
		i++;
	}
	pthread_mutex_unlock(&(info->print));
	return (NO_ERROR);
}