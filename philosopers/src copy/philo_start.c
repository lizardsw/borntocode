/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:13 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/20 15:37:37 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

int	philo_thinking(t_philo *philo, t_info *info)
{
	if (philo->ph_index % 2 == 0)
	{
		pthread_mutex_lock(&(info->fork[philo->left_fork]));
		philo_printf(philo, info, FORK);
		pthread_mutex_lock(&(info->fork[philo->right_fork]));
		philo_printf(philo, info, FORK);
	}
	else
	{
		pthread_mutex_lock(&(info->fork[philo->right_fork]));
		philo_printf(philo, info, FORK);
		pthread_mutex_lock(&(info->fork[philo->left_fork]));
		philo_printf(philo, info, FORK);
	}
	return (SUCCESS);
}

int	philo_eating(t_philo *philo, t_info *info)
{
	long long time;

	time = philo_printf(philo, info, EAT);
	if (time == -1)
		return (FAIL);
	pthread_mutex_lock(&(philo->die));
	philo->deadline = time + info->starve_time * 1000;
	philo->must_eat--;
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
	return (SUCCESS);
}

int	philo_sleeping(t_philo *philo, t_info *info)
{
	philo_printf(philo, info, SLEEP);
	my_usleep(info, info->sleeping_time * 1000);
	philo_printf(philo, info, THINK);
	my_usleep(info, 300);
	return (SUCCESS);
}

void	*philo_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	// printf("---philo %d---\n", philo->ph_index);
	while (1)
	{
		if (philo_thinking(philo, philo->info) == FAIL)
			return (NULL);
		if (philo_eating(philo, philo->info) == FAIL)
			return (NULL);
		if (philo_sleeping(philo, philo->info) == FAIL)
			return (NULL);
	}
	return (NULL);
}

int	sit_philo_table(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(info->print));
	while (i < info->philo_num)
	{
		if (pthread_create(&(philo[i].thread), NULL, philo_action, (void *)&philo[i]))
			return (THREAD_CREATE_ERROR);
		if(pthread_detach((philo[i].thread)))
			return (THREAD_JOIN_ERROR);
		i += 2;
	}
	usleep(500);
	i = 1;
	while (i < info->philo_num)
	{
		if (pthread_create(&(philo[i].thread), NULL, philo_action, (void *)&philo[i]))
			return (THREAD_CREATE_ERROR);
		if(pthread_detach((philo[i].thread)))
			return (THREAD_JOIN_ERROR);
		i += 2;
	}
	usleep(500);
	i = 0;
	info->start_time = get_time();
	info->simul = 1;
	while (i < info->philo_num)
	{
		philo[i].deadline = info->start_time + info->starve_time * 1000;
		i++;
	}
	pthread_mutex_unlock(&(info->print));
	return (NO_ERROR);
}