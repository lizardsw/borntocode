/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:13 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/21 19:18:37 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

static void	pick_fork(t_philo *philo, t_info *info)
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

static void	philo_eating(t_philo *philo, t_info *info)
{
	pick_fork(philo, info);
	philo_printf(info, philo->ph_index, "is eating");
	pthread_mutex_lock(&(philo->die));
	philo->deadline = get_time() + info->starve_time * 1000;
	pthread_mutex_unlock(&(philo->die));
	my_usleep(info, info->eating_time * 1000);
	unpick_fork(philo, info);
}

void	*philo_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		philo_eating(philo, philo->info);
		philo_printf(philo->info, philo->ph_index, "is sleeping");
		my_usleep(philo->info, philo->info->sleeping_time * 1000);
		philo_printf(philo->info, philo->ph_index, "is thinking");
		if (philo->info->philo_num % 2 == 1)
			my_usleep(philo->info, 2500);
	}
	return (NULL);
}

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
			if (pthread_create(&(philo[i].thread), NULL, philo_action, (void *)&philo[i]))
				return (THREAD_CREATE_ERROR);
			usleep(10);
			i += 2;
		}
		my_usleep(info, 800);
		i = 0;
		j++;
	}
	deadline_init(philo, info);
	printf("start!\n");
	pthread_mutex_unlock(&(info->print));
	return (NO_ERROR);
}