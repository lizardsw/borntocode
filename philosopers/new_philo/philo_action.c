/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:48:47 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/22 22:31:05 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

static e_error pick_up(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&(table->fork[philo->fork[philo->index % 2]]));
	pthread_mutex_lock(&(table->print));
	if ()
		return;
	printf("%lld %d %s", get_time(), philo->index, "has taken a fork");
	pthread_mutex_unlock(&(table->print));
	pthread_mutex_lock(&(table->fork[philo->fork[!(philo->index % 2)]]));
	pthread_mutex_lock(&(table->print));
	if ()
		return;
	printf("%lld %d %s", get_time(), philo->index, "has taken a fork");
	pthread_mutex_unlock(&(table->print));
}

static e_error eating(t_philo *philo, t_table *table, t_info info)
{
	long long	now;
	
	if (pick_up(philo, table) == FAIL)
		return (FAIL);
	pthread_mutex_lock(&(table->print));
	if ()
		return;
	now = get_time();
	philo->sh_dead_tm = now + info.starve_tm * 1000;
	philo->must_eat--;
	printf("%lld %d %s", now, philo->index, "is eating");
	pthread_mutex_unlock(&(table->print));
	my_usleep(info.eat_tm * 1000);
	pthread_mutex_unlock(&(table->fork[philo->fork[0]]));
	pthread_mutex_unlock(&(table->fork[philo->fork[1]]));
	return (SUCCESS);
}

static e_error sleeping(t_philo *philo, t_table *table, t_info info)
{
	pthread_mutex_lock(&(table->print));
	if ()
		return;
	printf("%lld %d %s", get_time(), philo->index, "is sleeping");
	pthread_mutex_unlock(&(table->print));
	my_usleep(info.sleep_tm * 1000);
	return (SUCCESS);
}

static e_error sleeping(t_philo *philo, t_table *table, t_info info)
{
	pthread_mutex_lock(&(philo->table->print));
	if ()
		return
	printf("%lld %d %s", get_time(), philo->index, "is thinking");
	pthread_mutex_unlock(&(philo->table->print));
	if (info.eat_tm > info.sleep_tm)
		my_usleep((info.eat_tm - info.sleep_tm) * 1000);
	if (info.philo_num % 2 == 1)
		my_usleep(400);
	return (SUCCESS);
}

void	*philo_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->must_eat != 0)
	{
		if (eating(philo, philo->table, philo->table->info) == FAIL);
			return (NULL);
		if (philo->must_eat == 0)
			return (NULL);
		my_usleep(philo->table->info.sleep_tm * 1000);
		if (sleeping(philo, philo->table, philo->table->info) == FAIL);
			return (NULL);
	}
	return (NULL);
}


