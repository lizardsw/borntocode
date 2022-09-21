/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:58:51 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/21 22:31:58 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

static int	pick_fork(t_philo *philo, t_info *info)
{
	if (philo->ph_index % 2 == 0)
	{
		pthread_mutex_lock(&(info->fork[philo->left_fork]));
		if(philo_printf(info, philo->ph_index, "has taken a fork", 0) == FAIL)
			return (FAIL);
		pthread_mutex_lock(&(info->fork[philo->right_fork]));
		if(philo_printf(info, philo->ph_index, "has taken a fork", 0) == FAIL)
			return (FAIL);
	}
	else
	{
		pthread_mutex_lock(&(info->fork[philo->right_fork]));
		if(philo_printf(info, philo->ph_index, "has taken a fork", 0) == FAIL)
			return (FAIL);
		pthread_mutex_lock(&(info->fork[philo->left_fork]));
		if(philo_printf(info, philo->ph_index, "has taken a fork", 0) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

static void	unpick_fork(t_philo *philo, t_info *info)
{
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

static int	philo_eating(t_philo *philo, t_info *info)
{
	long long now;
	
	if (pick_fork(philo, info) == FAIL)
		return (FAIL);
	pthread_mutex_lock(&(philo->die));
	now = get_time();
	if (now - philo->deadline >= 0)
	{
		pthread_mutex_unlock(&(philo->die));
		return (FAIL);
	}
	philo->deadline = get_time() + info->starve_time * 1000;
	if (philo->must_eat > 0)
		philo->must_eat--;
	pthread_mutex_unlock(&(philo->die));
	if (philo_printf(info, philo->ph_index, "is eating", 1) == FAIL)
		return (FAIL);
	my_usleep(info, info->eating_time * 1000);
	unpick_fork(philo, info);
	return (SUCCESS);
}

void	*philo_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->must_eat > 0 || philo->must_eat == -1)
	{
		if(philo_eating(philo, philo->info) == FAIL)
			break;
		if (philo_printf(philo->info, philo->ph_index, "is sleeping", 0) == FAIL)
			break;
		my_usleep(philo->info, philo->info->sleeping_time * 1000);
		if (philo_printf(philo->info, philo->ph_index, "is thinking", 0) == FAIL)
			break;
		if (philo->info->philo_num % 2 == 1)
			my_usleep(philo->info, 400);
	}
	return (NULL);
}
