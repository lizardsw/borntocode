/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:48:47 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/24 13:40:44 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

static t_flag	pick_up(t_philo *philo, t_table *table)
{
	long long	now;

	pthread_mutex_lock(&(table->print));
	now = get_time_from(table->sh_start_time);
	if (table->sh_simul == 0 || now == -1)
	{
		pthread_mutex_unlock(&(table->fork[philo->fork[philo->index % 2]]));
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	printf("%lld %d %s\n", now, philo->index + 1, "has taken a fork");
	pthread_mutex_unlock(&(table->print));
	pthread_mutex_lock(&(table->fork[philo->fork[!(philo->index % 2)]]));
	pthread_mutex_lock(&(table->print));
	now = get_time_from(table->sh_start_time);
	if (table->sh_simul == 0 || now == -1)
	{
		pthread_mutex_unlock(&(table->fork[philo->fork[philo->index % 2]]));
		pthread_mutex_unlock(&(table->fork[philo->fork[!(philo->index % 2)]]));
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	printf("%lld %d %s\n", now, philo->index + 1, "has taken a fork");
	pthread_mutex_unlock(&(table->print));
	return (SUCCESS);
}

static t_flag	eating(t_philo *philo, t_table *table, t_info info)
{
	long long	now;

	pthread_mutex_lock(&(table->fork[philo->fork[philo->index % 2]]));
	if (pick_up(philo, table) == FAIL)
		return (FAIL);
	pthread_mutex_lock(&(table->print));
	now = get_time_from(table->sh_start_time);
	if (table->sh_simul == 0 || now == -1)
	{
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	philo->sh_dead_tm = now + (long long)info.starve_tm;
	printf("%lld %d %s\n", now, philo->index + 1, "is eating");
	if (table->sh_total_eat > 0)
		table->sh_total_eat--;
	philo->must_eat--;
	pthread_mutex_unlock(&(table->print));
	my_usleep(info.eat_tm, table->sh_start_time);
	pthread_mutex_unlock(&(table->fork[philo->fork[!(philo->index % 2)]]));
	pthread_mutex_unlock(&(table->fork[philo->fork[(philo->index % 2)]]));
	return (SUCCESS);
}

static t_flag	sleeping(t_philo *philo, t_table *table, t_info info)
{
	long long	now;

	pthread_mutex_lock(&(table->print));
	now = get_time_from(table->sh_start_time);
	if (table->sh_simul == 0 || now == -1)
	{
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	printf("%lld %d %s\n", now, philo->index + 1, "is sleeping");
	pthread_mutex_unlock(&(table->print));
	my_usleep(info.sleep_tm, table->sh_start_time);
	return (SUCCESS);
}

static t_flag	thinking(t_philo *philo, t_table *table, t_info info)
{
	long long	now;

	pthread_mutex_lock(&(table->print));
	if (table->sh_simul == 0)
	{
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	now = get_time_from(table->sh_start_time);
	printf("%lld %d %s\n", now, philo->index + 1, "is thinking");
	pthread_mutex_unlock(&(table->print));
	if (info.eat_tm > info.sleep_tm)
		my_usleep((info.eat_tm - info.sleep_tm), table->sh_start_time);
	if (info.philo_num % 2 == 1)
		usleep(100);
	return (SUCCESS);
}

void	*philo_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->index % 2 == 1)
		usleep(800);
	while (philo->must_eat != 0)
	{
		if (eating(philo, philo->table, philo->table->info) == FAIL)
			return (NULL);
		if (philo->must_eat == 0)
			return (NULL);
		if (sleeping(philo, philo->table, philo->table->info) == FAIL)
			return (NULL);
		if (thinking(philo, philo->table, philo->table->info) == FAIL)
			return (NULL);
	}
	return (NULL);
}
